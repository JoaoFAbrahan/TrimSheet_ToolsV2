/*
    My custom ToggleSwitch Button Widget
*/
#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QWidget>
#include <QColor>
#include <QMap>
#include <QPropertyAnimation>
#include <QMouseEvent>

namespace View {
class ToggleSwitch : public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY toggled)

    // Class Variables
private:
    int _trackRadius;
    int _thumbRadius;
    int _margin;
    int _baseOffset;
    int _offset;
    qreal _trackOpacity;
    QMap<bool, QColor> _trackColor;
    QMap<bool, QColor> _thumbColor;
    QMap<bool, QColor> _textColor;
    QMap<bool, QString> _thumbText;
    int endOffset(bool checked) const;


    // Constructor
public:
    ToggleSwitch(QWidget* parent = nullptr, int trackRadius = 10, int thumbRadius = 8);


    // Methods
public:
    QSize sizeHint() const override;
    int offset() const;
    void setOffset(int value);
    void SetColor(QColor trackColorON,  QColor trackColorOFF, QColor thumbColorON, QColor thumbColorOFF);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) override;

    // Events
signals:
    void checkStateChanged(bool checked);
    void switchedOn();
};
}
#endif // TOGGLESWITCH_H
