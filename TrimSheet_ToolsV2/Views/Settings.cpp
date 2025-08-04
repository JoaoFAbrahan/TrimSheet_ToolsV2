#include "Settings.h"
#include "ui_Settings.h"
#include "pch.h"

namespace View {
Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);

    // Initialize
    this->setWindowIcon(QIcon(":/Icons/Settings.ico"));
    this->setWindowTitle(tr("Settings"));
}

Settings::~Settings()
{   delete ui; }

void Settings::Init()
{
    // Set Style
    StartLabels();
    StartStyleTheme();
    StartIcons();

    this->update();
    qApp->processEvents();
}

// Methods
void Settings::StartStyleTheme()
{
    // Form
    Controller::StyleController::Instance().ApplyStyle(this, Controller::WindowBackground);

    // Labels
    Controller::StyleController::Instance().ApplyStyle(ui->themeTitle_Label, Controller::TitleLabel);
    Controller::StyleController::Instance().ApplyStyle(ui->languageTitle_Label, Controller::TitleLabel);

    // ComboBox
    Controller::StyleController::Instance().ApplyStyle(ui->theme_ComboBox, Controller::ComboBox);
    Controller::StyleController::Instance().ApplyStyle(ui->language_ComboBox, Controller::ComboBox);

    // Buttons
    Controller::StyleController::Instance().ApplyStyle(ui->buttonBox, Controller::NormalButton);
}
void Settings::StartIcons()
{}
void Settings::StartLabels()
{
    // Labels
    ui->themeTitle_Label->setText(tr("Theme:"));
    ui->languageTitle_Label->setText(tr("Language:"));

    // Buttons
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    QPushButton *cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);

    okButton->setText(tr("Apply"));
    cancelButton->setText(tr("Cancel"));
}

void Settings::applySettings()
{

}


// Event Methods
void Settings::on_buttonBox_accepted()
{
    QMessageBox msgBox(this);

    msgBox.setWindowTitle(tr("Restart Required"));
    msgBox.setText(tr("You need to restart the program to apply the settings. Do you want to restart the software?"));
    msgBox.setIcon(QMessageBox::Warning);

    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Apply Style
    Controller::StyleController::Instance().ApplyMessageBoxStyle(&msgBox);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Ok) {
        // Reboot Confirm
        applySettings();
    } else {
        // Apply Settings Cancel
        return;
    }
}

void Settings::on_buttonBox_rejected()
{

}
}
