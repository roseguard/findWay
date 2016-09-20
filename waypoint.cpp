#include "waypoint.h"

wayPoint::wayPoint(int tX, int tY, const QPixmap pix, wayPoint *finish, wayPoint *parent) : QGraphicsPixmapItem(pix)
{
    parentPoint = parent;
    finishPoint = finish;

    fX = tX;
    fY = tY;

    F = 0; G = 0; H = 0;

    inOpen = 0;

    FT = new QGraphicsTextItem(this);
    FT->moveBy(10, 10);
    FT->setPlainText("0");
    GT = new QGraphicsTextItem(this);
    GT->moveBy(20, 20);
    GT->setPlainText("0");
    HT = new QGraphicsTextItem(this);
    HT->moveBy(30, 30);
    HT->setPlainText("0");
}

int wayPoint::getF()
{
    F = getG() + getH();
    FT->setPlainText(QString::number(F));
    return F;
}

int wayPoint::getG()
{
    G = parentPoint->G;
    if(fX!=parentPoint->fX && fY!=parentPoint->fY)
    {
        G+=14;
    }
    else
    {
        G+=10;
    }
    GT->setPlainText(QString::number(G));
    return G;
}

int wayPoint::getH()
{
    H = (abs(fX - finishPoint->fX) + abs(fY - finishPoint->fY))*10;
    HT->setPlainText(QString::number(H));
    return H;
}

void wayPoint::setFPos(int tX, int tY)
{
    fX = tX;
    fY = tY;
}

wayPoint::~wayPoint()
{
    delete FT, GT, HT;
}


