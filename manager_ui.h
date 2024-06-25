#ifndef MANAGER_UI_H
#define MANAGER_UI_H

#include <QObject>

#include "sqlite_connect.h"

class manager_ui:public QObject,public sqlite_connect
{
    Q_OBJECT
public:
    manager_ui(QObject *parent=nullptr):QObject(parent),sqlite_connect(){};

public slots:
    Q_INVOKABLE QString QueryStudentButton();
};

#endif // MANAGER_UI_H
