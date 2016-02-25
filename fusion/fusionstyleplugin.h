#ifndef FUSIONSTYLEPLUGIN_H
#define FUSIONSTYLEPLUGIN_H

#include <QtGui/QStylePlugin>
#include "qfusionstyle.h"

class FusionStylePlugin: public QStylePlugin
{
    Q_OBJECT

public:
    FusionStylePlugin(QObject *parent = 0);
    QStyle *create(const QString &key);
    QStringList keys() const;
};

#endif // FUSIONSTYLEPLUGIN_H
