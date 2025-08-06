#include "WinMain.h"
#include "./ui_WinMain.h"
#include "pch.h"

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
    _settingsForm = new Settings(this);
    _aboutForm = new About(this);

    // Connect Events
    connect(ui->trimPlanning_DockBtn, &QPushButton::clicked, this, &WinMain::on_trimPlanning_Btn_clicked);
    connect(ui->uvCalculate_DockBtn, &QPushButton::clicked, this, &WinMain::on_uvCalculate_Btn_clicked);
    connect(ui->helpInfo_DockBtn, &QPushButton::clicked, this, &WinMain::on_helpInfo_Btn_clicked);
    connect(ui->settings_DockBtn, &QPushButton::clicked, this, &WinMain::on_settings_Btn_clicked);
    connect(ui->about_DockBtn, &QPushButton::clicked, this, &WinMain::on_about_Btn_clicked);
    connect(ui->alwaysOnTop_Chk, &View::ToggleSwitch::toggled, this, &View::WinMain::on_alwaysOnTop_Chk_toggled);
    connect(ui->alwaysOnTop_DockChk, &View::ToggleSwitch::toggled, this, &View::WinMain::on_alwaysOnTop_Chk_toggled);
}

WinMain::~WinMain()
{   delete ui;  }

void WinMain::Init()
{
    // Set Style
    StartLabels();
    StartStyleTheme();
    StartIcons();
    SetMenuButtonsGroups();

    this->update();
    qApp->processEvents();

    // Set Tab Order
    setTabOrder(ui->menu_Btn, ui->trimPlanning_Btn);
    setTabOrder(ui->trimPlanning_Btn, ui->uvCalculate_Btn);
    setTabOrder(ui->uvCalculate_Btn, ui->helpInfo_Btn);
    setTabOrder(ui->helpInfo_Btn, ui->settings_Btn);
    setTabOrder(ui->settings_Btn, ui->about_Btn);
    setTabOrder(ui->about_Btn, ui->alwaysOnTop_Chk);

}


// Methods
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
void WinMain::StartStyleTheme()
{
    // Form
    Controller::StyleController::Instance().ApplyStyle(this, Controller::WindowBackground);

    // Panels
    Controller::StyleController::Instance().ApplyStyle(ui->MainMenu_Panel_Undocked, Controller::MainMenuPanel);
    Controller::StyleController::Instance().ApplyStyle(ui->MainMenu_Panel_Docked, Controller::MainMenuPanel);

    // Menu Buttons Style
    Controller::StyleController::Instance().ApplyStyle(ui->menu_Btn, Controller::MenuDockButton);
    Controller::StyleController::Instance().ApplyStyle(ui->menu_Btn_2, Controller::MenuDockButton);
    Controller::StyleController::Instance().ApplyStyle(ui->trimPlanning_Btn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->trimPlanning_DockBtn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->uvCalculate_Btn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->uvCalculate_DockBtn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->helpInfo_Btn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->helpInfo_DockBtn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->settings_Btn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->settings_DockBtn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->about_Btn, Controller::MenuButton);
    Controller::StyleController::Instance().ApplyStyle(ui->about_DockBtn, Controller::MenuButton);

    // Toggle Switch Button
    ui->alwaysOnTop_Chk->SetColor(QColor(84, 65, 246),QColor(15, 16, 17),QColor(245, 245, 245),QColor(245, 245, 245));
    ui->alwaysOnTop_DockChk->SetColor(QColor(84, 65, 246),QColor(15, 16, 17),QColor(245, 245, 245),QColor(245, 245, 245));
    connect(ui->alwaysOnTop_Chk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_DockChk, &View::ToggleSwitch::setChecked);
    connect(ui->alwaysOnTop_DockChk, &View::ToggleSwitch::toggled, ui->alwaysOnTop_Chk, &View::ToggleSwitch::setChecked);

    // Set Label
    Controller::StyleController::Instance().ApplyStyle(ui->alwaysOnTop_Label, Controller::NormalLabel);
}
void WinMain::StartIcons()
{
    // Menu Buttons Icons
    if(Controller::StyleController::Instance().GetThemeStatus())
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
void WinMain::StartLabels()
{
    ui->trimPlanning_Btn->setText(" " + tr("Trim Planning"));
    ui->uvCalculate_Btn->setText(" " + tr("UV Calculate"));
    ui->helpInfo_Btn->setText(" " + tr("Help Inform"));
    ui->settings_Btn->setText(" " + tr("Settings"));
    ui->about_Btn->setText(" " + tr("About"));
    ui->alwaysOnTop_Label->setText(" " + tr("Always on Top"));
}


// Event Methods
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

void WinMain::on_trimPlanning_Btn_clicked()
{

}

void WinMain::on_uvCalculate_Btn_clicked()
{

}

void WinMain::on_helpInfo_Btn_clicked()
{

}

void WinMain::on_settings_Btn_clicked()
{
    _settingsForm->Init();
    _settingsForm->exec();
}

void WinMain::on_about_Btn_clicked()
{
    _aboutForm->Init();
    _aboutForm->exec();
}

void WinMain::on_alwaysOnTop_Chk_toggled(bool checked)
{
    // Apply Aways on Top condition
    setWindowFlag(Qt::WindowStaysOnTopHint, checked);
    show();
}
}
