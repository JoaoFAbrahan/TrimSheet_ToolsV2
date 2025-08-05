#ifndef INITIALLIZATIONCONFIG_H
#define INITIALLIZATIONCONFIG_H

#include <QString>
#include "ELanguages.h"

namespace Controller {
class InitiallizationConfig
{
    // Class variables
private:
    static bool _theme;
    static ELanguages _language;


    // Singleton Pattern
private:
    InitiallizationConfig();
    InitiallizationConfig(const InitiallizationConfig&) = delete;
    InitiallizationConfig& operator=(const InitiallizationConfig&) = delete;

    // Constructor
public:
    static InitiallizationConfig& Instance();


    // Methods
public:
    void SetTheme(bool themeRef);
    void SetLanguage(ELanguages languageRef);
    bool GetTheme();
    ELanguages GetLanguage();

};
}
#endif // INITIALLIZATIONCONFIG_H
