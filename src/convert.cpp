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

#include "convert.h"

Convert::Convert(QObject *parent) : QObject(parent)
{}

Convert::~Convert()
{}

QString Convert::bytes(const QString& x) {
    return bytes(x.toDouble());
}

QString Convert::bytes(long int x) {
    if (x >= ONE_GIG)
        return QString::number(x / (ONE_GIG)) + " Gb";
    else if (x >= ONE_MEG)
        return QString::number(x / (ONE_MEG)) + " Mb";
    else if (x >= ONE_KILO)
        return QString::number(x / (ONE_KILO)) + " kb";
    else
        return QString::number(x) + " b";
}

QString Convert::bytes(double x, int precision) {
    double absX = x>0.0?x:-x;

    if (absX >= ONE_GIG)
        return QString::number(x / (ONE_GIG), 'f', precision) + " Gb";
    else if (absX >= ONE_MEG)
        return QString::number(x / (ONE_MEG), 'f', precision) + " Mb";
    else if (absX >= ONE_KILO)
        return QString::number(x / (ONE_KILO), 'f', precision) + " kb";
    else
        return QString::number(x) + " b";
}

QString Convert::bytes(qulonglong x) {
    if (x >= (qulonglong)ONE_GIG)
        return QString::number((x / ONE_GIG)) + " Gb";
    else if (x >= (qulonglong)ONE_MEG)
        return QString::number((x / ONE_MEG)) + " Mb";
    else if (x >= (qulonglong)ONE_KILO)
        return QString::number((x / ONE_KILO)) + " kb";
    else
        return QString::number(x) + " b";
}

QString Convert::bytes(qulonglong x, int precision) {
    if (x >= (qulonglong)ONE_GIG)
        return QString::number((x / (float)(ONE_GIG)), 'f', precision) + " Gb";
    else if (x >= (qulonglong)ONE_MEG)
        return QString::number((x / (float)(ONE_MEG)), 'f', precision) + " Mb";
    else if (x >= (qulonglong)ONE_KILO)
        return QString::number((x / (float)(ONE_KILO)), 'f', precision) + " kb";
    else
        return QString::number(x) + " b";
}


QString Convert::bytes(const QString& x, const QString& y) {
    double x1 = x.toDouble() - y.toDouble();
    return Convert::bytes(x1, 2);
}

QString Convert::bytesLong(const QString& x) {
    // x in Mbyte
    double x1 = x.section(',',0,0).toDouble();
    if (x1 >= ONE_MEG)
        return QString::number(x1 / (ONE_MEG), 'f', 2) + " Terrabyte";
    else if (x1 >= ONE_KILO)
        return QString::number(x1 / (ONE_KILO), 'f', 2) + " Gigabyte";
    else
        return x + " Mbyte";
}

QString Convert::bytesExtra(const QString& x) {
    bool negative = (x[0] == '-');
    qlonglong x1 = qAbs(x.toLongLong());
    int base = 1;
    QString unit;
    if (x1 >= ONE_GIG) {
        base = ONE_GIG;
        unit = " Gb";
    } else if (x1 >= ONE_MEG) {
        base = ONE_MEG;
        unit = " Mb";
    } else if (x1 >= ONE_KILO) {
        base = ONE_KILO;
        unit = " kb";
    } else {
        base = 1;
        unit = " b";
    }

    double r = (double)(x1 / (base));
    r += (double)((x1 % (base))) / base ;

    if (negative)
        r *= -1;
    return QString::number(r , 'f', 2) + unit;
}

QString Convert::num(long int num) {
    if (num < 10)
        return QString("0" + QString::number(num));
    else
        return QString::number(num);
}

float Convert::powerValue(const QString& x) {
    float x1 = x.toFloat();
    return (x1 + 10) / 10.0;
}

QString Convert::power(const QString& x) {
    float x1 = x.toFloat();
    x1 = (x1 + 10) / 10.0;
    return "1:"+QString::number(x1, 'f', 1);
}

QString Convert::power(float power) {
    return QString::number(power*10 - 10,'f',0);
}

QString Convert::time(long int seconds) {
    int days, hours, minutes;
    days = hours = minutes = 0;
    if (seconds >= ONE_DAY) {
        days = seconds / ONE_DAY;
        seconds %= ONE_DAY;
    }
    if (seconds >= ONE_HOUR) {
        hours = seconds / ONE_HOUR;
        seconds %= ONE_HOUR;
    }
    if (seconds >= ONE_MINUTE) {
        minutes = seconds / ONE_MINUTE;
        seconds %= ONE_MINUTE;
    }
    QString time ;
    if (days == 1)
        time = "> 1 day";
    else if (days > 1)
        time = "> " + QString::number(days) + " days";
    else
        time = num(hours) + ":" + num(minutes) + ":" + num(seconds);
    return time;
}


/*!
    \fn Convert::getFileErrorString(QFile::FileError error)
 */
QString Convert::getFileErrorString(QFile::FileError error) {
    switch (error) {
        case QFile::ReadError: return tr("An error occurred when reading from the file.");
        break;
        case QFile::WriteError: return tr("An error occurred when writing to the file.");
        break;
        case QFile::FatalError: return tr("A fatal error occurred.");
        break;
        case QFile::ResourceError: return tr("Not enough disk space.");
        break;
        case QFile::OpenError: return tr("The file could not be opened.");
        break;
        case QFile::AbortError: return tr("The operation was aborted.");
        break;
        case QFile::TimeOutError: return tr("A timeout occurred.");
        break;
        case QFile::PermissionsError: return tr("The file could not be accessed.");
        break;
        default: return tr("An unspecified error occurred.");
    }
}


/*!
    \fn Convert::compareVersion(const QString& v1, const QString& v2)
 */
int Convert::compareVersion(const QString& v1, const QString& v2) {
    QRegExp removeZeros("\\.0*$");
    QStringList v1s = QString(v1).remove(removeZeros).split(".");
    QStringList v2s = QString(v2).remove(removeZeros).split(".");
    for(int i=0; i<min(v1s.size(), v2s.size()); i++) {
        if(v1s.at(i).toInt() > v2s.at(i).toInt()) {
            return 1;
        } else if (v1s.at(i).toInt() < v2s.at(i).toInt()) {
            return -1;
        }
    }
    if(v1s.size() > v2s.size()) {
        return 1;
    } else if(v1s.size() < v2s.size()) {
        return -1;
    } else {
        return 0;
    }
}


/*!
    \fn Convert::dateString(const QString& mSeconds)
 */
QString Convert::dateString(const QString& mSeconds) {
    return Convert::dateTime(mSeconds).toLocalTime().toString(Qt::LocalDate);
}

/*!
    \fn Convert::dateTime(const QString& mSeconds)
 */
QDateTime Convert::dateTime(const QString& mSeconds) {
    static QDateTime zeroTime(QDate(1970,1,1), QTime(0,0), Qt::UTC);
    return zeroTime.addMSecs(mSeconds.toULongLong());
}

#ifdef Q_WS_WIN

#include <qt_windows.h>

QIcon Convert::getFileIcon(const QFileInfo& file) {
	return Convert::getFileIcon(file.canonicalFilePath(), file.exists());
}

QIcon Convert::getFileIcon(const QUrlInfo& url) {
    return Convert::getFileIcon(url.name());
}

QIcon Convert::getFileIcon(const QString &path, bool exists) {
    // performance tuned using:
    //http://www.codeguru.com/Cpp/COM-Tech/shell/article.php/c4511/
	QString path2(path);
	path2.replace('/','\\');  // -- necessary, I don't exactly know why... --
	UINT flags = SHGFI_ICON | SHGFI_LARGEICON;
	if(!exists) {
		flags |= SHGFI_USEFILEATTRIBUTES;
	}
    SHFILEINFO file_info;
    ::SHGetFileInfo((wchar_t*)path2.utf16(),FILE_ATTRIBUTE_NORMAL,
            &file_info, sizeof(SHFILEINFO), flags);
    return QIcon(convertHIconToPixmap(file_info.hIcon));
}

QPixmap Convert::convertHIconToPixmap(const HICON icon) {
    bool foundAlpha = false;
    HDC screenDevice = GetDC(0);
    HDC hdc = CreateCompatibleDC(screenDevice);
    ReleaseDC(0, screenDevice);

    ICONINFO iconinfo;
    bool result = GetIconInfo(icon, &iconinfo); //x and y Hotspot describes the icon center
    if (!result)
        qWarning("convertHIconToPixmap(), failed to GetIconInfo()");

    int w = iconinfo.xHotspot * 2;
    int h = iconinfo.yHotspot * 2;

    BITMAPINFOHEADER bitmapInfo;
    bitmapInfo.biSize        = sizeof(BITMAPINFOHEADER);
    bitmapInfo.biWidth       = w;
    bitmapInfo.biHeight      = h;
    bitmapInfo.biPlanes      = 1;
    bitmapInfo.biBitCount    = 32;
    bitmapInfo.biCompression = BI_RGB;
    bitmapInfo.biSizeImage   = 0;
    bitmapInfo.biXPelsPerMeter = 0;
    bitmapInfo.biYPelsPerMeter = 0;
    bitmapInfo.biClrUsed       = 0;
    bitmapInfo.biClrImportant  = 0;
    DWORD* bits;

    HBITMAP winBitmap = CreateDIBSection(hdc, (BITMAPINFO*)&bitmapInfo, DIB_RGB_COLORS, (VOID**)&bits, NULL, 0);
    HGDIOBJ oldhdc = (HBITMAP)SelectObject(hdc, winBitmap);
    DrawIconEx(hdc, 0, 0, icon, iconinfo.xHotspot * 2, iconinfo.yHotspot * 2, 0, 0, DI_NORMAL);
    QImage image = qt_fromWinHBITMAP(hdc, winBitmap, w, h);

    for (int y = 0 ; y < h && !foundAlpha ; y++) {
        QRgb *scanLine= reinterpret_cast<QRgb *>(image.scanLine(y));
        for (int x = 0; x < w ; x++) {
            if (qAlpha(scanLine[x]) != 0) {
                foundAlpha = true;
                break;
            }
        }
    }
    if (!foundAlpha) {
        //If no alpha was found, we use the mask to set alpha values
        DrawIconEx(hdc, 0, 0, icon, w, h, 0, 0, DI_MASK);
        QImage mask = qt_fromWinHBITMAP(hdc, winBitmap, w, h);

        for (int y = 0 ; y < h ; y++){
            QRgb *scanlineImage = reinterpret_cast<QRgb *>(image.scanLine(y));
            QRgb *scanlineMask = mask.isNull() ? 0 : reinterpret_cast<QRgb *>(mask.scanLine(y));
            for (int x = 0; x < w ; x++){
                if (scanlineMask && qRed(scanlineMask[x]) != 0)
                    scanlineImage[x] = 0; //mask out this pixel
                else
                    scanlineImage[x] |= 0xff000000; // set the alpha channel to 255
            }
        }
    }
    //dispose resources created by iconinfo call
    DeleteObject(iconinfo.hbmMask);
    DeleteObject(iconinfo.hbmColor);

    SelectObject(hdc, oldhdc); //restore state
    DeleteObject(winBitmap);
    DeleteDC(hdc);
    return QPixmap::fromImage(image);
}

QImage Convert::qt_fromWinHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h) {
    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = w;
    bmi.bmiHeader.biHeight      = -h;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage   = w * h * 4;

    QImage image(w, h, QImage::Format_ARGB32_Premultiplied);
    if (image.isNull())
        return image;

    // Get bitmap bits
    uchar *data = (uchar *) qMalloc(bmi.bmiHeader.biSizeImage);

    if (GetDIBits(hdc, bitmap, 0, h, data, &bmi, DIB_RGB_COLORS)) {
        // Create image and copy data into image.
        for (int y=0; y<h; ++y) {
            void *dest = (void *) image.scanLine(y);
            void *src = data + y * image.bytesPerLine();
            memcpy(dest, src, image.bytesPerLine());
        }
    } else {
        qWarning("qt_fromWinHBITMAP(), failed to get bitmap bits");
    }

    return image;
}
#else
QIcon Convert::getFileIcon(const QFileInfo& file) {
    static QFileIconProvider fileIconProvider;
    return fileIconProvider.icon(file);
}

QIcon Convert::getFileIcon(const QUrlInfo& url) {
    static QFileIconProvider fileIconProvider;
    if(url.isFile()) {
        return fileIconProvider.icon(QFileIconProvider::File);
    } else if(url.isDir()) {
        return fileIconProvider.icon(QFileIconProvider::Folder);
    } else {
        return QIcon();
    }
}

QIcon Convert::getFileIcon(const QString &path, bool exists) {
    return QIcon();
}
#endif
