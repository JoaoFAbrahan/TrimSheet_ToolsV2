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
    connect(ui->alwaysOnTop_Chk, &View::ToggleSwitch::toggled, this, &View::WinMain::on_alwaysOnTop_Chk_toggled);
    connect(ui->alwaysOnTop_DockChk, &View::ToggleSwitch::toggled, this, &View::WinMain::on_alwaysOnTop_Chk_toggled);

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
    ui->alwaysOnTop_Chk->SetColor(QColor(84, 65, 246),QColor(15, 16, 17),QColor(245, 245, 245),QColor(245, 245, 245));
    ui->alwaysOnTop_DockChk->SetColor(QColor(84, 65, 246),QColor(15, 16, 17),QColor(245, 245, 245),QColor(245, 245, 245));
    connect(ui->alwaysOnTop_Chk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_DockChk, &View::ToggleSwitch::setChecked);
    connect(ui->alwaysOnTop_DockChk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_Chk, &View::ToggleSwitch::setChecked);

    // Set Label
    _styleControllerComponent.ApplyStyle(ui->alwaysOnTop_Label, Controller::NormalLabel);

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
            ":/Icons/Menu_Icon.svg",
            ":/Icons/Menu_Icon.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->menu_Btn_2->SetStateIcons(
            ":/Icons/Menu_Icon.svg",
            ":/Icons/Menu_Icon.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );

        // TrimPlanning Btn
        ui->trimPlanning_Btn->SetStateIcons(
            ":/Icons/TrimPlanning_Idle.svg",
            ":/Icons/TrimPlanning_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->trimPlanning_DockBtn->SetStateIcons(
            ":/Icons/TrimPlanning_Idle.svg",
            ":/Icons/TrimPlanning_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );

        // UV Calculate
        ui->uvCalculate_Btn->SetStateIcons(
            ":/Icons/UVCalculate_Idle.svg",
            ":/Icons/UVCalculate_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->uvCalculate_DockBtn->SetStateIcons(
            ":/Icons/UVCalculate_Idle.svg",
            ":/Icons/UVCalculate_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );

        // HelpInform Btn
        ui->helpInfo_Btn->SetStateIcons(
            ":/Icons/HelpInfo_Idle.svg",
            ":/Icons/HelpInfo_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->helpInfo_DockBtn->SetStateIcons(
            ":/Icons/HelpInfo_Idle.svg",
            ":/Icons/HelpInfo_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );

        // Settings Btn
        ui->settings_Btn->SetStateIcons(
            ":/Icons/Settings_Idle.svg",
            ":/Icons/Settings_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->settings_DockBtn->SetStateIcons(
            ":/Icons/Settings_Idle.svg",
            ":/Icons/Settings_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );

        // About Btn
        ui->about_Btn->SetStateIcons(
            ":/Icons/About_Idle.svg",
            ":/Icons/About_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
        ui->about_DockBtn->SetStateIcons(
            ":/Icons/About_Idle.svg",
            ":/Icons/About_Pressed.svg",
            QColor(245, 245, 245),
            QColor(245, 245, 245),
            QColor(51, 51, 51),
            30
        );
    }
    else
    {
        // Dock Button
        ui->menu_Btn->SetStateIcons(
            ":/Icons/Menu_Icon.svg",
            ":/Icons/Menu_Icon.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->menu_Btn_2->SetStateIcons(
            ":/Icons/Menu_Icon.svg",
            ":/Icons/Menu_Icon.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );

        // TrimPlanning Btn
        ui->trimPlanning_Btn->SetStateIcons(
            ":/Icons/TrimPlanning_Idle.svg",
            ":/Icons/TrimPlanning_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->trimPlanning_DockBtn->SetStateIcons(
            ":/Icons/TrimPlanning_Idle.svg",
            ":/Icons/TrimPlanning_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );

        // UV Calculate
        ui->uvCalculate_Btn->SetStateIcons(
            ":/Icons/UVCalculate_Idle.svg",
            ":/Icons/UVCalculate_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->uvCalculate_DockBtn->SetStateIcons(
            ":/Icons/UVCalculate_Idle.svg",
            ":/Icons/UVCalculate_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );

        // HelpInform Btn
        ui->helpInfo_Btn->SetStateIcons(
            ":/Icons/HelpInfo_Idle.svg",
            ":/Icons/HelpInfo_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->helpInfo_DockBtn->SetStateIcons(
            ":/Icons/HelpInfo_Idle.svg",
            ":/Icons/HelpInfo_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );

        // Settings Btn
        ui->settings_Btn->SetStateIcons(
            ":/Icons/Settings_Idle.svg",
            ":/Icons/Settings_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->settings_DockBtn->SetStateIcons(
            ":/Icons/Settings_Idle.svg",
            ":/Icons/Settings_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );

        // About Btn
        ui->about_Btn->SetStateIcons(
            ":/Icons/About_Idle.svg",
            ":/Icons/About_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
            30
        );
        ui->about_DockBtn->SetStateIcons(
            ":/Icons/About_Idle.svg",
            ":/Icons/About_Pressed.svg",
            QColor(10, 20, 42),
            QColor(245, 245, 245),
            QColor(230, 230, 230),
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

void WinMain::on_settings_Btn_clicked()
{

}

void WinMain::on_about_Btn_clicked()
{

}

void WinMain::on_alwaysOnTop_Chk_toggled(bool checked)
{
    // Apply Aways on Top condition
    setWindowFlag(Qt::WindowStaysOnTopHint, checked);
    show();
}


}
