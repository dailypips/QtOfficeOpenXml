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
#ifndef OPCPACKAGERELATIONSHIP_P_H
#define OPCPACKAGERELATIONSHIP_P_H

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

#include <QtOfficeOpenXml/opcpackagerelationship.h>
#include <QtCore/qmap.h>

class QIODevice;

namespace QtOfficeOpenXml {
namespace Opc {
class Package;
class PackagePart;
class PackageRelationshipPrivate
{
public:
    PackageRelationshipPrivate(const QString &id, const QString &type, const QString &source, const QString &target, TargetMode targetMode)
        :id(id), relationshipType(type), source(source), target(target), targetMode(targetMode)
    {
    }

    QString id;
    QString relationshipType;
    QString source;
    QString target;
    TargetMode targetMode;
};

class PackageRelationshipHelper
{
public:
    PackageRelationshipHelper(Package *package, const QString &sourcePartName);
    ~PackageRelationshipHelper();
    void flush();

    PackageRelationship *relationship(const QString &id) const;
    QList<PackageRelationship *> relationships() const;
    QList<PackageRelationship *> getRelationshipsByType(const QString &type) const;
    PackageRelationship *createRelationship(const QString &target, TargetMode mode, const QString &type, const QString &id=QString());
    void deleteRelationship(const QString &id);

private:
    void doLoadFromXml(QIODevice *device);
    void doSaveToXml(QIODevice *device);

    QMap<QString, PackageRelationship *> m_relationships;
    Package *m_package;
    PackagePart *m_relationshipsPart;
    QString m_sourcePartName;
    bool m_dirty;
};


} // namespace Opc
} // namespace QtOfficeOpenXml

#endif // OPCPACKAGERELATIONSHIP_P_H
