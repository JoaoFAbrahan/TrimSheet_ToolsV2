#ifndef STYLECONTROLLER_H
#define STYLECONTROLLER_H

#include <QWidget>
#include <QFile>
#include <SStyleComponents.h>
#include <EStyleObjects.h>

using namespace Model;

namespace Controller {
class StyleController
{
    // Class variables
private:
    QVector<QString> _darkThemes;
    QVector<QString> _lightThemes;
    SStyleComponents _styles;
    bool _isDarkTheme;

    // Constructor
public:
    StyleController();


    // Methods
public:
    void DarkThemeStatus(bool status);
    void ApplyStyle(QWidget *objRef, EStyleObjects objTypeRef);

private:
    void LoadThemesFromQSS();
};
}
#endif // STYLECONTROLLER_H
