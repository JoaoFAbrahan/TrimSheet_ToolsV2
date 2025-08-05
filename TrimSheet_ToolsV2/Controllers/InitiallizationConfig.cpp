#include "InitiallizationConfig.h"
#include "pch.h"

namespace Controller {
bool Controller::InitiallizationConfig::_theme = true;
ELanguages Controller::InitiallizationConfig::_language = ELanguages::English;

InitiallizationConfig &InitiallizationConfig::Instance()
{
    static InitiallizationConfig instance;
    return instance;
}

InitiallizationConfig::InitiallizationConfig() {}


// Methods
void Controller::InitiallizationConfig::SetTheme(bool themeRef)
{   _theme = themeRef;  }

void Controller::InitiallizationConfig::SetLanguage(ELanguages languageRef)
{   _language = languageRef;    }

bool Controller::InitiallizationConfig::GetTheme()
{   return _theme;  }

Controller::ELanguages Controller::InitiallizationConfig::GetLanguage()
{   return _language;   }
}
