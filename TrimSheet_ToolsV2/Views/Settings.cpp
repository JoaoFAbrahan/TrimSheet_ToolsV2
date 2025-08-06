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

    // Initialize
    ui->language_ComboBox->setCurrentIndex(static_cast<int>(Controller::InitializationConfig::Instance().GetLanguage()));
    ui->theme_ComboBox->setCurrentIndex(static_cast<int>(Controller::InitializationConfig::Instance().GetTheme()));

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
void Settings::StartIcons() {}
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
    // Set new settings
    QString configPath = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);

    settings.setValue("Theme", ui->theme_ComboBox->currentIndex());
    settings.setValue("Language", ui->language_ComboBox->currentIndex());

    // Restart the application
    QString exePath = QCoreApplication::applicationFilePath();
    QProcess::startDetached(exePath);
    QCoreApplication::quit();
}


// Event Methods
void Settings::on_buttonBox_accepted()
{
    // Create a MessageBox
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

void Settings::on_buttonBox_rejected() {}
}
