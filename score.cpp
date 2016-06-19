#include"Score.h"
#include<QFont>

Score::Score(QGraphicsTextItem *parent){
    //initialize score=0
    score=0;

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Helvetica",38));
}

void Score::increase(){
    score+50;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
