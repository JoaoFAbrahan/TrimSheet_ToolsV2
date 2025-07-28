#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QSvgRenderer>
#include <QPainter>

namespace View {
class CustomPushButton : public QPushButton
{
    Q_OBJECT

    // Class variables
private:
    QIcon _icon;


    // Constructor
public:
    CustomPushButton(QWidget *parent = nullptr);


    // Methods
public:
    void SetStateIcons(QString iconIdleRef, QString iconPressedRef, QColor colorIdle, QColor colorPressed, QColor colorDisable, int sizeIcon = 24);

private:
    QPixmap ColorizeSVG(QString iconPath, QColor iconColor, int iconSize);
};
}
#endif // CUSTOMPUSHBUTTON_H
