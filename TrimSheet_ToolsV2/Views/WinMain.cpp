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

    // Set Style
    _styleControllerComponent.DarkThemeStatus(_isDarktheme);
    SetStyleThemeSelected();
    SetMenuButtonsGroups();
}

WinMain::~WinMain()
{   delete ui;  }

// Methods
void WinMain::SetStyleThemeSelected()
{
    // Form
    _styleControllerComponent.ApplyStyle(this, Controller::WindowBackground);

    // Panels
    _styleControllerComponent.ApplyStyle(ui->MainMenu_Panel_Undocked, Controller::MainMenuPanel);
    _styleControllerComponent.ApplyStyle(ui->MainMenu_Panel_Docked, Controller::MainMenuPanel);

    // Menu Buttons Style
    _styleControllerComponent.ApplyStyle(ui->menu_Btn, Controller::MenuDockButton);
    _styleControllerComponent.ApplyStyle(ui->menu_Btn_2, Controller::MenuDockButton);
    _styleControllerComponent.ApplyStyle(ui->trimPlanning_Btn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->trimPlanning_DockBtn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->uvCalculate_Btn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->uvCalculate_DockBtn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->helpInfo_Btn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->helpInfo_DockBtn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->settings_Btn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->settings_DockBtn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->about_Btn, Controller::MenuButton);
    _styleControllerComponent.ApplyStyle(ui->about_DockBtn, Controller::MenuButton);

    // Toggle Switch Button
    ui->alwaysOnTop_Chk->SetColor(QColor("#5441F6"),QColor("#0f1011"),QColor("#ffffff"),QColor("#ffffff"));
    ui->alwaysOnTop_DockChk->SetColor(QColor("#5441F6"),QColor("#0f1011"),QColor("#ffffff"),QColor("#ffffff"));
    connect(ui->alwaysOnTop_Chk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_DockChk, &View::ToggleSwitch::setChecked);
    connect(ui->alwaysOnTop_DockChk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_Chk, &View::ToggleSwitch::setChecked);

    // Menu Buttons Icons
    SetMenuButtonIcons();
}

void WinMain::SetMenuButtonIcons()
{
    // Menu Buttons Icons
    if(_isDarktheme)
    {
        // Dock Button
        ui->menu_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            30
        );
        ui->menu_Btn_2->SetStateIcons(
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            QPixmap(":/Icons/DK_Menu_Icon.png"),
            30
        );

        // TrimPlanning Btn
        ui->trimPlanning_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_TrimPlanning_IconIdle.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/DK_TrimPlanning_IconDisable.png"),
            30
        );
        ui->trimPlanning_DockBtn->SetStateIcons(
            QPixmap(":/Icons/DK_TrimPlanning_IconIdle.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/DK_TrimPlanning_IconDisable.png"),
            30
        );

        // UV Calculate
        ui->uvCalculate_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_UVCalculate_IconIdle.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/DK_UVCalculate_IconDisable.png"),
            30
        );
        ui->uvCalculate_DockBtn->SetStateIcons(
            QPixmap(":/Icons/DK_UVCalculate_IconIdle.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/DK_UVCalculate_IconDisable.png"),
            30
        );

        // HelpInform Btn
        ui->helpInfo_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_HelpInfo_IconIdle.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/DK_HelpInfo_IconDisable.png"),
            30
        );
        ui->helpInfo_DockBtn->SetStateIcons(
            QPixmap(":/Icons/DK_HelpInfo_IconIdle.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/DK_HelpInfo_IconDisable.png"),
            30
        );

        // Settings Btn
        ui->settings_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_Settings_IconIdle.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/DK_Settings_IconDisable.png"),
            30
        );
        ui->settings_DockBtn->SetStateIcons(
            QPixmap(":/Icons/DK_Settings_IconIdle.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/DK_Settings_IconDisable.png"),
            30
        );

        // About Btn
        ui->about_Btn->SetStateIcons(
            QPixmap(":/Icons/DK_About_IconIdle.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/DK_About_IconDisable.png"),
            30
        );
        ui->about_DockBtn->SetStateIcons(
            QPixmap(":/Icons/DK_About_IconIdle.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/DK_About_IconDisable.png"),
            30
        );
    }
    else
    {
        // Dock Button
        ui->menu_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            30
            );
        ui->menu_Btn_2->SetStateIcons(
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            QPixmap(":/Icons/LG_Menu_Icon.png"),
            30
            );

        // TrimPlanning Btn
        ui->trimPlanning_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_TrimPlanning_IconIdle.png"),
            QPixmap(":/Icons/DK_TrimPlanning_IconIdle.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/LG_TrimPlanning_IconDisable.png"),
            30
            );
        ui->trimPlanning_DockBtn->SetStateIcons(
            QPixmap(":/Icons/LG_TrimPlanning_IconIdle.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/TrimPlanning_IconPressed.png"),
            QPixmap(":/Icons/LG_TrimPlanning_IconDisable.png"),
            30
            );

        // UV Calculate
        ui->uvCalculate_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_UVCalculate_IconIdle.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/LG_UVCalculate_IconDisable.png"),
            30
            );
        ui->uvCalculate_DockBtn->SetStateIcons(
            QPixmap(":/Icons/LG_UVCalculate_IconIdle.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/UVCalculate_IconPressed.png"),
            QPixmap(":/Icons/LG_UVCalculate_IconDisable.png"),
            30
            );

        // HelpInform Btn
        ui->helpInfo_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_HelpInfo_IconIdle.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/LG_HelpInfo_IconDisable.png"),
            30
            );
        ui->helpInfo_DockBtn->SetStateIcons(
            QPixmap(":/Icons/LG_HelpInfo_IconIdle.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/HelpInfo_IconPressed.png"),
            QPixmap(":/Icons/LG_HelpInfo_IconDisable.png"),
            30
            );

        // Settings Btn
        ui->settings_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_Settings_IconIdle.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/LG_Settings_IconDisable.png"),
            30
            );
        ui->settings_DockBtn->SetStateIcons(
            QPixmap(":/Icons/LG_Settings_IconIdle.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/Settings_IconPressed.png"),
            QPixmap(":/Icons/LG_Settings_IconDisable.png"),
            30
            );

        // About Btn
        ui->about_Btn->SetStateIcons(
            QPixmap(":/Icons/LG_About_IconIdle.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/LG_About_IconDisable.png"),
            30
            );
        ui->about_DockBtn->SetStateIcons(
            QPixmap(":/Icons/LG_About_IconIdle.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/About_IconPressed.png"),
            QPixmap(":/Icons/LG_About_IconDisable.png"),
            30
            );
    }
}

void WinMain::SetMenuButtonsGroups()
{
    // Menu Button Group
    _buttonUndockedGroupList.setExclusive(true);
    _buttonDockedGroupList.setExclusive(true);

    // Undocked
    _buttonUndockedGroupList.addButton(ui->trimPlanning_Btn);
    _buttonUndockedGroupList.addButton(ui->uvCalculate_Btn);
    _buttonUndockedGroupList.addButton(ui->helpInfo_Btn);
    _buttonUndockedGroupList.addButton(ui->settings_Btn);
    _buttonUndockedGroupList.addButton(ui->about_Btn);

    // Docked
    _buttonDockedGroupList.addButton(ui->trimPlanning_DockBtn);
    _buttonDockedGroupList.addButton(ui->uvCalculate_DockBtn);
    _buttonDockedGroupList.addButton(ui->helpInfo_DockBtn);
    _buttonDockedGroupList.addButton(ui->settings_DockBtn);
    _buttonDockedGroupList.addButton(ui->about_DockBtn);
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
