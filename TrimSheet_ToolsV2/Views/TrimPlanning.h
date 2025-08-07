#ifndef TRIMPLANNING_H
#define TRIMPLANNING_H

#include <QWidget>
#include <IStartComponent.h>
#include <StyleController.h>
#include <ProportionalContainer.h>

using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class TrimPlanning;
}
QT_END_NAMESPACE

namespace View {
class TrimPlanning : public QWidget, public IStartComponent
{
    Q_OBJECT

    // Class Variables
private:



    // Constructor
public:
    explicit TrimPlanning(QWidget *parent = nullptr);
    ~TrimPlanning();
    void Init();


    // Methods
private:
    Ui::TrimPlanning *ui;


    // IStartComponent interface
public:
    void StartStyleTheme();
    void StartIcons();
    void StartLabels();
};
}
#endif // TRIMPLANNING_H
