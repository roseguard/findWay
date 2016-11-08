#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>

#include "waypoint.h"

#define sizeX 11
#define sizeY 9

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    char                *fieldPosses[sizeX];
    QGraphicsScene      *scene;
    wayPoint            *start;
    wayPoint            *finish;

    wayPoint            *field[sizeX][sizeY];
    wayPoint            *activePoint;
    QVector<wayPoint*>  openVect;

    QVector<QGraphicsPixmapItem*>   movements;

    QPixmap             pix;

    bool                inStepBack = false;

    void areaF();
    void setNewActive();
    void setThisActive(wayPoint *point);
    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
