#include "sculptor.h"
#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>


Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
       nx=10;
       ny=10;
       nz=10;


}

void Plotter::paintEvent(QPaintEvent *event)
{
    float linha=1,coluna,limiteX,limiteY;

    QPainter painter(this);
    QPen pen;
    QBrush brush;

    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(Qt::black);
    pen.setWidth(2);


    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(0,0,width(),height());

    pen.setColor(Qt::gray);
    pen.setWidth(1);
    painter.setPen(pen);

    limiteX = width()/nx;
    limiteY = height()/ny;

    for(int i=0;  i < nx; i++) {
        linha = 1;
        for(int j=0; j < ny; j++) {
            painter.drawRect(coluna,linha,limiteX,limiteY);
            linha=linha+limiteY;
        }
        coluna=coluna+limiteX;
    }
}

Plotter::Plotter(int _nx,int _ny, int _nz)
{
        nx =_nx;
        ny =_ny;
        nz =_nz;

}

void Plotter::setNx(int _nx)
{
    nx =_nx;
    repaint();
}
