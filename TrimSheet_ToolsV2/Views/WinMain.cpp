#include "WinMain.h"
#include "./ui_WinMain.h"


namespace View {
WinMain::WinMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinMain)
{
    ui->setupUi(this);

    // Set Style
    SetButtonsStyle();
}

WinMain::~WinMain()
{
    delete ui;
}

void WinMain::SetButtonsStyle()
{
    // Menu buttons
    // TrimPlanning Btn
    ui->trimPlanning_Btn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/TrimSettings_IconIdle.png"),
        QIcon(":/Icons/TrimSettings_IconPressed.png"),
        QIcon(":/Icons/TrimSettings_IconDisable.png"),
        30
    );
    ui->trimPlanning_DockBtn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/TrimSettings_IconIdle.png"),
        QIcon(":/Icons/TrimSettings_IconPressed.png"),
        QIcon(":/Icons/TrimSettings_IconDisable.png"),
        30
    );

    // UV Calculate
    ui->uvCalculate_Btn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/UVPlanning_IconIdle.png"),
        QIcon(":/Icons/UVPlanning_IconPressed.png"),
        QIcon(":/Icons/UVPlanning_IconDisable.png"),
        30
    );
    ui->uvCalculate_DockBtn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/UVPlanning_IconIdle.png"),
        QIcon(":/Icons/UVPlanning_IconPressed.png"),
        QIcon(":/Icons/UVPlanning_IconDisable.png"),
        30
    );

    // HelpInform Btn
    ui->helpInfo_Btn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/HelpInfo_IconIdle.png"),
        QIcon(":/Icons/HelpInfo_IconPressed.png"),
        QIcon(":/Icons/HelpInfo_IconDisable.png"),
        30
    );
    ui->helpInfo_DockBtn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/HelpInfo_IconIdle.png"),
        QIcon(":/Icons/HelpInfo_IconPressed.png"),
        QIcon(":/Icons/HelpInfo_IconDisable.png"),
        30
    );

    // Settings Btn
    ui->settings_Btn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/Settings_IconIdle.png"),
        QIcon(":/Icons/Settings_IconPressed.png"),
        QIcon(":/Icons/Settings_IconDisable.png"),
        30
    );
    ui->settings_DockBtn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/Settings_IconIdle.png"),
        QIcon(":/Icons/Settings_IconPressed.png"),
        QIcon(":/Icons/Settings_IconDisable.png"),
        30
    );

    // About Btn
    ui->about_Btn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/About_IconIdle.png"),
        QIcon(":/Icons/About_IconPressed.png"),
        QIcon(":/Icons/About_IconDisable.png"),
        30
    );
    ui->about_DockBtn->SetStateIcons(
        menuButtonStyle,
        QIcon(":/Icons/About_IconIdle.png"),
        QIcon(":/Icons/About_IconPressed.png"),
        QIcon(":/Icons/About_IconDisable.png"),
        30
    );
}
}
