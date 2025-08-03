#ifndef WINMAIN_H
#define WINMAIN_H

#include <QMainWindow>
#include <QTranslator>
#include <QButtonGroup>
#include <CustomPushButton.h>
#include <StyleController.h>
#include <EStyleObjects.h>
#include <IStartComponent.h>

#include <Settings.h>
#include <About.h>

using namespace View;
using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class WinMain;
}
QT_END_NAMESPACE

namespace View {
class WinMain : public QMainWindow, public IStartComponent
{
    Q_OBJECT

    // Class Variables
private:
    // Style Theme and UI Components
    QButtonGroup _buttonUndockedGroupList;
    QButtonGroup _buttonDockedGroupList;

    // Features
    Settings *_settingsForm = nullptr;
    About *_aboutForm = nullptr;


    // Constructor
public:
    WinMain(QWidget *parent = nullptr);
    ~WinMain();
    void Init();


    // Events
private slots:
    void on_menu_Btn_clicked();
    void on_menu_Btn_2_clicked();
    void on_trimPlanning_Btn_clicked();
    void on_uvCalculate_Btn_clicked();
    void on_helpInfo_Btn_clicked();
    void on_settings_Btn_clicked();
    void on_about_Btn_clicked();
    void on_alwaysOnTop_Chk_toggled(bool checked);


    // Methods
private:
    Ui::WinMain *ui;
    void SetMenuButtonsGroups();


    // IStartComponent interface
public:
    void StartStyleTheme() override;
    void StartIcons() override;
    void StartLabels() override;
};
}
#endif // WINMAIN_H
