/***************************************************************************
 *   Copyright (C) 2004 - 2009 by Matthias Reif, Holger Gerth              *
 *   matthias.reif@informatik.tu-chemnitz.de                               *
 *   holger.gerth@informatik.tu-chemnitz.de                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see http://www.gnu.org/licenses/     *
 ***************************************************************************/

#include "downloadmodule.h"
#include "juicer.h"

DownloadModule::DownloadModule(Juicer* juicer, QWidget* tabWidget)
  : ModuleBase(juicer, juicer->downloadsTreeWidget, juicer->downloadToolBar, tabWidget)
{
    userStatusDescr["1"] = QObject::tr("unasked");
    userStatusDescr["2"] = QObject::tr("try to connect");
    userStatusDescr["3"] = QObject::tr("partner have to old vers.");
    userStatusDescr["4"] = QObject::tr("partner can't    open file");
    userStatusDescr["5"] = QObject::tr("queueing");
    userStatusDescr["6"] = QObject::tr("no usable parts");
    userStatusDescr["7"] = QObject::tr("loading");
    userStatusDescr["8"] = QObject::tr("not enough disk space");
    userStatusDescr["9"] = QObject::tr("finished");
    userStatusDescr["11"] = QObject::tr("no connection possible");
    userStatusDescr["12"] = QObject::tr("try indirect");
    userStatusDescr["13"] = QObject::tr("paused");
    userStatusDescr["14"] = QObject::tr("queue full");
    userStatusDescr["15"] = QObject::tr("own limit reached");
    userStatusDescr["16"] = QObject::tr("indirect conn. rejected");
    downloadStatusDescr["-1"] = QObject::tr("loading");
    downloadStatusDescr["0"] = QObject::tr("searching");
    downloadStatusDescr["1"] = QObject::tr("error at creating");
    downloadStatusDescr["12"] = QObject::tr("finishing");
    downloadStatusDescr["13"] = QObject::tr("error at finishing");
    downloadStatusDescr["14"] = QObject::tr("finished");
    downloadStatusDescr["15"] = QObject::tr("canceling");
    downloadStatusDescr["16"] = QObject::tr("creating .dat");
    downloadStatusDescr["17"] = QObject::tr("canceled");
    downloadStatusDescr["18"] = QObject::tr("paused");

    currIdRoundRobin = -1;

    powerCheck = new QCheckBox(tr("Power Download:"), juicer->downloadToolBar);
    powerCheck->setChecked(false);
    juicer->downloadToolBar->addWidget(powerCheck);

    powerSpin = new QDoubleSpinBox(juicer->downloadToolBar);
    powerSpin->setRange(2.2, 50.0);
    powerSpin->setSingleStep(0.1);
    powerSpin->setDecimals(1);
    juicer->downloadToolBar->addWidget(powerSpin);

    QPushButton *powerButton = new QPushButton(tr("SET") , juicer->downloadToolBar);
    powerButtonAction = juicer->downloadToolBar->addWidget(powerButton);
    partListTimer = new QTimer(this);
    connect(partListTimer, SIGNAL(timeout()), this, SLOT(partListSlot()));

    connect(treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
    connect(powerCheck, SIGNAL(clicked(bool)), this, SLOT(applyPowerDownload()));
    connect(powerSpin,  SIGNAL(valueChanged(double)), this, SLOT(applyPowerDownload()));
    connect(powerButton, SIGNAL(clicked()), this, SLOT(setMultiPowerDownload()));
    connect(juicer->actionPause, SIGNAL(triggered()), this, SLOT(pauseSlot()));
    connect(juicer->actionResume, SIGNAL(triggered()), this, SLOT(resumeSlot()));
    connect(juicer->actionCancel, SIGNAL(triggered()), this, SLOT(cancelSlot()));
    connect(juicer->actionShow_Part_List, SIGNAL(triggered()), this, SLOT(partListWidgetSlot()));
    connect(juicer->actionShow_Part_List, SIGNAL(triggered()), this, SLOT(partListSlot()));
    connect(juicer->actionRename, SIGNAL(triggered()), this, SLOT(renameSlot()));
    connect(juicer->actionRename_By_Clipboard, SIGNAL(triggered()), this, SLOT(renamePlusSlot()));
    connect(juicer->actionOpen, SIGNAL(triggered()), this, SLOT(openSlot()));
    connect(juicer->actionCopy_Link, SIGNAL(triggered()), this, SLOT(linkSlot()));
    connect(juicer->actionRemove_Finished, SIGNAL(triggered()), this, SLOT(cleanSlot()));
    connect(juicer->actionCreate_Link_List, SIGNAL(triggered()), this, SLOT(linkListSlot()));
    connect(juicer->actionHide_Paused, SIGNAL(triggered(bool)), this, SLOT(hidePausedSlot(bool)));
    connect(juicer->actionMaximal_Power, SIGNAL(triggered()), this, SLOT(maxPowerDownload()));
    connect(juicer->actionTarget_Folder, SIGNAL(triggered()), this, SLOT(targetFolder()));

    connect(treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(partListSlot()));

    connect(juicer->actionShow_Part_List_Dock, SIGNAL(triggered(bool)),
             juicer->partListDock, SLOT(setVisible(bool)));
    connect(juicer->partListDock, SIGNAL(visibilityChanged(bool)),
             juicer->actionShow_Part_List_Dock, SLOT(setChecked(bool)));

    #ifdef AJQTGUI_MODE_SPECIAL
        juicer->actionMaximal_Power->setVisible(true);
    #else
        char* mode = getenv("AJQTGUI_MODE");
        juicer->actionMaximal_Power->setVisible(((mode != NULL)) && (strcmp(mode, "SPECIAL") == 0));
    #endif

    juicer->actionHide_Paused->setChecked(OptionsDialog::getSetting("download", "hidePaused", false).toBool());
    hidePausedSlot(juicer->actionHide_Paused->isChecked());
    selectionChanged();
    adjustTabText();
}

DownloadModule::~DownloadModule() {
}

/*!
    \fn DownloadModule::insertDownload(const QString& id, const QString& hash, const QString& fileName, const QString& status, const QString& size, const QString& ready, const QString& power, const QString& tempNumber)
 */
void DownloadModule::insertDownload(const QString& id,
                                    const QString& hash,
                                    const QString& fileName,
                                    const QString& status,
                                    const QString& size,
                                    const QString& ready,
                                    const QString& power,
                                    const QString& tempNumber,
                                    const QString& targetDir)
{
    DownloadItem *downloadItem = findDownload(id);
    if(downloadItem == NULL) {
        downloadItem = new DownloadItem(id, treeWidget);
        downloads[id] = downloadItem;
        if(juicer->actionMaximal_Power->isVisible()) {
            xml->set("setpowerdownload", "&Powerdownload="+Convert::power(50)+"&id="+id);
        }
        downloadItem->update(hash, fileName, status, size, ready, power, tempNumber, targetDir);
        updateView();
        connect(downloadItem->powerSpin, SIGNAL(powerChanged(QString, double)),
                 this, SLOT(applyPowerDownload(const QString &, double)));
    } else {
        if(downloadItem->update(hash, fileName, status, size, ready, power, tempNumber, targetDir)) {
            // -- if status changed => reset tool buttons --
            selectionChanged();
        }
    }
    downloadItem->setHiddenSave(hidePaused && (status == DOWN_PAUSED));
}


/*!
    \fn DownloadModule::insertUser(const QString& downloadId, const QString& id, const QString& fileName, const QString& speed, const QString& status, const QString& power, const QString& queuePos, const QString& os, QTime& time)
 */
void DownloadModule::insertUser(const QString& downloadId,
                                const QString& id,
                                const QString& fileName,
                                const QString& nickname,
                                const QString& speed,
                                const QString& status,
                                const QString& power,
                                const QString& queuePos,
                                const QString& os,
                                const QString& downloadfrom,
                                const QString& downloadto,
                                const QString& actualdownloadposition,
                                QTime& time)
{
    DownloadItem *downloadItem = findDownload(downloadId);
    if(downloadItem == NULL) {  // -- this shouldn't happen, just in case... --
        insertDownload(downloadId, "", "", "", "", "", "", "", "");
        downloadItem = findDownload(downloadId);
    }
    downloadItem->updateUser(id, fileName, nickname, speed, status, power, queuePos,
                             userStatusDescr[status], juicer->osIcons[os], downloadfrom,
                             downloadto, actualdownloadposition, time);
}

/*!
    \fn DownloadModule::updateView()
 */
void DownloadModule::updateView() {
    QList<DownloadItem*> finished;
    for(int i=0; i<treeWidget->topLevelItemCount(); i++) {
        DownloadItem* item = ((DownloadItem*)treeWidget->topLevelItem(i));
        if(item->updateView(downloadStatusDescr)) {
            finished << item;
        }
    }
    if(!finished.isEmpty()) {
        downloadsFinished(finished);
    }
    powerSpin->setEnabled(powerCheck->isChecked());
    adjustTabText();
}

/*!
    \fn DownloadModule::findDownload(const QString& id)
 */
DownloadItem* DownloadModule::findDownload(const QString& id) {
    if (downloads.contains(id)) {
        return downloads[id];
    }
    return NULL;
}

/*!
    \fn DownloadModule::findDownload(const QString& size, const QString& hash)
 */
DownloadItem* DownloadModule::findDownload(const QString& size, const QString& hash) {
    QHash<QString,DownloadItem*>::const_iterator i;
    for(i = downloads.constBegin(); i != downloads.constEnd(); i++) {
        if(QString::number((int)(*i)->getSize()) == size && (*i)->getHash() == hash)
            return *i;
    }
    return NULL;
}

/*!
    \fn DownloadModule::remove(const QString& id)
    removes either download or user
 */
bool DownloadModule::remove(const QString& id) {
    if(removeDownload(id)) {
        return true;
    } else {
        DownloadUser du = findParent(id);
        if(du.user != NULL) {
            du.download->removeUser(id);
            return true;
        }
    }
    return false;
}

/*!
    \fn DownloadModule::removeDownload(const QString& id)
    removes a download
 */
bool DownloadModule::removeDownload(const QString& id) {
    if(downloads.contains(id)) {
        // -- first remove it form the hashtable, than delete it --
        DownloadItem* item = downloads[id];
        downloads.remove(id);
        delete item;
        return true;
    }
    return false;
}

/*!
    \fn DownloadModule::findParent(const QString& id)
 */
DownloadModule::DownloadUser DownloadModule::findParent(const QString& id) {
    DownloadUser du;
    QHash<QString,DownloadItem*>::const_iterator i;
    for(i = downloads.constBegin(); i != downloads.constEnd(); i++) {
        du.download = i.value();
        du.user = du.download->findUser(id);
        if(du.user != NULL) {
            break;
        }
    }
    return du;
}

/*!
    \fn DownloadModule::processSelected(XMLModule::Type type, const QString& request, const QString& para)
 */
void DownloadModule::processSelected(XMLModule::Type type, const QString& request, const QString& para) {
    QItemList items = treeWidget->selectedItems();
    for(QItemList::iterator i = items.begin(); i!=items.end(); i++) {
        xml->make(type, request, para + "&id=" + ((Item*)(*i))->getId());
    }
}

/*!
    \fn DownloadModule::getSelected(const QString& request, const QString& para)
 */
void DownloadModule::getSelected(const QString& request, const QString& para) {
    processSelected(XMLModule::GET, request, para);
}

/*!
    \fn DownloadModule::setSelected(const QString& request, const QString& para)
 */
void DownloadModule::setSelected(const QString& request, const QString& para) {
    processSelected(XMLModule::SET, request, para);
}

void DownloadModule::cancelSlot() {
    QString text = tr("Do you realy want to cancel %n download(s)?", "", treeWidget->selectedItems().size());
    if(QMessageBox::question(juicer, tr("Confirm"), text, QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
        setSelected("canceldownload");
    }
}

void DownloadModule::cleanSlot() {
    xml->set("cleandownloadlist");
}

void DownloadModule::resumeSlot() {
    setSelected("resumedownload");
}

void DownloadModule::pauseSlot() {
    setSelected("pausedownload");
}

void DownloadModule::partListSlot() {
    QString id = getNextIdRoundRobin();
    if(!id.isEmpty()) {
        xml->get("downloadpartlist", "&simple&id=" + id);
    }
    if(treeWidget->selectedItems().count() == 1) { // part list widget flickers if more than one item is selected
        getSelected("downloadpartlist");
    }
}

void DownloadModule::renameSlot() {
    QString oldFilename, newFilename;
    bool ok;

    QItemList selectedItems = treeWidget->selectedItems();
    QItemList::iterator item;
    for(item = selectedItems.begin(); item != selectedItems.end(); item++) {
        oldFilename = (*item)->text(DownloadItem::FILENAME_COL);
        newFilename = QInputDialog::getText( juicer,
                                              tr("rename download"),
                                              tr("enter new filename for ") + oldFilename,
                                              QLineEdit::Normal,
                                              oldFilename,
                                              &ok);
        newFilename = QString(QUrl::toPercentEncoding(newFilename));
        if(ok && !newFilename.isEmpty()) {
            xml->set("renamedownload", "&id=" + ((Item*)(*item))->getId() + "&name=" + newFilename);
        }
    }
}

void DownloadModule::renamePlusSlot() {
    QString oldFilename, newFilename;
    QString newFilenameBase = qApp->clipboard()->text(QClipboard::Clipboard);

    int i = 0;
    QItemList selectedItems = treeWidget->selectedItems();
    QItemList::iterator item;
    for(item = selectedItems.begin(); item != selectedItems.end(); item++) {
        oldFilename = (*item)->text(DownloadItem::FILENAME_COL);
        newFilename = newFilenameBase;
        if(selectedItems.size() > 1) {
            newFilename += "_" + QString::number(i+1);
        }
        QStringList s = oldFilename.split(".");
        if(s.size() > 1) {
            newFilename += "." + s[s.size() - 1];
        }
        newFilename = QString(QUrl::toPercentEncoding(newFilename));
        if(!newFilename.isEmpty()) {
            xml->set("renamedownload", "&id=" + ((Item*)(*item))->getId() + "&name=" + newFilename);
        }
        i++;
    }
}

void DownloadModule::openSlot() {
    QStringList args = Juicer::getExec();
    QString exec = args.takeFirst();

    QString iDir, tDir;
    // -- determine the path --
    AjSettings::LOCATION location = (AjSettings::LOCATION)OptionsDialog::getSetting("location", AjSettings::SAME).toInt();

    QString seperator = juicer->getFilesystemSeparator();
    if(location == AjSettings::SPECIFIC) {
        iDir = OptionsDialog::getSetting("incomingDirSpecific", "/").toString() + seperator;
        tDir = OptionsDialog::getSetting("tempDirSpecific", "/").toString() + seperator;
    }
    else if(location == AjSettings::SAME) {
        iDir = incomingDir + seperator;
        tDir = tempDir + seperator;
    }
    // -- ftp --
    else {
        // TODO
        return;
    }

    QItemList selectedItems = treeWidget->selectedItems();
    QItemList::iterator item;
    for(item = selectedItems.begin(); item != selectedItems.end(); item++) {
        DownloadItem* ajDownloadItem = (DownloadItem*)(*item);
        if(ajDownloadItem->getStatus() == DOWN_FINISHED) {
            args.push_back(iDir + ajDownloadItem->text(DownloadItem::FILENAME_COL));
        } else {
            args.push_back(tDir + ajDownloadItem->getTempNumber() + ".data");
        }
        QProcess::startDetached(exec, args);
        args.pop_back();
    }
}

void DownloadModule::linkSlot() {
    QString link = ((DownloadItem*)(treeWidget->selectedItems()[0]))->getLinkAJFSP();
    juicer->setClipboard(link);
}

/*!
    \fn DownloadModule::setMultiPowerDownload()
 */
void DownloadModule::setMultiPowerDownload() {
    float value = powerCheck->isChecked() ? powerSpin->value() : 1.0;
    setSelected("setpowerdownload", "&Powerdownload=" + Convert::power(value));
}

/*!
    \fn DownloadModule::applyPowerDownload()
 */
void DownloadModule::applyPowerDownload() {
    if(treeWidget->selectedItems().size() == 1) {
        float value = powerCheck->isChecked() ? powerSpin->value() : 1.0;
        setSelected("setpowerdownload", "&Powerdownload=" + Convert::power(value));
    }
}

/*!
    \fn DownloadModule::applyPowerDownload(const QString& id, double value)
 */
void DownloadModule::applyPowerDownload(const QString& id, double value) {
    xml->set("setpowerdownload", "&Powerdownload="+Convert::power(value)+"&id="+id);
}

/*!
    \fn DownloadModule::maxPowerDownload()
 */
void DownloadModule::maxPowerDownload() {
    QList<QString> ids = downloads.keys();
    for(QList<QString>::iterator i = ids.begin(); i != ids.end(); i++) {
        xml->set("setpowerdownload", "&Powerdownload="+Convert::power(50)+"&id="+(*i));
    }
}

/*!
    \fn DownloadModule::hidePausedSlot(bool checked)
 */
void DownloadModule::hidePausedSlot(bool checked) {
    bool b = treeWidget->updatesEnabled();
    treeWidget->setUpdatesEnabled(false);
    QHash<QString,DownloadItem*>::const_iterator i;
    for(i = downloads.constBegin(); i != downloads.constEnd(); i++) {
        (*i)->setHiddenSave(checked && ((*i)->getStatus() == DOWN_PAUSED));
    }
    hidePaused = checked;
    treeWidget->setUpdatesEnabled(b);
    OptionsDialog::setSetting("download", "hidePaused", hidePaused);
}

/*!
    \fn DownloadModule::selectionChanged()
 */
void DownloadModule::selectionChanged() {
    bool onePaused = false;
    bool oneActive = false;
    QItemList selectedItems = treeWidget->selectedItems();
    bool oneSelected = !selectedItems.empty();
    bool multipleSelected = selectedItems.size() > 1;

    if (oneSelected) {
        powerButtonAction->setVisible(multipleSelected);
        // -- always use values of first selected download --
        DownloadItem* downloadItem = dynamic_cast<DownloadItem*>(selectedItems.at(0));
        bool pwdl = downloadItem->powerDownloadActive();
        powerCheck->setChecked(pwdl);
        if (pwdl) {
            powerSpin->setValue(downloadItem->powerDownloadValue());
        } else {
            powerSpin->setValue(1.0);
        }
    } else {
        powerButtonAction->setVisible(false);
        powerCheck->setChecked(false);
        powerSpin->setValue(1.0);
    }

    QItemList::iterator i;
    for(i = selectedItems.begin(); i != selectedItems.end(); i++) {
        DownloadItem* downloadItem = dynamic_cast<DownloadItem*>(*i);
        if (!downloadItem) {
            Q_ASSERT(false);
            return;
        }
        if(downloadItem->getStatus() == DOWN_PAUSED) {
            onePaused = true;
        }
        if((downloadItem->getStatus() == DOWN_SEARCHING) || (downloadItem->getStatus() == DOWN_LOADING)) {
            oneActive = true;
        }
        if(onePaused && oneActive) {
            break;
        }
    }

    juicer->actionPause->setEnabled(oneActive);
    juicer->actionResume->setEnabled(onePaused);
    juicer->actionCancel->setEnabled(oneSelected);
    juicer->actionShow_Part_List->setEnabled(oneSelected);
    juicer->actionRename->setEnabled(oneSelected);
    juicer->actionRename_By_Clipboard->setEnabled(oneSelected);
    juicer->actionOpen->setEnabled(oneSelected);
    juicer->actionCopy_Link->setEnabled(oneSelected);
    juicer->actionCreate_Link_List->setEnabled(oneSelected);
    juicer->actionTarget_Folder->setEnabled(oneSelected);

    // clear part list widget if none or more than one item is selected
    if(multipleSelected) {
        juicer->partsWidget->clear();
    }
}


/*!
    \fn DownloadModule::getNextIdRoundRobin()
 */
QString DownloadModule::getNextIdRoundRobin() {
    if(treeWidget->topLevelItemCount() < 1) {
        return "";
    }
    currIdRoundRobin ++;
    currIdRoundRobin %= treeWidget->topLevelItemCount();
    return ((DownloadItem*)treeWidget->topLevelItem(currIdRoundRobin))->getId();
}


/*!
    \fn DownloadModule::setDirs(const QString& tmpDir, const QString& inDir)
 */
void DownloadModule::setDirs(const QString& tmpDir, const QString& inDir)  {
    this->tempDir     = tmpDir;
    this->incomingDir = inDir;
}


/*!
    \fn DownloadModule::findDownloadByTempNum(const QString& tempFile)
 */
QString DownloadModule::findDownloadByTempNum(const QString& tempFile) {
    QStringList splitPath = tempFile.split(juicer->getFilesystemSeparator());
    QString filename      = splitPath.last();
    if (tempFile.contains(tempDir)) {
        QStringList splitFilename = filename.split(".");
        QString tempNum = splitFilename.first();
        QHash<QString,DownloadItem*>::const_iterator i;
        for(i = downloads.constBegin(); i != downloads.constEnd(); i++) {
//            qDebug() << (*i)->getTempNumber() << " - " << tempNum;
            if((*i)->getTempNumber() == tempNum) {
                return (*i)->text(DownloadItem::FILENAME_COL);
            }
        }
    }
    return filename;
}

/*!
    \fn DownloadModule::storeDownloadFtp()
 */
void DownloadModule::storeDownloadFtp() {
    FTP* ftp = NULL;
    QString filename, localDir;
    QItemList  selectedItems = treeWidget->selectedItems();

    QString dir = OptionsDialog::getSetting("ftp", "dir", "/").toString();

    if(!dir.endsWith('/')) {
        dir += '/';
    }
    ftp = new FTP(this);

    QItemList::iterator item;
    for(item = selectedItems.begin(); item != selectedItems.end(); item++) {
        filename = (*item)->text(DownloadItem::FILENAME_COL);
        localDir = QFileDialog::getExistingDirectory(juicer, "save \"" + filename + "\" + to");
        if (localDir != "") {
            if(!localDir.endsWith(QDir::separator())) {
                localDir += QDir::separator();
            }
            QFile* dstFile = new QFile(localDir + filename);
            if(!dstFile->exists()) {
                dstFile->open(QIODevice::WriteOnly);
                ftp->add(dir + filename, dstFile);
            }
        }
    }
    ftp->start();
}


/*!
    \fn DownloadModule::setPartList(const QString& id, PartsWidget::PartList& partList)
 */
void DownloadModule::setPartList(const QString& id, PartsWidget::PartList& partList) {
    DownloadItem* item = findDownload(id);
    if(item != NULL) {
        if(item->getPartListDialog()->isVisible()) {
            item->getPartListDialog()->update(partList);
        }
        if(juicer->partsWidget->isVisible() && item->isSelected()) {
            juicer->partsWidget->update(partList);
        }
        item->setMissing(partList.getMissing());
    }
}


/*!
    \fn DownloadModule::partListWidgetSlot()
 */
void DownloadModule::partListWidgetSlot() {
    QItemList items = treeWidget->selectedItems();
    for(QItemList::iterator i = items.begin(); i!=items.end(); i++) {
        DownloadItem* tmp = dynamic_cast<DownloadItem*>(*i);
        if (tmp) tmp->getPartListDialog()->show();
    }
}


/*!
    \fn DownloadModule::targetFolder()
 */
void DownloadModule::targetFolder() {
    DirSelectionDialog tf(tr("Select a folder below ") + juicer->getIncomingDirectory(),
            juicer->getIncomingDirectory(), false, xml, juicer);
    tf.leNewFolder->setHidden(false);
    tf.labelNewFolder->setHidden(false);
    if(tf.exec() == QDialog::Accepted) {
        QString path = tf.getPath();  // ever below incoming!
        qDebug() << path;
        setSelected("settargetdir", "&dir=" + path);
    }
}


/*!
    \fn DownloadModule::adjustTabText()
 */
void DownloadModule::adjustTabText() {
    int loading = 0;
    QHash<QString,DownloadItem*>::const_iterator i;
    for(i = downloads.constBegin(); i != downloads.constEnd(); i++) {
        DownloadItem* downloadItem = dynamic_cast<DownloadItem*>(*i);
        if(downloadItem->getStatus() == DOWN_LOADING) {
            loading++;
        }
    }
    juicer->ajTab->setTabText(tabIndex, tabText + " " + QString::number(loading) + "/" + QString::number(downloads.size()));
}
