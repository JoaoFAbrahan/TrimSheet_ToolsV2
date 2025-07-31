#include "About.h"
#include "ui_About.h"

namespace View {
About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    // Initialize
    this->setWindowIcon(QIcon(":/Icons/About.ico"));
    this->setWindowTitle(tr("About"));
}

About::~About()
{   delete ui;  }

void About::Init()
{
    // Set Style
    _styleControllerComponent.DarkThemeStatus(true);
    StartLabels();
    StartStyleTheme();
    StartIcons();

    this->update();
    qApp->processEvents();
}

void About::StartStyleTheme()
{
    // Form
    _styleControllerComponent.ApplyStyle(this, Controller::WindowBackground);

    // Panel
    _styleControllerComponent.ApplyStyle(ui->top_Panel, Controller::MainMenuPanel);

    // Labels
    _styleControllerComponent.ApplyStyle(ui->softwareName_Label, Controller::TitleLabel);
    _styleControllerComponent.ApplyStyle(ui->version_Label, Controller::NormalLabel);
    _styleControllerComponent.ApplyStyle(ui->copyright_Label, Controller::TitleLabel);
    _styleControllerComponent.ApplyStyle(ui->githubInfo_Label, Controller::NormalLabel);
    _styleControllerComponent.ApplyStyle(ui->licensingInfo_Label, Controller::NormalLabel);
    _styleControllerComponent.ApplyStyle(ui->softwareInfo_Label, Controller::NormalLabel);
}
void About::StartIcons()
{}
void About::StartLabels()
{
    // Set Labels
    ui->copyright_Label->setText(tr("Copyright © 2025 João Felipe Abrahan. Licensed under GNU GPL v3.\nAll rights reserved under free software terms."));
    ui->githubInfo_Label->setText(tr("For more information about TrimSheet Tools and its versions, please visit the github page:"));
    ui->licensingInfo_Label->setText(tr("For licensing informations, please visit:"));
    ui->softwareInfo_Label->setText(tr("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version."));
}
}
