/*
    My custom PushButton Widget
*/
#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QWidget>
#include <QString>
#include <QColor>
#include <QSvgRenderer>

namespace View {
class CustomPushButton : public QPushButton
{
    Q_OBJECT

    // Class Variables
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
