#ifndef WINMAIN_H
#define WINMAIN_H

#include <QMainWindow>
#include <QButtonGroup>
#include <CustomPushButton.h>
#include <StyleController.h>
#include <EStyleObjects.h>

using namespace View;
using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class WinMain;
}
QT_END_NAMESPACE

namespace View {
class WinMain : public QMainWindow
{
    Q_OBJECT

    // Class Variables
private:
    StyleController _styleControllerComponent;
    bool _isDarktheme = false;
    QButtonGroup _buttonUndockedGroupList;
    QButtonGroup _buttonDockedGroupList;

    // Constructor
public:
    WinMain(QWidget *parent = nullptr);
    ~WinMain();


    // Events
private slots:
    void on_menu_Btn_clicked();
    void on_menu_Btn_2_clicked();


    // Methods
private:
    Ui::WinMain *ui;
    void SetStyleThemeSelected();
    void SetMenuButtonIcons();
    void SetMenuButtonsGroups();

};
}
#endif // WINMAIN_H
