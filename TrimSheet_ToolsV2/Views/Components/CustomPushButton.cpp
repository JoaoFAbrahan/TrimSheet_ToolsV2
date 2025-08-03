#include "CustomPushButton.h"
#include "pch.h"

namespace View {
CustomPushButton::CustomPushButton(QWidget *parent) : QPushButton(parent)
{   }

void CustomPushButton::SetStateIcons(QString iconIdleRef, QString iconPressedRef, QColor colorIdle, QColor colorPressed, QColor colorDisable, int sizeIcon)
{
    // Set Icons
    _icon.addPixmap(ColorizeSVG(iconIdleRef, colorIdle, sizeIcon), QIcon::Normal, QIcon::Off);          // Idle State
    _icon.addPixmap(ColorizeSVG(iconPressedRef, colorPressed, sizeIcon), QIcon::Selected, QIcon::Off);  // Pressed State
    _icon.addPixmap(ColorizeSVG(iconIdleRef, colorDisable, sizeIcon), QIcon::Disabled, QIcon::Off);     // Disable State
    _icon.addPixmap(ColorizeSVG(iconPressedRef, colorPressed, sizeIcon), QIcon::Normal, QIcon::On);     // Checked State

    // Start Value and Size icon
    this->setIcon(_icon);
    this->setIconSize(QSize(sizeIcon, sizeIcon));
}

QPixmap CustomPushButton::ColorizeSVG(QString iconPath, QColor iconColor, int iconSize)
{
    QSvgRenderer renderer(iconPath);
    if (!renderer.isValid()) {
        qDebug() << "Erro ao carregar SVG:" << iconPath;
        return QPixmap();
    }

    QPixmap pixmap(QSize(iconSize, iconSize));
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    // Primeiro renderiza o SVG
    renderer.render(&painter);

    // Agora aplica a cor com máscara
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), iconColor);

    return pixmap;
}
}
