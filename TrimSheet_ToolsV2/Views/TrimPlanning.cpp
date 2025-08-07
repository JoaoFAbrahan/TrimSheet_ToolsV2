#include "TrimPlanning.h"
#include "ui_TrimPlanning.h"
#include "pch.h"

namespace View {
TrimPlanning::TrimPlanning(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrimPlanning)
{
    ui->setupUi(this);

    // Initialize

}

TrimPlanning::~TrimPlanning()
{
    delete ui;
}

void TrimPlanning::Init()
{
    // Set Style
    StartLabels();
    StartStyleTheme();
    StartIcons();

    this->update();
    qApp->processEvents();
}


// Methods
void TrimPlanning::StartStyleTheme()
{
    // Form
    Controller::StyleController::Instance().ApplyStyle(this, Controller::WindowBackground);

    // Panels
    Controller::StyleController::Instance().ApplyStyle(ui->generatedContainer_Panel, Controller::ContainerPanel);
    Controller::StyleController::Instance().ApplyStyle(ui->exportContainer_Panel, Controller::ContainerPanel);
    Controller::StyleController::Instance().ApplyStyle(ui->dataGridViewContainer_Panel, Controller::ContainerPanel);
    Controller::StyleController::Instance().ApplyStyle(ui->viewContainer_Panel, Controller::ContainerPanel);

    // Butons

}
void TrimPlanning::StartIcons()
{

}
void TrimPlanning::StartLabels()
{

}


}
