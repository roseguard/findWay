#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>

#include "waypoint.h"

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QGraphicsScene      *scene;
    wayPoint            *start;
    wayPoint            *finish;

    wayPoint            *field[7][5];
    wayPoint            *activePoint;
    QVector<wayPoint*>  openVect;

    QVector<QGraphicsPixmapItem*>   movements;

    QPixmap             pix;

    void areaF();
    void setNewActive();
    void setThisActive(wayPoint *point);
    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
