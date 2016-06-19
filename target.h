#ifndef TARGET_H
#define TARGET_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Target : public GameItem
{
public:
    Target(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // TARGET_H
