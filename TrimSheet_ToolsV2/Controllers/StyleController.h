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
    // Class variables
private:
    static bool _isDarkTheme;
    static QVector<QString> _darkThemes;
    static QVector<QString> _lightThemes;
    SStyleComponents _styles;


    // Singleton Pattern
private:
    StyleController(); // Construtor privado
    StyleController(const StyleController&) = delete;            // Impede cópia
    StyleController& operator=(const StyleController&) = delete;

    // Constructor
public:
    static StyleController& Instance(); // Acesso ao Singleton


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
