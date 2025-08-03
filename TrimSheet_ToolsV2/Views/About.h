#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QTranslator>
#include <StyleController.h>
#include <EStyleObjects.h>
#include <IStartComponent.h>

using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class About;
}
QT_END_NAMESPACE

namespace View {
class About : public QDialog, public IStartComponent
{
    Q_OBJECT

    // Class Variables
private:
    // Style Theme and UI Components


    // Constructor
public:
    explicit About(QWidget *parent = nullptr);
    ~About();
    void Init();


    // Methods
private:
    Ui::About *ui;


    // IStartComponent interface
public:
    void StartStyleTheme();
    void StartIcons();
    void StartLabels();
};
}
#endif // ABOUT_H
