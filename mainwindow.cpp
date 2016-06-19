#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QGraphicsView>
#include<QGraphicsScene>
#include<button.h>
#include<QGraphicsItem>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int flag1=0;
int flag2=0;
int flag3=0;
void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    // Create background
    scene->setBackgroundBrush(QPixmap(":/bg2.jpg").scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/3),world,scene));
    // Create Obstacle
    Obstacle *wood1 = new Obstacle(21.6f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood1);
    Obstacle *wood2 = new Obstacle(24.0f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood2);
    Obstacle *wood3 = new Obstacle(21.5f,14.0f,3.5f,0.2f,&timer,QPixmap(":/thinwood.png"),world,scene);
    itemList.push_back(wood3);
    Obstacle *wood4 = new Obstacle(18.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood4);
    Obstacle *wood5 = new Obstacle(22.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood5);
    Obstacle *wood6 = new Obstacle(19.6f,13.0f,2.0f,0.4f,&timer,QPixmap(":/thickwood.png").scaled(width()/8,height()/10),world,scene);
    itemList.push_back(wood6);
    Obstacle *wood7 = new Obstacle(26.0f,13.0f,2.5f,0.4f,&timer,QPixmap(":/thinwood.png").scaled(width()/8,height()/10),world,scene);
    itemList.push_back(wood7);
    Obstacle *wood8 = new Obstacle(25.0f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood8);
    Obstacle *wood9 = new Obstacle(28.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood9);
    // Create target (You can edit here)
    target1 = new Target(19.0f,5.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target1);
    target2 = new Target(25.0f,5.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target2);
    target3 = new Target(22.8f,10.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target3);
    flag1=1;
    flag2=1;
    flag3=1;
    QGraphicsPixmapItem * pic_b1 = new QGraphicsPixmapItem();
    pic_b1->setPixmap(QPixmap(":/shooter.png").scaled(width()/12,height()/6));
    scene->addItem(pic_b1);
    pic_b1->setPos(50,350);//decorate picture
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    //create the restart Button
    Button* playButton = new Button();
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    playButton->setPixmap(QPixmap(":/restart.png"));
    scene->addItem(playButton);
    playButton->setPos(0,0);
    //create the quit Button
    Button* quitButton = new Button();
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    quitButton->setPixmap(QPixmap(":/exit.png"));
    scene->addItem(quitButton);
    quitButton->setPos(100,0);
    QTimer * timer0 = new QTimer();
    connect(&timer,SIGNAL(timeout()),this,SLOT(getpoint()));
    timer0->start(1000);

}
int gen=0;
int gen1=0;
int tag=0;
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    { 
        if(gen%5==0)
        {
            if(tag%4==0)
            {   //Create bird (You can edit here)
                birdie = new Bird(3.0f,6.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9,height()/9),world,scene);
                birdie->setLinearVelocity(b2Vec2(20,10));
                itemList.push_back(birdie);
                if(tag/4>0)
                    delete birdie3;

            }
            if(tag%4==1)
            {   //Create bird (You can edit here)
                birdie1 = new Bird1(3.0f,6.0f,0.54f,&timer,QPixmap(":/yellow.png").scaled(height()/7,height()/7),world,scene);
                birdie1->setLinearVelocity(b2Vec2(8,10));
                itemList.push_back(birdie1);
                delete birdie;
            }
            if(tag%4==2)
            {   //Create bird (You can edit here)
                birdie2=new Bird2(3.0f,6.0f,0.27f,&timer,QPixmap(":/white.png").scaled(height()/9,height()/9),world,scene);
                birdie2->setLinearVelocity(b2Vec2(10,15));
                itemList.push_back(birdie2);
                delete birdie1;
            }
            if(tag%4==3)
            {   //Create bird (You can edit here)
                birdie3=new Bird3(3.0f,6.0f,0.27f,&timer,QPixmap(":/blue.png").scaled(height()/9,height()/9),world,scene);
                birdie3->setLinearVelocity(b2Vec2(12,15));
                itemList.push_back(birdie3);
                delete birdie2;
            }
            tag++;
        }
        gen++;
        /* TODO : add your code here */
        //std::cout << "Press !"<<tag<<"  "<<gen<< std::endl ;
    }

    if(event->type() == QEvent::MouseMove)
    {
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {   
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }

    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
        if(e->key() == Qt::Key_A)
        {
           birdie2->setLinearVelocity(b2Vec2(0,-20));
           if(!birdie2)return;
        }
        if(e->key() == Qt::Key_S)
        {
           float x,y;
           x = birdie3->g_body->GetPosition().x;
           y = birdie3->g_body->GetPosition().y;
           Bird3 *birdie_a=new Bird3(x,y,0.27f,&timer,QPixmap(":/blue.png").scaled(height()/9,height()/9),world,scene);
           Bird3 *birdie_b=new Bird3(x,y,0.27f,&timer,QPixmap(":/blue.png").scaled(height()/9,height()/9),world,scene);
            if(!birdie3)return;
        }
}

void MainWindow::game()
{
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/3),world,scene));
    // Create Obstacle
    Obstacle *wood1 = new Obstacle(21.6f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood1);
    Obstacle *wood2 = new Obstacle(24.0f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood2);
    Obstacle *wood3 = new Obstacle(21.5f,14.0f,3.5f,0.2f,&timer,QPixmap(":/thinwood.png"),world,scene);
    itemList.push_back(wood3);
    Obstacle *wood4 = new Obstacle(18.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood4);
    Obstacle *wood5 = new Obstacle(22.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood5);
    Obstacle *wood6 = new Obstacle(19.6f,13.0f,2.0f,0.4f,&timer,QPixmap(":/thickwood.png").scaled(width()/8,height()/10),world,scene);
    itemList.push_back(wood6);
    Obstacle *wood7 = new Obstacle(26.0f,13.0f,2.5f,0.4f,&timer,QPixmap(":/thinwood.png").scaled(width()/8,height()/10),world,scene);
    itemList.push_back(wood7);
    Obstacle *wood8 = new Obstacle(25.0f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood8);
    Obstacle *wood9 = new Obstacle(28.5f,6.0f,0.5f,3.0f,&timer,QPixmap(":/thinwood1.png").scaled(width()/28,height()/3),world,scene);
    itemList.push_back(wood9);
    // Create target (You can edit here)
    target1 = new Target(19.0f,5.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target1);
    target2 = new Target(25.0f,5.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target2);
    target3 = new Target(22.8f,10.0f,0.36f,&timer,QPixmap(":/pig.png").scaled(height()/9,height()/9),world,scene);
    itemList.push_back(target3);
    flag1=1;
    flag2=1;
    flag3=1;
    QGraphicsPixmapItem * pic_b1 = new QGraphicsPixmapItem();
    pic_b1->setPixmap(QPixmap(":/shooter.png").scaled(width()/12,height()/6));
    scene->addItem(pic_b1);
    pic_b1->setPos(50,350);//decorate picture
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    //create the restart Button
    Button* playButton = new Button();
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    playButton->setPixmap(QPixmap(":/restart.png"));
    scene->addItem(playButton);
    playButton->setPos(0,0);
    //create the quit Button
    Button* quitButton = new Button();
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    quitButton->setPixmap(QPixmap(":/exit.png"));
    scene->addItem(quitButton);
    quitButton->setPos(100,0);
    QTimer * timer0 = new QTimer();
    connect(&timer,SIGNAL(timeout()),this,SLOT(getpoint()));
    timer0->start(1000);
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::start()
{
    //ui->setupUi(this);
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    // Create background
    scene->setBackgroundBrush(QPixmap(":/bg2.jpg").scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);
    game();
    qApp->installEventFilter(this);

}



void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
int count=0;
void MainWindow::getpoint()
{
    float vx1 = target1->g_body->GetLinearVelocity().x;
    float vy1 = target1->g_body->GetLinearVelocity().y;
    float vx2 = target2->g_body->GetLinearVelocity().x;
    float vy2 = target2->g_body->GetLinearVelocity().y;
    float vx3 = target3->g_body->GetLinearVelocity().x;
    float vy3 = target3->g_body->GetLinearVelocity().y;
    std::cout<<vx1<<vy1<<std::endl;
    if(flag1==1){
        if(vx1>2||vy1>2)
        {
            delete target1;
            score=score+50;
            flag1=0;
        }
    }
    std::cout<<vx2<<vy2<<std::endl;
    if(flag2==1){
        if(vx2>2||vy2>2)
        {
            delete target2;
            score=score+50;
            flag2=0;
        }
    }
    std::cout<<vx3<<vy3<<std::endl;
    if(flag3==1){
        if(vx3>2||vy3>2)
        {
            delete target3;
            score=score+50;
            flag3=0;
        }
    }
}
