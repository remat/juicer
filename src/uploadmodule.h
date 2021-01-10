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

#ifndef QAJUPLOADWIDGET_H
#define QAJUPLOADWIDGET_H

#include <QHash>
#include <QIcon>
#include <QFileInfo>
#include "modulebase.h"
#include "uploaditem.h"

#include <QStandardItemModel>

/**
@author Matthias Reif
*/
class UploadModule : public ModuleBase {
    Q_OBJECT
public:
    QStandardItemModel* model;
    UploadModule(Juicer* juicer, QWidget* tabWidget);

    ~UploadModule();

    bool insertUpload(const QString& id, const QString& shareId, const QString& version,
                      const QString& os, const QString& status, const QString& directState,
                      const QString& priority, const QString& nick, const QString& speed,
                      const QString& loaded, const QString& chunkStart, const QString& chunkEnd,
                      const QString& chunkPos, const QString& lastConnected);

    bool remove( const QString& id );
    void setFilename( const QString& shareId, const QString& filename );
public slots:
    void adjustSizeOfColumns();
    void selectionChanged();
    void hideQueuedSlot( bool checked );
private:
    UploadItem* findUpload( const QString& id );
    void adjustTabText();
    QHash<QString, QString> uploadStatusDescr;
    QHash<QString, QString> uploadDirectStateDescr;
    QHash<QString, UploadItem*> uploads;
    bool hideQueued;
};

#endif
