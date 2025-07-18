#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QFile>

namespace View {
class CustomPushButton : public QPushButton
{
    Q_OBJECT

    // Class variables
private:
    QIcon _iconIdle;
    QIcon _iconHover;
    QIcon _iconPressed;
    QIcon _iconDisable;


    // Constructor
public:
    CustomPushButton(QWidget *parent = nullptr);


    // Methods
public:
    void SetStateIcons(const QString &qssStylePath, QIcon iconIdleRef, QIcon iconPressedRef, QIcon iconDisableRef, int sizeIcon = 24);

protected:
    void enterEvent(QEnterEvent  *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};
}
#endif // CUSTOMPUSHBUTTON_H
