/*
    This class is a singleton designed to control and verify the information retrieved from the config.ini file.
    Variables mebers:
    - bool _theme
    - ELanguage _language
    - QString _version

    Associated files:
    - Controllers/Components/ELanguage
*/
#ifndef INITIALIZATIONCONFIG_H
#define INITIALIZATIONCONFIG_H

#include <QString>
#include <ELanguages.h>

namespace Controller {
class InitializationConfig
{
    // Class Variables
private:
    static bool _theme;
    static ELanguages _language;
    static QString _version;


    // Singleton Pattern
private:
    InitializationConfig();
    InitializationConfig(const InitializationConfig&) = delete;
    InitializationConfig& operator=(const InitializationConfig&) = delete;

    // Constructor
public:
    static InitializationConfig& Instance();


    // Methods
public:
    void SetTheme(bool themeRef);
    void SetLanguage(ELanguages languageRef);
    void SetVersion(QString versionNumber);
    bool GetTheme();
    ELanguages GetLanguage();
    QString GetVersion();
};
}
#endif // INITIALIZATIONCONFIG_H
