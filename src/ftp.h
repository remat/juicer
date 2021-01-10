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

#ifndef FTP_H
#define FTP_H

#include <QObject>
#include <QFtp>
#include <QThread>
#include <QStringList>
#include <QDir>
#include <QHash>
#include <QMessageBox>
#include <QProgressDialog>
#include <QProcess>
#include <QTemporaryFile>

#include "optionsdialog.h"

/**
	@author Matthias Reif <matthias.reif@informatik.tu-chemnitz.de>
*/
class FTP : public QThread
{
    Q_OBJECT
public:
    FTP(const QString& host, int port, const QString& user, const QString& password, bool binary, QObject *parent = 0);
    FTP(QObject *parent = 0);
    ~FTP();
    void getNext();
    void add(const QString& srcFilename, QFile* dstFile);
    void add(const QString& srcFilename);

private:
    class StoreInfo {
        public:
        QString srcFile;
        QFile* dstFile;
    };

    QFtp* ftp;
    QString host;
    int port;
    QString user, password;
    QString srcFile;
    QFile* dstFile;
    bool binary;
    int getFile;

    QList< FTP::StoreInfo > queue;

    QProgressDialog* progressDialog;

    bool ready;
    bool tmpMode;

private slots:
    void stateChangedSlot(int state);
    void commandFinishedSlot(int id, bool error);
signals:
    void done();
    void errorOccured(const QString& message);
    void downloadFinished(QFile* file, FTP* ftp);
    void readyRead(QFile* dstFile, FTP* ftp);
protected:
    void run();
public slots:
    void dataTransferProgressSlot(qint64 done, qint64 total);
    void abort();
private:
    void init();
};

#endif
