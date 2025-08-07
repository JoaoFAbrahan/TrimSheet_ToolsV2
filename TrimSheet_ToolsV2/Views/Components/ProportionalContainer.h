#ifndef PROPORTIONALCONTAINER_H
#define PROPORTIONALCONTAINER_H

#include <QObject>
#include <QWidget>

class ProportionalContainer : public QWidget
{
    Q_OBJECT

    // Constructor
public:
    explicit ProportionalContainer(QWidget *parent = nullptr);


    //Methods
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // PROPORTIONALCONTAINER_H
