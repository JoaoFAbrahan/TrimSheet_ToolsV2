#include "ToggleSwitch.h"

namespace View {
ToggleSwitch::ToggleSwitch(QWidget *parent, int trackRadius, int thumbRadius) : QAbstractButton(parent), _trackRadius(trackRadius), _thumbRadius(thumbRadius)
{
    setCheckable(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    _margin = std::max(0, _thumbRadius - _trackRadius);
    _baseOffset = std::max(_thumbRadius, _trackRadius);
    _offset = _baseOffset;

    // Conecta o sinal toggled para animar o offset
    connect(this, &ToggleSwitch::toggled, this, [this](bool checked) {
        QPropertyAnimation* anim = new QPropertyAnimation(this, "offset", this);
        anim->setDuration(120);
        anim->setStartValue(_offset);
        anim->setEndValue(endOffset(checked));
        anim->start(QAbstractAnimation::DeleteWhenStopped);
    });
}

void ToggleSwitch::SetColor(QColor trackColorON, QColor trackColorOFF, QColor thumbColorON, QColor thumbColorOFF)
{
    if (_thumbRadius > _trackRadius) {
        _trackColor[true] = trackColorON;
        _trackColor[false] = trackColorOFF;

        _thumbColor[true] = thumbColorON;
        _thumbColor[false] = thumbColorOFF;

        _textColor[true] = trackColorON;
        _textColor[false] = trackColorOFF;

        _thumbText[true] = "";
        _thumbText[false] = "";

        _trackOpacity = 0.5;
    } else {
        _trackColor[true] = trackColorON;
        _trackColor[false] = trackColorOFF;

        _thumbColor[true] = thumbColorON;
        _thumbColor[false] = thumbColorOFF;

        _textColor[true] = trackColorON;
        _textColor[false] = trackColorOFF;

        _thumbText[true] = "✔";
        _thumbText[false] = "✕";

        _trackOpacity = 1.0;
    }
}

QSize ToggleSwitch::sizeHint() const {
    return QSize(
        4 * _trackRadius + 2 * _margin,
        2 * _trackRadius + 2 * _margin
        );
}

int ToggleSwitch::offset() const {
    return _offset;
}

void ToggleSwitch::setOffset(int value) {
    _offset = value;
    update();
}

int ToggleSwitch::endOffset(bool checked) const {
    return checked ? width() - _baseOffset : _baseOffset;
}

void ToggleSwitch::resizeEvent(QResizeEvent* event) {
    QAbstractButton::resizeEvent(event);
    _offset = endOffset(isChecked());
}

void ToggleSwitch::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    qreal track_opacity = _trackOpacity;
    qreal thumb_opacity = 1.0;
    qreal text_opacity = 1.0;

    QColor track_color, thumb_color, text_color;

    if (isEnabled()) {
        track_color = _trackColor[isChecked()];
        thumb_color = _thumbColor[isChecked()];
        text_color = _textColor[isChecked()];
    } else {
        track_opacity *= 0.8;
        track_color = palette().shadow().color();
        thumb_color = palette().mid().color();
        text_color = palette().shadow().color();
    }

    // Track
    p.setBrush(track_color);
    p.setOpacity(track_opacity);
    p.drawRoundedRect(
        QRectF(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin),
        _trackRadius, _trackRadius
        );

    // Thumb
    p.setBrush(thumb_color);
    p.setOpacity(thumb_opacity);
    p.drawEllipse(
        QPointF(_offset, _baseOffset),
        _thumbRadius, _thumbRadius
        );

    // Text
    p.setPen(text_color);
    p.setOpacity(text_opacity);

    QFont font = p.font();
    font.setPixelSize(static_cast<int>(1.5 * _thumbRadius));
    p.setFont(font);

    QRectF textRect(
        _offset - _thumbRadius,
        _baseOffset - _thumbRadius,
        2 * _thumbRadius,
        2 * _thumbRadius
        );

    p.drawText(textRect, Qt::AlignCenter, _thumbText[isChecked()]);
}

void ToggleSwitch::mouseReleaseEvent(QMouseEvent* event) {
    QAbstractButton::mouseReleaseEvent(event);

    if (event->button() == Qt::LeftButton) {
        QPropertyAnimation* anim = new QPropertyAnimation(this, "offset", this);
        anim->setDuration(120);
        anim->setStartValue(_offset);
        anim->setEndValue(endOffset(isChecked()));
        anim->start(QAbstractAnimation::DeleteWhenStopped);

        if(isChecked()) {
            emit switchedOn();
        }
    }

    emit checkStateChanged(isChecked());
}

void ToggleSwitch::enterEvent(QEnterEvent* event) {
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(event);
}
}
