/*
    About form containing all information about the software such as version, licensing, and GitHub repository.
*/
#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QTranslator>
#include <StyleController.h>
#include <EStyleObjects.h>
#include <IStartComponent.h>
#include <InitializationConfig.h>

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
