#ifndef WINMAIN_H
#define WINMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class WinMain;
}
QT_END_NAMESPACE

class WinMain : public QMainWindow
{
    Q_OBJECT

public:
    WinMain(QWidget *parent = nullptr);
    ~WinMain();

private:
    Ui::WinMain *ui;
};
#endif // WINMAIN_H
