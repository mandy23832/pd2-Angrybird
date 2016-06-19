#include"Button.h"
#include<QGraphicsTextItem>
#include<QGraphicsRectItem>
#include<QBrush>

Button::Button(QGraphicsItem *parent): QGraphicsPixmapItem(parent){}
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}
