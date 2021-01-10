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

#include "searchentryitem.h"

#include "searchitem.h"

SearchEntryItem::SearchEntryItem(const QString& id, SearchItem* search, const QString& checksum,
            const QString& size, QTreeWidgetItem* parent) : Item(parent, id) {
    this->search = search;
    if(hash_.isEmpty()) {
        hash_ = checksum;
    }
    size_ = size.toDouble();
}

SearchEntryItem::~SearchEntryItem() {
}

bool SearchEntryItem::operator<(const QTreeWidgetItem & other) const {
    int sortIndex = treeWidget()->header()->sortIndicatorSection();
    SearchEntryItem* searchItem = (SearchEntryItem*)&other;
    switch(sortIndex) {
    case SearchItem::SIZE_COL:
        return size_ < searchItem->getSize();
    default:
        return this->text(sortIndex) < other.text(sortIndex);
    }
}

void SearchEntryItem::setFilename(const QString& filename) {
    filename_ = filename;
}


/*!
    \fn SearchEntryItem::setFilter(Filter& filter)
 */
void SearchEntryItem::setFilter(Filter& filter) {
    bool ok = true
        && (size_ >= filter.minSize)
        && (size_ <= filter.maxSize)
        && (!filter.type.isValid() || filter.type.indexIn(filename_) >=0);
    setHidden(!ok);
}
