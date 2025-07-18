#ifndef WINMAIN_H
#define WINMAIN_H

#include <QMainWindow>
#include <Components/CustomPushButton.h>

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

    // Constructor
public:
    WinMain(QWidget *parent = nullptr);
    ~WinMain();


    // Methods
private:    
    Ui::WinMain *ui;
    void SetButtonsStyle();
};
}
#endif // WINMAIN_H
