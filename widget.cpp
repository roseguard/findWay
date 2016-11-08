#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent)
{

    for(int i = 0; i < sizeX; i++)
    {
        fieldPosses[i] = new char[sizeY];
    }
    fieldPosses[0] = "wooooooooos";
    fieldPosses[1] = "wowwwwwwoww";
    fieldPosses[2] = "wowwwwoooww";
    fieldPosses[3] = "wowwwwwwwww";
    fieldPosses[4] = "wowwoooooow";
    fieldPosses[5] = "wowwwoowoow";
    fieldPosses[6] = "woooooowoof";
    fieldPosses[7] = "wwwwwoowoow";
    fieldPosses[8] = "wwwwwooooow";

    pix = QPixmap(":/img/quad.png");
    scene = new QGraphicsScene(this);
    setScene(scene);

    int finishX, finishY;
    bool tempEnd = false;
    for(finishX = 0; finishX < sizeX; finishX++)
    {
        for(finishY = 0; finishY < sizeY; finishY++)
        {
            if(fieldPosses[finishY][finishX]=='f')
            {
                finish  = new wayPoint(finishX,finishY, pix);
                finish->finishPoint = finish;
                tempEnd = true;
                break;
            }
        }
        if(tempEnd)
            break;
    }

    tempEnd = false;
    int startX, startY;
    for(startX = 0; startX < sizeX; startX++)
    {
        for(startY = 0; startY < sizeY; startY++)
        {
            if(fieldPosses[startY][startX]=='s')
            {
                start = new wayPoint(startX,startY, pix, finish);
                tempEnd = true;
                break;
            }
        }
        if(tempEnd)
            break;
    }

    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            if ((i == startX && j == startY))
            {
                field[i][j] = start;
                start->setPos(pix.size().width()*(i+1), pix.size().height()*(j+1));
            }
            else if((i == finishX && j == finishY))
            {
                field[i][j] = finish;
                finish->setPos(pix.size().width()*(i+1), pix.size().height()*(j+1));
            }
            else
            {
                field[i][j] = new wayPoint(i, j, pix, finish);
                if(fieldPosses[j][i] == 'w')
                {
                    field[i][j]->isWall = true;
                    field[i][j]->setPixmap(QPixmap(":/img/wall.png"));
                }
                field[i][j]->setPos(pix.size().width()*(i+1), pix.size().height()*(j+1));
            }
        }
    }

    for(int i = 0; i < sizeX; i++)
        for(int j = 0; j < sizeY; j++)
            scene->addItem(field[i][j]);

    start->FT->setPlainText("START");
    finish->FT->setPlainText("FINISH");

    start->inOpen = 2;
    activePoint = start;
    QGraphicsPixmapItem* movement = new QGraphicsPixmapItem(QPixmap(":/img/movement.png").scaled(35,35));
    movement->setPos(activePoint->pos());
    scene->addItem(movement);
    movements.append(movement);
}

void Widget::areaF()
{
    // комментарії розміщення за нумпадом
    openVect.clear();
    if(activePoint->fX-1 >= 0)
    {
        if(!field[activePoint->fX-1][activePoint->fY]->isWall &&           //4
                field[activePoint->fX-1][activePoint->fY]->inOpen!=2)
        {
            field[activePoint->fX-1][activePoint->fY]->parentPoint = activePoint;
            field[activePoint->fX-1][activePoint->fY]->setData(0, field[activePoint->fX-1][activePoint->fY]->F);
            field[activePoint->fX-1][activePoint->fY]->getF();
            openVect.append(field[activePoint->fX-1][activePoint->fY]);
        }
    }
    if(activePoint->fY-1 >= 0)
    {
//        if(!field[activePoint->fX-1][activePoint->fY-1]->isWall &&              //7
//                field[activePoint->fX-1][activePoint->fY-1]->inOpen!=2)
//        {
//            field[activePoint->fX-1][activePoint->fY-1]->parentPoint = activePoint;
//            field[activePoint->fX-1][activePoint->fY-1]->setData(0, field[activePoint->fX-1][activePoint->fY-1]->F);
//            field[activePoint->fX-1][activePoint->fY-1]->getF();
//            openVect.append(field[activePoint->fX-1][activePoint->fY-1]);
//        }

        if(!field[activePoint->fX][activePoint->fY-1]->isWall &&                //8
                field[activePoint->fX][activePoint->fY-1]->inOpen!=2)
        {
            field[activePoint->fX][activePoint->fY-1]->parentPoint = activePoint;
            field[activePoint->fX][activePoint->fY-1]->setData(0, field[activePoint->fX][activePoint->fY-1]->F);
            field[activePoint->fX][activePoint->fY-1]->getF();
            openVect.append(field[activePoint->fX][activePoint->fY-1]);
        }
    }
    if(activePoint->fY+1 <= sizeY)
    {
//        if(!field[activePoint->fX-1][activePoint->fY+1]->isWall &&              //1
//                field[activePoint->fX-1][activePoint->fY+1]->inOpen!=2)
//        {
//            field[activePoint->fX-1][activePoint->fY+1]->parentPoint = activePoint;
//            field[activePoint->fX-1][activePoint->fY+1]->setData(0, field[activePoint->fX-1][activePoint->fY+1]->F);
//            field[activePoint->fX-1][activePoint->fY+1]->getF();
//            openVect.append(field[activePoint->fX-1][activePoint->fY+1]);
//        }
        if(!field[activePoint->fX][activePoint->fY+1]->isWall &&                //2
                field[activePoint->fX][activePoint->fY+1]->inOpen!=2)
        {
            field[activePoint->fX][activePoint->fY+1]->parentPoint = activePoint;
            field[activePoint->fX][activePoint->fY+1]->setData(0, field[activePoint->fX][activePoint->fY+1]->F);
            field[activePoint->fX][activePoint->fY+1]->getF();
            openVect.append(field[activePoint->fX][activePoint->fY+1]);
        }
    }
    if(activePoint->fX+1 <= sizeX)
    {
        if(!field[activePoint->fX+1][activePoint->fY]->isWall &&                    //6
                field[activePoint->fX+1][activePoint->fY]->inOpen!=2)
        {
            field[activePoint->fX+1][activePoint->fY]->parentPoint = activePoint;
            field[activePoint->fX+1][activePoint->fY]->setData(0, field[activePoint->fX+1][activePoint->fY]->F);
            field[activePoint->fX+1][activePoint->fY]->getF();
            openVect.append(field[activePoint->fX+1][activePoint->fY]);
        }
//        if(activePoint->fY-1 >= 0)
//        {
//            if(!field[activePoint->fX+1][activePoint->fY-1]->isWall &&              //9
//                    field[activePoint->fX+1][activePoint->fY-1]->inOpen!=2)
//            {
//                field[activePoint->fX+1][activePoint->fY-1]->parentPoint = activePoint;
//                field[activePoint->fX+1][activePoint->fY-1]->setData(0, field[activePoint->fX+1][activePoint->fY-1]->F);
//                field[activePoint->fX+1][activePoint->fY-1]->getF();
//                openVect.append(field[activePoint->fX+1][activePoint->fY-1]);
//            }
//        }
//        if(activePoint->fY+1 <=7)
//        {
//            if(!field[activePoint->fX+1][activePoint->fY+1]->isWall &&              //3
//                    field[activePoint->fX+1][activePoint->fY+1]->inOpen!=2)
//            {
//                field[activePoint->fX+1][activePoint->fY+1]->parentPoint = activePoint;
//                field[activePoint->fX+1][activePoint->fY+1]->setData(0, field[activePoint->fX+1][activePoint->fY+1]->F);
//                field[activePoint->fX+1][activePoint->fY+1]->getF();
//                openVect.append(field[activePoint->fX+1][activePoint->fY+1]);
//            }
//        }
    }
    setNewActive();
}

void Widget::setNewActive()
{
    qDebug() << openVect.length();
    if(openVect.length()==0)
    {
        if(activePoint==start)
            return;
        activePoint->inOpen = 2;
        activePoint = activePoint->parentPoint;
        QGraphicsPixmapItem *forDel = movements.last();
        movements.removeLast();
        delete forDel;
        openVect.clear();
        inStepBack = true;
        return;
    }
    int minF = openVect.at(0)->F;
    int numsOfThis = 0;
    int count = 0;
    for(int i = 0; i < openVect.length(); i++)
    {
        if(minF > openVect.at(i)->F)
        {
            minF = openVect.at(i)->F;
            count = i;
            numsOfThis = 0;
        }
        numsOfThis++;
    }
//    QVector<wayPoint*> difWays;
//    difWays.append(openVect.at(count));
//    for(int i = 0; i < openVect.length(); i++)
//    {
//        if (openVect.at(i)->F == difWays.first()->F)
//        {
//            difWays.append(openVect.at(i));
//        }
//    }
    int newCount;
    if(numsOfThis>1 && openVect.at(count)->inOpen == 1)
    {
        for(int i = 0; i < openVect.length(); i++)
        {
            if(i==count)
                continue;
            else if(openVect.at(i)->F == minF)
            {
                newCount = i;
                break;
            }
        }
        count = newCount;
    }

    if(openVect.at(count)->inOpen == 1 && !inStepBack)
    {
        wayPoint *workPoint = openVect.at(count);
        wayPoint *befPar = workPoint->parentPoint;
        workPoint->parentPoint = activePoint;
        if(workPoint->F > workPoint->data(0).toInt())
        {
            workPoint->parentPoint = befPar;
            workPoint->getF();
            setThisActive(workPoint);
        }
    }
    else
    {
        activePoint = openVect.at(count);
        QGraphicsPixmapItem* movement = new QGraphicsPixmapItem(QPixmap(":/img/movement.png").scaled(35,35));
        movement->setPos(activePoint->pos());
        scene->addItem(movement);
        movements.append(movement);
    }

    for(int i = 0; i < openVect.length(); i++)
        openVect.at(i)->inOpen = 1;
    openVect.clear();
    activePoint->inOpen = 2;
    inStepBack = false;
}

void Widget::setThisActive(wayPoint *point)
{
    movements.last()->setPos(point->pos());
    activePoint = point;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(activePoint!=finish)
    {
        if(event->text()=="\r")
        {
            areaF();
        }
    }
    else
    {
        finish->FT->setPlainText("FINISH");
        qDebug() << "==================================";
        for(int i = 0; i < movements.length(); i++)
        {
            qDebug() << "------";
            qDebug() << movements.at(i)->x() / pix.width();
            qDebug() << movements.at(i)->y() / pix.height();
            qDebug() << "------";
        }
    }
}

Widget::~Widget()
{
    for(int i = 0; i < movements.length(); i++)
    {
        delete movements.at(i);
    }
    for(int i = 0; i < sizeY; i++)
    {
        delete[] fieldPosses;
    }
}
