/*
    Application EntryPoint
*/
#include "Views/WinMain.h"

#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <QDir>

#include <StyleController.h>
#include <InitializationConfig.h>
#include <ELanguages.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // === Read the config.ini file ===
    QString configPath = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);

    Controller::InitializationConfig::Instance().SetTheme(settings.value("Theme", 1).toBool());
    Controller::InitializationConfig::Instance().SetLanguage(static_cast<Controller::ELanguages>(settings.value("Language", 0).toInt()));

    // === Set Software version ===
    QString softwareVersion = "0.1.15 (Build August 2025)";   // =====> Version number
    Controller::InitializationConfig::Instance().SetVersion(softwareVersion);

    // === Set Themes ===
    Controller::StyleController::Instance().DarkThemeStatus(Controller::InitializationConfig::Instance().GetTheme());

    // === Load and set Translation .qm file ===
    QTranslator translator;
    QString translationFile;

    QMap<Controller::ELanguages, QString> translationMap = {
        { Controller::ELanguages::Portuguese, ":/Translations/TrimSheet_ToolsV2_pt_BR.qm" },
        { Controller::ELanguages::Spanish,    ":/Translations/TrimSheet_ToolsV2_es_ES.qm" },
        { Controller::ELanguages::Chinese,    ":/Translations/TrimSheet_ToolsV2_zh_CN.qm" }
    };

    translationFile = translationMap.value(Controller::InitializationConfig::Instance().GetLanguage(), "");
    if (!translationFile.isEmpty()) {
        translator.load(translationFile);
        a.installTranslator(&translator);
    }

    // === Start the Main Window ===
    View::WinMain w;
    w.Init();
    w.show();
    return a.exec();
}
