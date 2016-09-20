#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent)
{
    pix = QPixmap(":/img/quad.png");
    scene = new QGraphicsScene(this);
    setScene(scene);
    finish  = new wayPoint(5,2, pix);
    finish->finishPoint = finish;
    start   = new wayPoint(1,2, pix, finish);

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            field[i][j] = new wayPoint(i, j, pix, finish);
            field[i][j]->setPos(pix.size().width()*(i+1), pix.size().height()*(j+1));
        }
    }

    delete field[1][2];
    delete field[5][2];
    field[1][2] = start;
    start->setPos(pix.size().width()*(1+1), pix.size().height()*(2+1));
    start->FT->setPlainText("S");
    field[5][2] = finish;
    finish->setPos(pix.size().width()*(5+1), pix.size().height()*(2+1));
    finish->FT->setPlainText("F");

    field[3][1]->isWall = true;
    field[3][2]->isWall = true;
    field[3][3]->isWall = true;
    field[3][1]->setPixmap(QPixmap(":/img/wall.png"));
    field[3][2]->setPixmap(QPixmap(":/img/wall.png"));
    field[3][3]->setPixmap(QPixmap(":/img/wall.png"));

    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 5; j++)
            scene->addItem(field[i][j]);

    start->inOpen = 2;
    activePoint = start;
    QGraphicsPixmapItem* movement = new QGraphicsPixmapItem(QPixmap(":/img/movement.png").scaled(35,35));
    movement->setPos(activePoint->pos());
    scene->addItem(movement);
    movements.append(movement);
}

void Widget::areaF()
{
    openVect.clear();
    if(activePoint->fX-1 >= 0)
    {
        if(!field[activePoint->fX-1][activePoint->fY]->isWall &&
                field[activePoint->fX-1][activePoint->fY]->inOpen!=2)
        {
            field[activePoint->fX-1][activePoint->fY]->parentPoint = activePoint;
            field[activePoint->fX-1][activePoint->fY]->setData(0, field[activePoint->fX-1][activePoint->fY]->F);
            field[activePoint->fX-1][activePoint->fY]->getF();
            openVect.append(field[activePoint->fX-1][activePoint->fY]);
        }
        if(activePoint->fY-1 >= 0)
        {
            if(!field[activePoint->fX-1][activePoint->fY-1]->isWall &&
                    field[activePoint->fX-1][activePoint->fY-1]->inOpen!=2)
            {
                field[activePoint->fX-1][activePoint->fY-1]->parentPoint = activePoint;
                field[activePoint->fX-1][activePoint->fY-1]->setData(0, field[activePoint->fX-1][activePoint->fY-1]->F);
                field[activePoint->fX-1][activePoint->fY-1]->getF();
                openVect.append(field[activePoint->fX-1][activePoint->fY-1]);
            }

            if(!field[activePoint->fX][activePoint->fY-1]->isWall &&
                    field[activePoint->fX][activePoint->fY-1]->inOpen!=2)
            {
                field[activePoint->fX][activePoint->fY-1]->parentPoint = activePoint;
                field[activePoint->fX][activePoint->fY-1]->setData(0, field[activePoint->fX][activePoint->fY-1]->F);
                field[activePoint->fX][activePoint->fY-1]->getF();
                openVect.append(field[activePoint->fX][activePoint->fY-1]);
            }
        }
        if(activePoint->fY+1 <= 5)
        {
            if(!field[activePoint->fX-1][activePoint->fY+1]->isWall &&
                    field[activePoint->fX-1][activePoint->fY+1]->inOpen!=2)
            {
                field[activePoint->fX-1][activePoint->fY+1]->parentPoint = activePoint;
                field[activePoint->fX-1][activePoint->fY+1]->setData(0, field[activePoint->fX-1][activePoint->fY+1]->F);
                field[activePoint->fX-1][activePoint->fY+1]->getF();
                openVect.append(field[activePoint->fX-1][activePoint->fY+1]);
            }

            if(!field[activePoint->fX][activePoint->fY+1]->isWall &&
                    field[activePoint->fX][activePoint->fY+1]->inOpen!=2)
            {
                field[activePoint->fX][activePoint->fY+1]->parentPoint = activePoint;
                field[activePoint->fX][activePoint->fY+1]->setData(0, field[activePoint->fX][activePoint->fY+1]->F);
                field[activePoint->fX][activePoint->fY+1]->getF();
                openVect.append(field[activePoint->fX][activePoint->fY+1]);
            }
        }
    }
    if(activePoint->fX+1 <= 7)
    {
        if(!field[activePoint->fX+1][activePoint->fY]->isWall &&
                field[activePoint->fX+1][activePoint->fY]->inOpen!=2)
        {
            field[activePoint->fX+1][activePoint->fY]->parentPoint = activePoint;
            field[activePoint->fX+1][activePoint->fY]->setData(0, field[activePoint->fX+1][activePoint->fY]->F);
            field[activePoint->fX+1][activePoint->fY]->getF();
            openVect.append(field[activePoint->fX+1][activePoint->fY]);
        }
        if(activePoint->fY-1 >= 0)
        {
            if(!field[activePoint->fX+1][activePoint->fY-1]->isWall &&
                    field[activePoint->fX+1][activePoint->fY-1]->inOpen!=2)
            {
                field[activePoint->fX+1][activePoint->fY-1]->parentPoint = activePoint;
                field[activePoint->fX+1][activePoint->fY-1]->setData(0, field[activePoint->fX+1][activePoint->fY-1]->F);
                field[activePoint->fX+1][activePoint->fY-1]->getF();
                openVect.append(field[activePoint->fX+1][activePoint->fY-1]);
            }
        }
        if(activePoint->fY+1 <=7)
        {
            if(!field[activePoint->fX+1][activePoint->fY+1]->isWall &&
                    field[activePoint->fX+1][activePoint->fY+1]->inOpen!=2)
            {
                field[activePoint->fX+1][activePoint->fY+1]->parentPoint = activePoint;
                field[activePoint->fX+1][activePoint->fY+1]->setData(0, field[activePoint->fX+1][activePoint->fY+1]->F);
                field[activePoint->fX+1][activePoint->fY+1]->getF();
                openVect.append(field[activePoint->fX+1][activePoint->fY+1]);
            }
        }
    }
    setNewActive();
}

void Widget::setNewActive()
{
    int minF = openVect.at(0)->F;
    int count = 0;
    for(int i = 0; i < openVect.length(); i++)
    {
        if(minF > openVect.at(i)->F)
        {
            minF = openVect.at(i)->F;
            count = i;
        }
    }
    if(openVect.at(count)->inOpen == 1)
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
}

void Widget::setThisActive(wayPoint *point)
{
    movements.last()->setPos(point->pos());
    activePoint = point;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(activePoint!=finish)
        areaF();
}

Widget::~Widget()
{
    for(int i = 0; i < movements.length(); i++)
    {
        delete movements.at(i);
    }
}
