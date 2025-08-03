#include "Views/WinMain.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QSettings>
#include <QDir>

#include "StyleController.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // === Leitura do arquivo config.ini ===
    QString configPath = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);
    QString theme = settings.value("General/Theme", "Dark").toString();
    QString language = settings.value("General/Language", "English").toString();

    // === Aplicar Tema ===
    theme = "Light";
    Controller::StyleController::Instance().DarkThemeStatus(theme.compare("Dark", Qt::CaseInsensitive) == 0);

    // === Carregar Tradução ===
    QTranslator translator;
    QString translationFile;
    language = "Spanish";

    QMap<QString, QString> translationMap = {
        { "Portuguese", ":/Translations/TrimSheet_ToolsV2_pt_BR.qm" },
        { "Spanish",    ":/Translations/TrimSheet_ToolsV2_es_ES.qm" },
        { "Chinese",    ":/Translations/TrimSheet_ToolsV2_zh_CN.qm" }
    };

    translationFile = translationMap.value(language, ""); // "" se for "English" (padrão)
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
