#include "Views/WinMain.h"

#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <QDir>

#include "StyleController.h"
#include "InitiallizationConfig.h"
#include "ELanguages.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // === Leitura do arquivo config.ini ===
    QString configPath = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);

    Controller::InitiallizationConfig::Instance().SetTheme(settings.value("Theme", 1).toBool());
    Controller::InitiallizationConfig::Instance().SetLanguage(static_cast<Controller::ELanguages>(settings.value("Language", 0).toInt()));

    // === Aplicar Tema ===
    Controller::StyleController::Instance().DarkThemeStatus(Controller::InitiallizationConfig::Instance().GetTheme());
    //Controller::StyleController::Instance().DarkThemeStatus(theme.compare("Dark", Qt::CaseInsensitive) == 0);

    // === Carregar Tradução ===
    QTranslator translator;
    QString translationFile;

    QMap<Controller::ELanguages, QString> translationMap = {
        { Controller::ELanguages::Portuguese, ":/Translations/TrimSheet_ToolsV2_pt_BR.qm" },
        { Controller::ELanguages::Spanish,    ":/Translations/TrimSheet_ToolsV2_es_ES.qm" },
        { Controller::ELanguages::Chinese,    ":/Translations/TrimSheet_ToolsV2_zh_CN.qm" }
    };

    translationFile = translationMap.value(Controller::InitiallizationConfig::Instance().GetLanguage(), "");
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
