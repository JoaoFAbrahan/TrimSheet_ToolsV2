#include "InitializationConfig.h"
#include "pch.h"

namespace Controller {
// Static variables initialization
bool Controller::InitializationConfig::_theme = true;
ELanguages Controller::InitializationConfig::_language = ELanguages::English;
QString Controller::InitializationConfig::_version = "0.1.15 (Build XX 20XX)";

InitializationConfig::InitializationConfig() {}

InitializationConfig &InitializationConfig::Instance()
{
    static InitializationConfig instance;
    return instance;
}


// Methods
void Controller::InitializationConfig::SetTheme(bool themeRef)
{   _theme = themeRef;  }

void Controller::InitializationConfig::SetLanguage(ELanguages languageRef)
{   _language = languageRef;    }

void InitializationConfig::SetVersion(QString versionNumber)
{
    _version = versionNumber;
}

bool Controller::InitializationConfig::GetTheme()
{   return _theme;  }

Controller::ELanguages Controller::InitializationConfig::GetLanguage()
{   return _language;   }

QString InitializationConfig::GetVersion()
{   return _version;    }
}
