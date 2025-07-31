#include "Settings.h"
#include "ui_Settings.h"

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
    _styleControllerComponent.DarkThemeStatus(true);
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
    _styleControllerComponent.ApplyStyle(this, Controller::WindowBackground);

    // Labels
    _styleControllerComponent.ApplyStyle(ui->themeTitle_Label, Controller::TitleLabel);
    _styleControllerComponent.ApplyStyle(ui->languageTitle_Label, Controller::TitleLabel);

    // ComboBox
    _styleControllerComponent.ApplyStyle(ui->theme_ComboBox, Controller::ComboBox);
    _styleControllerComponent.ApplyStyle(ui->language_ComboBox, Controller::ComboBox);

    // Buttons
    _styleControllerComponent.ApplyStyle(ui->buttonBox, Controller::NormalButton);
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

    okButton->setText(tr("Ok"));
    cancelButton->setText(tr("Cancel"));
}


// Event Methods
void Settings::on_buttonBox_accepted()
{

}

void Settings::on_buttonBox_rejected()
{

}
}
