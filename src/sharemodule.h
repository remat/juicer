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

#ifndef QAJSHAREWIDGET_H
#define QAJSHAREWIDGET_H

#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>

#include "modulebase.h"
#include "shareitem.h"
#include "sharefileitem.h"
#include "dirselectiondialog.h"

/**
@author Matthias Reif
*/
class ShareModule : public ModuleBase
{
    Q_OBJECT

    QHash<QString, ShareFileItem*> sharedFiles;

public:
    QLabel*        prioLabel;
    QSpinBox*      prioSpin;
    QPushButton*   prioButton;

    ShareModule(Juicer* juicer);
    ~ShareModule();

    ShareFileItem* findFile(const QString& id);
    ShareFileItem* findFile(const QString& size, const QString& hash);

    void insertShare(const QString& path, const QString& shareMode);
    void insertFile(const QString& id, const QString& hash, const QString& fileName,
                    const QString& size, const QString& priority, const QString& lastAsked,
                    const QString& askCount, const QString& searchCount,
                    const QString& filesystemSeperator);
    void updateSharedFilesList();

    bool isChanged() const {
        return changed_;
    }
    void reset() {
        sharedFiles.clear();
    }

public slots:
    void commitSlot();
    void selectionChanged();
    void reloadSlot();

protected:
    ShareItem* findShare(const QString& fileName);
    QString filesystemSeparator;
    int prio_;
    bool changed_;

private slots:
    void insertSlot();
    void removeSlot();
    void linkSlot();
    void setTmpPriority(int prio);
    void setPriority();
};

#endif
