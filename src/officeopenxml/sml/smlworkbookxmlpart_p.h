/****************************************************************************
**
** Copyright (C) 2014-2015 Debao Zhang <hello@debao.me>
**
** This file is part of the QtOfficeOpenXml library.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPLv2 included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
****************************************************************************/
#ifndef QTOFFICEOPENXML_SML_SMLWORKBOOKPART_P_H
#define QTOFFICEOPENXML_SML_SMLWORKBOOKPART_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt Office Open Xml API.  It exists for
// the convenience of the Qt Office Open Xml.  This header file may
// change from version to version without notice, or even be removed.
//
// We mean it.
//

#include <private/ooxmlabstractfixedtypexmlpart_p.h>
#include <QtOfficeOpenXml/smlglobal.h>
#include <QtCore/qhash.h>
#include <QtCore/qlist.h>

namespace QtOfficeOpenXml {
namespace Sml {
class Workbook;
class WorkbookXmlPart : public Ooxml::AbstractFixedTypeXmlPart
{
public:
    WorkbookXmlPart(Workbook *wb, const QString &partName, Opc::Package *package);
    QString contentType() const Q_DECL_OVERRIDE;

    //Items contains "r:Id" attributes
    QList<QHash<QString, QString> > sheets;
    QList<QString> externalReferences;

private:
    bool doLoadFromXml(QIODevice *device, Ooxml::SchameType schameType) Q_DECL_OVERRIDE;
    bool doSaveToXml(QIODevice *device, Ooxml::SchameType schameType) const Q_DECL_OVERRIDE;

    Workbook *wb;
};

} // namespace Sml
} // namespace QtOfficeOpenXml

#endif // QTOFFICEOPENXML_SML_SMLWORKBOOKPART_P_H
