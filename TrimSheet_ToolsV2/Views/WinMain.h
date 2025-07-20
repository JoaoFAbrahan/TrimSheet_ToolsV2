#ifndef WINMAIN_H
#define WINMAIN_H

#include <QMainWindow>
#include <QButtonGroup>
#include <CustomPushButton.h>

using namespace View;

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
    QString menuButtonStyle = ":/Styles/Style_MainMenu_Button.qss"; // Set Menu Button Style
    QButtonGroup *_buttonUndockedGroupList;
    QButtonGroup *_buttonDockedGroupList;

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
    void SetButtonsStyle();
    void LinkButtonState(CustomPushButton *a, CustomPushButton *b);
};
}
#endif // WINMAIN_H
