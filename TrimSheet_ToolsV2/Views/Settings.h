#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
/*
    Settings form containing the system for writing values to the config.ini file.
*/
#include <QDialog>
#include <QMessageBox>
#include <QTranslator>
#include <QProcess>
#include <StyleController.h>
#include <EStyleObjects.h>
#include <IStartComponent.h>
#include <InitializationConfig.h>
#include <ELanguages.h>

using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class Settings;
}
QT_END_NAMESPACE

namespace View {
class Settings : public QDialog, public IStartComponent
{
    Q_OBJECT

    // Class Variables
private:


    // Constructor
public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    void Init();


    // Events
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();


    // Methods
private:
    Ui::Settings *ui;
    void applySettings();


    // IStartComponent interface
public:
    void StartStyleTheme();
    void StartIcons();
    void StartLabels();
};
}
#endif // SETTINGS_H
