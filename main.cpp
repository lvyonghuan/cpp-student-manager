#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "manager_ui.h"
#include "sqlite_connect.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<manager_ui>("manager_ui", 1, 0, "ManagerUI");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("student-manager", "Main");

    sqlite_connect db;

    return app.exec();
}

