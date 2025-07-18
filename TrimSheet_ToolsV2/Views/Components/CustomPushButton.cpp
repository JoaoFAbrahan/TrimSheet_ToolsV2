#include "CustomPushButton.h"

namespace View {
CustomPushButton::CustomPushButton(QWidget *parent) : QPushButton(parent) {}

void CustomPushButton::SetStateIcons(const QString &qssStylePath, QIcon iconIdleRef, QIcon iconPressedRef, QIcon iconDisableRef, int sizeIcon)
{
    // Set Style Button
    QFile file(qssStylePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style = QTextStream(&file).readAll();
        this->setStyleSheet(style);
        file.close();
    }
    else
        qDebug() << "Erron in QSS Style: " << qssStylePath;

    // Set Icons
    _iconIdle = iconIdleRef;
    _iconPressed = iconPressedRef;
    _iconDisable = iconDisableRef;

    // Start Value and Size icon
    this->setIcon(_iconIdle);
    this->setIconSize(QSize(sizeIcon, sizeIcon));
}

// Private Methods
void CustomPushButton::enterEvent(QEnterEvent  *event)
{
    this->setIcon(_iconPressed);
    QPushButton::enterEvent(event);
}

void CustomPushButton::leaveEvent(QEvent *event)
{
    this->setIcon(_iconIdle);
    QPushButton::leaveEvent(event);
}

void CustomPushButton::mousePressEvent(QMouseEvent *event)
{
    this->setIcon(_iconPressed);
    QPushButton::mousePressEvent(event);
}

void CustomPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    this->setIcon(_iconIdle);
    QPushButton::mouseReleaseEvent(event);
}
}
