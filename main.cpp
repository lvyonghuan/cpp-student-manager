#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "sqlite_connect.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("student-manager", "Main");

    sqlite_connect db;

    std::vector<selection> temp=db.QuerySelection();
    while(!temp.empty()){
        selection temp1=temp.back();
        qDebug()<<temp1.course::name<<temp1.student::name;
        temp.pop_back();
    }

    return app.exec();
}
