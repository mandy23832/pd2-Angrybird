#include "land.h"

Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);

    // Create body
    b2BodyDef groundbodyDef;
    groundbodyDef.type = b2_staticBody;
    groundbodyDef.userData = this;
    groundbodyDef.position.Set(x,y);
    g_body = world->CreateBody(&groundbodyDef);
    b2PolygonShape groundbodyBox;
    groundbodyBox.SetAsBox(w,h);
    b2FixtureDef fixturedef;
    fixturedef.shape = &groundbodyBox;
    fixturedef.density = 0;
    fixturedef.friction = 0.3;
    g_body->CreateFixture(&fixturedef);


    scene->addItem(&g_pixmap);
    paint();
}
