#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include <QLCDNumber>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();




 // Add you custom slots here

protected:
    void createWidgets();        //Function to create the widgets
    void placeWidget();         // Function to place the widgets
    void makeConnexions();      // Create all the connectivity

//events
protected:
    void keyPressEvent(QKeyEvent *e)override;     //Override the keypress events

private:
    QGridLayout *buttonsLayout; // layout for the buttons
    QVBoxLayout *layout;        //main layout for the button
    QVector<QPushButton*> digits;  //Vector for the digits
    QPushButton *enter;            // enter button
    QVector<QPushButton*> operations; //operation buttons
    QLCDNumber *disp;
private:
    int * left=nullptr;          //left operand
    int * right=nullptr;         // right operand
    QString *operation=nullptr;  // Pointer on the current operation// Where to display the numbers
public slots:
   void newDigit();
   void changeOperation();  //Slot to handle the click on operations
void calcul();
};
#endif // CALCULATOR_H
