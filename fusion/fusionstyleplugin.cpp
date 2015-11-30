#include "fusionstyleplugin.h"

FusionStylePlugin::FusionStylePlugin(QObject *parent): QStylePlugin(parent)
{
}

QStyle *FusionStylePlugin::create(const QString &key)
{
    return (key.toLower() == "fusion") ? new QFusionStyle : 0;
}

QStringList FusionStylePlugin::keys() const
{
    return QStringList() << "fusion";
}

Q_EXPORT_PLUGIN2(fusion, FusionStylePlugin)
