#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <bird3.h>
#include <bird1.h>
#include <bird2.h>
#include <target.h>
#include <obstacle.h>
#include <button.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *e);
    void game();

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    void start();
    void getpoint();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird *birdie;
    Bird1 *birdie1;
    Bird2 *birdie2;
    Bird3 *birdie3;
    Target*target1;
    Target*target2;
    Target*target3;
    int score;
};

#endif // MAINWINDOW_H
