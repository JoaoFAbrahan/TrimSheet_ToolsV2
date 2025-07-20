#include "WinMain.h"
#include "./ui_WinMain.h"


namespace View {
WinMain::WinMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinMain)
{
    ui->setupUi(this);

    // Initialize
    this->setWindowIcon(QIcon(":/Icons/Icon.ico"));
    ui->MainMenu_Panel_Undocked->setVisible(true);
    ui->MainMenu_Panel_Docked->setVisible(false);
    _buttonUndockedGroupList = new QButtonGroup();
    _buttonDockedGroupList = new QButtonGroup();

    // Set Style
    SetButtonsStyle();
}

WinMain::~WinMain()
{
    delete ui;
}

// Methods
void WinMain::SetButtonsStyle()
{
    // Menu Buttons Style
    ui->trimPlanning_Btn->SetStyle(menuButtonStyle, true);
    ui->trimPlanning_DockBtn->SetStyle(menuButtonStyle, true);
    ui->uvCalculate_Btn->SetStyle(menuButtonStyle, true);
    ui->uvCalculate_DockBtn->SetStyle(menuButtonStyle, true);
    ui->helpInfo_Btn->SetStyle(menuButtonStyle, true);
    ui->helpInfo_DockBtn->SetStyle(menuButtonStyle, true);
    ui->settings_Btn->SetStyle(menuButtonStyle, true);
    ui->settings_DockBtn->SetStyle(menuButtonStyle, true);
    ui->about_Btn->SetStyle(menuButtonStyle, true);
    ui->about_DockBtn->SetStyle(menuButtonStyle, true);

    // Menu Buttons Icons
    // TrimPlanning Btn
    ui->trimPlanning_Btn->SetStateIcons(
        QPixmap(":/Icons/TrimSettings_IconIdle.png"),
        QPixmap(":/Icons/TrimSettings_IconPressed.png"),
        QPixmap(":/Icons/TrimSettings_IconDisable.png"),
        30
    );
    ui->trimPlanning_DockBtn->SetStateIcons(
        QPixmap(":/Icons/TrimSettings_IconIdle.png"),
        QPixmap(":/Icons/TrimSettings_IconPressed.png"),
        QPixmap(":/Icons/TrimSettings_IconDisable.png"),
        30
    );

    // UV Calculate
    ui->uvCalculate_Btn->SetStateIcons(
        QPixmap(":/Icons/UVPlanning_IconIdle.png"),
        QPixmap(":/Icons/UVPlanning_IconPressed.png"),
        QPixmap(":/Icons/UVPlanning_IconDisable.png"),
        30
    );
    ui->uvCalculate_DockBtn->SetStateIcons(
        QPixmap(":/Icons/UVPlanning_IconIdle.png"),
        QPixmap(":/Icons/UVPlanning_IconPressed.png"),
        QPixmap(":/Icons/UVPlanning_IconDisable.png"),
        30
    );

    // HelpInform Btn
    ui->helpInfo_Btn->SetStateIcons(
        QPixmap(":/Icons/HelpInfo_IconIdle.png"),
        QPixmap(":/Icons/HelpInfo_IconPressed.png"),
        QPixmap(":/Icons/HelpInfo_IconDisable.png"),
        30
    );
    ui->helpInfo_DockBtn->SetStateIcons(
        QPixmap(":/Icons/HelpInfo_IconIdle.png"),
        QPixmap(":/Icons/HelpInfo_IconPressed.png"),
        QPixmap(":/Icons/HelpInfo_IconDisable.png"),
        30
    );

    // Settings Btn
    ui->settings_Btn->SetStateIcons(
        QPixmap(":/Icons/Settings_IconIdle.png"),
        QPixmap(":/Icons/Settings_IconPressed.png"),
        QPixmap(":/Icons/Settings_IconDisable.png"),
        30
    );
    ui->settings_DockBtn->SetStateIcons(
        QPixmap(":/Icons/Settings_IconIdle.png"),
        QPixmap(":/Icons/Settings_IconPressed.png"),
        QPixmap(":/Icons/Settings_IconDisable.png"),
        30
    );

    // About Btn
    ui->about_Btn->SetStateIcons(
        QPixmap(":/Icons/About_IconIdle.png"),
        QPixmap(":/Icons/About_IconPressed.png"),
        QPixmap(":/Icons/About_IconDisable.png"),
        30
    );
    ui->about_DockBtn->SetStateIcons(
        QPixmap(":/Icons/About_IconIdle.png"),
        QPixmap(":/Icons/About_IconPressed.png"),
        QPixmap(":/Icons/About_IconDisable.png"),
        30
    );

    // Menu Button Group
    _buttonUndockedGroupList->setExclusive(true);
    _buttonDockedGroupList->setExclusive(true);

    // Undocked
    _buttonUndockedGroupList->addButton(ui->trimPlanning_Btn);
    _buttonUndockedGroupList->addButton(ui->uvCalculate_Btn);
    _buttonUndockedGroupList->addButton(ui->helpInfo_Btn);
    _buttonUndockedGroupList->addButton(ui->settings_Btn);
    _buttonUndockedGroupList->addButton(ui->about_Btn);

    // Docked
    _buttonDockedGroupList->addButton(ui->trimPlanning_DockBtn);
    _buttonDockedGroupList->addButton(ui->uvCalculate_DockBtn);
    _buttonDockedGroupList->addButton(ui->helpInfo_DockBtn);
    _buttonDockedGroupList->addButton(ui->settings_DockBtn);
    _buttonDockedGroupList->addButton(ui->about_DockBtn);
}

// Events Methods
void WinMain::on_menu_Btn_clicked()
{
    ui->MainMenu_Panel_Docked->setVisible(true);
    ui->MainMenu_Panel_Undocked->setVisible(false);
}

void WinMain::on_menu_Btn_2_clicked()
{
    ui->MainMenu_Panel_Docked->setVisible(false);
    ui->MainMenu_Panel_Undocked->setVisible(true);
}




}
