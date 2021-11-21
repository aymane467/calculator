#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include<QApplication>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

    //Creation the widgets
    createWidgets();

    //place Widgets
    placeWidgets();

    startTimer(1000);
}

void TrafficLight::createWidgets()
{

  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
lifeTime =0;
}


void TrafficLight::placeWidgets()
{

  // Placing the widgets
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
  setLayout(layout);
}

void TrafficLight::timerEvent(QTimerEvent *e){
 lifeTime ++;
     if( redlight->isChecked() && lifeTime==4){
         yellowlight->toggle();
         lifeTime=0;

    }
     if( yellowlight->isChecked() && lifeTime==1){
         greenlight->toggle();
         lifeTime=0;
    }

     if(greenlight->isChecked() && lifeTime==2){
         redlight->toggle();
         lifeTime=0;

    }


}

void TrafficLight::keyPressEvent(QKeyEvent *e){
    if (e->key()== Qt::Key_Escape)
        qApp->exit();
    else if  (e->key()== Qt::Key_R)
       redlight->toggle();
    else if (e->key()== Qt::Key_Y)
       yellowlight->toggle() ;
    else if (e->key()== Qt::Key_G)

    greenlight->toggle();
}
