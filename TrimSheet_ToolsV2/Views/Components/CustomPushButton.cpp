#include "CustomPushButton.h"

namespace View {
CustomPushButton::CustomPushButton(QWidget *parent) : QPushButton(parent)
{   setAttribute(Qt::WA_Hover, true);   setMouseTracking(true);  }

void CustomPushButton::SetStateIcons(QPixmap iconIdleRef, QPixmap iconHoverRef, QPixmap iconPressedRef, QPixmap iconDisableRef, int sizeIcon)
{
    // Set Icons
    _icon.addPixmap(iconIdleRef, QIcon::Normal, QIcon::Off);        // Idle State
    _icon.addPixmap(iconHoverRef, QIcon::Active, QIcon::On);       // Hover State
    //_icon.addPixmap(iconHoverRef, QIcon::Active, QIcon::Off);       // Hover State
    _icon.addPixmap(iconPressedRef, QIcon::Selected, QIcon::Off);   // Pressed State
    _icon.addPixmap(iconDisableRef, QIcon::Disabled, QIcon::Off);   // Disable State
    _icon.addPixmap(iconPressedRef, QIcon::Normal, QIcon::On);      // Checked State

    // Start Value and Size icon
    this->setIcon(_icon);
    this->setIconSize(QSize(sizeIcon, sizeIcon));
}
}
