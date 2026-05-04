#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("FTP");
    QCoreApplication::setApplicationVersion(QStringLiteral(APP_VERSION) + "." + QStringLiteral(GIT_COMMIT_HASH));
    QGuiApplication::setApplicationDisplayName(
        QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion()
        );


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Flight_Task_Planner", "Main");

    return QCoreApplication::exec();
}
