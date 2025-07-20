#include "CustomPushButton.h"

namespace View {
CustomPushButton::CustomPushButton(QWidget *parent) : QPushButton(parent)
{}

void CustomPushButton::SetStyle(const QString &qssStyleBaseRef, bool useCheckable)
{
    // Set CheckableButton
    this->setCheckable(useCheckable);

    // Set Style Button
    QFile file(qssStyleBaseRef);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString style = QTextStream(&file).readAll();
        this->setStyleSheet(style);

        file.close();
    }
    else
        qDebug() << "Erron in QSS Style: " << qssStyleBaseRef;
}

void CustomPushButton::SetStateIcons(QPixmap iconIdleRef, QPixmap iconPressedRef, QPixmap iconDisableRef, int sizeIcon)
{
    // Set Icons
    _icon.addPixmap(iconIdleRef, QIcon::Normal, QIcon::Off);        // Idle State
    _icon.addPixmap(iconPressedRef, QIcon::Active, QIcon::Off);     // Hover State
    _icon.addPixmap(iconPressedRef, QIcon::Selected, QIcon::Off);   // Pressed State
    _icon.addPixmap(iconDisableRef, QIcon::Disabled, QIcon::Off);   // Disable State
    _icon.addPixmap(iconPressedRef, QIcon::Normal, QIcon::On);      // Checked State

    // Start Value and Size icon
    this->setIcon(_icon);
    this->setIconSize(QSize(sizeIcon, sizeIcon));

}
}
