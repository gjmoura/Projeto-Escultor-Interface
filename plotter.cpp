#include "sculptor.h"
#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>


Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=50, y=50, z=50;
    figura = new Sculptor(x,y,z);
    dimX=0, dimY=0, dimZ=0;
    Rx=0, Ry=0, Rz=0, radius=0;
    R=1, G=1, B=1, a=255;

    eixo=0, plano=1;


}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
    painter.setPen(pen);
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);


}
