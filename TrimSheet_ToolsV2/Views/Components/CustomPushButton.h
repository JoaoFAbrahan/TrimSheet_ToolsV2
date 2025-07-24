#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QFile>

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
    void SetStateIcons(QPixmap iconIdleRef, QPixmap iconHoverRef, QPixmap iconPressedRef, QPixmap iconDisableRef, int sizeIcon = 24);
};
}
#endif // CUSTOMPUSHBUTTON_H
