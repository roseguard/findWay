#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class wayPoint : public QGraphicsPixmapItem
{
public:
    wayPoint(int tX, int tY, const QPixmap pix,
             wayPoint *finish = 0, wayPoint *parent = 0
            );
    ~wayPoint();

    int F, G, H;
    wayPoint            *parentPoint;   //звідки прийшли
    wayPoint            *finishPoint;   //куди воювати
    QGraphicsTextItem   *FT, *GT, *HT;    //оцінка вартості
    int                 inOpen;         //чи в відкритому списку 0 - не активне, 1 - відкрите, 2 - закрите
    bool                isWall;
    int                 fX, fY;         //позиція на полі

    int     getG();                     //встановлюють та
    int     getH();                     //повертають значення
    int     getF();                     //F, G, H;
    void    setFPos(int tX, int tY);
};

#endif // WAYPOINT_H
