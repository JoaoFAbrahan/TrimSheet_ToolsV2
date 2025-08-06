/*
    This class manages the control and application of .qss StyleSheet components
    Associated files:
    - Controllers/Components/EStyleObjects
    - Models/SStyleComponents
*/
#ifndef STYLECONTROLLER_H
#define STYLECONTROLLER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <SStyleComponents.h>
#include <EStyleObjects.h>

using namespace Model;

namespace Controller {
class StyleController
{
    // Class Variables
private:
    static bool _isDarkTheme;
    static QVector<QString> _darkThemes;
    static QVector<QString> _lightThemes;
    SStyleComponents _styles;


    // Singleton Pattern
private:
    StyleController();
    StyleController(const StyleController&) = delete;
    StyleController& operator=(const StyleController&) = delete;

    // Constructor
public:
    static StyleController& Instance();


    // Methods
public:
    void DarkThemeStatus(bool status);
    bool GetThemeStatus();
    void ApplyStyle(QWidget *objRef, EStyleObjects objTypeRef);
    void ApplyMessageBoxStyle(QMessageBox *msgBoxRef);

private:
    void LoadThemesFromQSS();
};
}
#endif // STYLECONTROLLER_H
