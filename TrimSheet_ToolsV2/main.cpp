#include "Views/WinMain.h"

#include <QApplication>
#include <QStyleFactory>
#include <QLocale>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TrimSheet_ToolsV2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    View::WinMain w;
    w.show();
    return a.exec();
}
