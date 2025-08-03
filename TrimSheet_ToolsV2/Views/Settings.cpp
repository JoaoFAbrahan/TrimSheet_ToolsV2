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
    Controller::StyleController::Instance().ApplyStyle(ui->themeTitle_Label, Controller::NormalLabel);
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
void Settings::SetMessageBoxStyle(QMessageBox *msgBoxRef)
{
    if(Controller::StyleController::Instance().GetThemeStatus())
    {
        //Apply Dark Style
        msgBoxRef->setStyleSheet(R"(
        QDialog  {
            background-color: #0f1011;

            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Regular';
            font-size: 8pt;
            text-align: left;
        }

        /* Buttons */
        QPushButton {
            /* Shape Button */
            background-color: #645ac8;

            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Bold';
            font-size: 10pt;
            font-weight: bold;
            text-align: center;

            /* Icon Button */
            qproperty-iconSize: 30px 30px;
        }

        QPushButton:hover {
            background-color: #69b5ff;
        }

        QPushButton:pressed {
            background-color: #5441F6;
        }

        QPushButton:disabled {
            color: #333333;
            background-color: #f8f8f8;
        }
        )");
    }
    else
    {
        //Apply Light Style
        msgBoxRef->setStyleSheet(R"(
        QDialog  {
            background-color: #e8eaec;

            /* Font Button */
            color: #0a142a;
            font-family: 'MollenNarrow_Regular';
            font-size: 8pt;
            text-align: left;
        }

        /* Buttons */
        QPushButton {
            /* Shape Button */
            background-color: #645ac8;

            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Bold';
            font-size: 10pt;
            font-weight: bold;
            text-align: center;

            /* Icon Button */
            qproperty-iconSize: 30px 30px;
        }

        QPushButton:hover {
            background-color: #69b5ff;
        }

        QPushButton:pressed {
            background-color: #5441F6;
        }

        QPushButton:disabled {
            color: #333333;
            background-color: #f8f8f8;
        }
        )");
    }
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
    SetMessageBoxStyle(&msgBox);

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
