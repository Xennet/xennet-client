#ifndef XENNET_H
#define XENNET_H

#include <QObject>

#include "model.h"

class xennetapp : public QObject
{
    Q_OBJECT
public:
    explicit xennetapp( QObject *parent = 0 ) : QObject( parent ) {}

signals:

public slots:

};

#endif // XENNET_H
