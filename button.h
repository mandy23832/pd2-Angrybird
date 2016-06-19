#ifndef BUTTON_H
#define BUTTON_H

#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMoveEvent>
#include<QObject>

class  Button:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Button(QGraphicsItem* parent=NULL);

    //public methods(events)
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void clicked();


};

#endif // BUTTON_H
