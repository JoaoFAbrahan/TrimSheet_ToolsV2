#include "ProportionalContainer.h"

ProportionalContainer::ProportionalContainer(QWidget *parent)
    : QWidget{parent}
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ProportionalContainer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    // Restringe a largura máxima para manter 1:1
    int currentHeight = height();
    setMaximumWidth(currentHeight);

    if (layout() && layout()->count() > 0) {
        QWidget *child = layout()->itemAt(0)->widget();
        if (child) {
            int side = qMin(width(), height());
            child->resize(side, side); // Mantém 1:1
        }
    }
}
