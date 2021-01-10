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

#include "uploadmodule.h"
#include "juicer.h"


UploadModule::UploadModule(Juicer* juicer, QWidget* tabWidget)
  : ModuleBase(juicer, juicer->uploadsTreeWidget, juicer->uploadToolBar, tabWidget)
{
    uploadStatusDescr["1"] = "active";
    uploadStatusDescr["2"] = "queueing";

    uploadDirectStateDescr["0"] = "disconnected";
    uploadDirectStateDescr["1"] = "active";
    uploadDirectStateDescr["2"] = "passive";

    connect(juicer->actionHide_Queued, SIGNAL(triggered(bool)), this, SLOT(hideQueuedSlot(bool)));
    juicer->actionHide_Queued->setChecked(OptionsDialog::getSetting("upload", "hideQueued", false).toBool());
    hideQueuedSlot(juicer->actionHide_Queued->isChecked());
    adjustTabText();
}


UploadModule::~UploadModule()
{}

bool UploadModule::insertUpload(
            const QString& id, const QString& shareId, const QString& version,
            const QString& os, const QString& status, const QString& directState,
            const QString& priority, const QString& nick, const QString& speed,
            const QString& loaded, const QString& chunkStart, const QString& chunkEnd,
            const QString& chunkPos, const QString& lastConnected )
{
    UploadItem *uploadItem = findUpload(id);
    bool newUpload = uploadItem == NULL;
    if(newUpload) {
        uploadItem = new UploadItem(id, shareId, treeWidget);
        uploads[ id ] = uploadItem;
    }
    if(uploadItem->update(juicer->osIcons[os], status, uploadStatusDescr[status],
            uploadDirectStateDescr[directState], priority, nick, speed, version,
            loaded, chunkStart, chunkEnd, chunkPos, lastConnected, newUpload)) {
        adjustTabText();
    }
    uploadItem->setHiddenSave(hideQueued && (status == QUEUEING_UPLOAD));
    return !newUpload;
}

bool UploadModule::remove( const QString& id )
{
    QTreeWidgetItem *item = findUpload(id);
    if(item != NULL) {
        uploads.remove(id);
        delete item;
        adjustTabText();
        return true;
    }
    return false;
}


UploadItem* UploadModule::findUpload(const QString& id) {
    if(uploads.contains(id)) {
        return uploads[id];
    }
    return NULL;
}


/*!
    \fn UploadModule::setFilename(const QString& shareId, const QString& filename)
 */
void UploadModule::setFilename(const QString& shareId, const QString& filename) {
    QHash<QString, UploadItem*>::const_iterator item;
    for(item = uploads.constBegin(); item != uploads.constEnd(); item++) {
        if((*item)->getShareID() == shareId) {
            bool r = (*item)->setHiddenSave(false);
            (*item)->setText(UploadItem::FILENAME_COL, filename);
            (*item)->setFileIcon(UploadItem::FILENAME_COL);
            (*item)->setHiddenSave(r);
        }
    }
}


/*!
    \fn UploadModule::adjustSizeOfColumns()
 */
void UploadModule::adjustSizeOfColumns() {
    for(int i=0; i<treeWidget->columnCount(); i++) {
        treeWidget->resizeColumnToContents(i);
    }
}

void UploadModule::selectionChanged() {
}

/*!
    \fn UploadModule::hideQueuedSlot(bool checked)
 */
void UploadModule::hideQueuedSlot(bool checked) {
    bool b = treeWidget->updatesEnabled();
    treeWidget->setUpdatesEnabled(false);
    hideQueued = checked;
    QHash<QString,UploadItem*>::const_iterator i;
    for(i = uploads.constBegin(); i != uploads.constEnd(); i++) {
        (*i)->setHiddenSave(hideQueued && ((*i)->getStatus() == QUEUEING_UPLOAD));
    }
    treeWidget->setUpdatesEnabled(b);
    OptionsDialog::setSetting("upload", "hideQueued", hideQueued);
}


/*!
    \fn UploadModule::adjustTabText()
 */
void UploadModule::adjustTabText() {
    int active = 0;
    QHash<QString,UploadItem*>::const_iterator i;
    for(i = uploads.constBegin(); i != uploads.constEnd(); i++) {
        UploadItem* uploadItem = dynamic_cast<UploadItem*>(*i);
        if(uploadItem->getStatus() == ACTIVE_UPLOAD) {
            active++;
        }
    }
    juicer->ajTab->setTabText(tabIndex, tabText + " " + QString::number(active) + "/" + QString::number(uploads.size()));
}