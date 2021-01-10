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

#ifndef QAJSERVERSOCKET_H
#define QAJSERVERSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>

/**
@author Matthias Reif
*/
class ServerSocket : public QTcpServer
{
Q_OBJECT
public:
    ServerSocket(quint16 port, QObject *parent = 0);
    ~ServerSocket();

protected:
    QTcpSocket* clientSocket;
public slots:
    void readLine();
signals:
    void lineReady(const QString& line);
protected slots:
    void newConnectionSlot();
};

#endif
