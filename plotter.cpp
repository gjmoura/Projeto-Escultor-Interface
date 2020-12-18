#include "sculptor.h"
#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QMouseEvent>

Sculptor *figura;

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
       nx=10;
       ny=10;
       nz=10;
       posZ=0;
       a=1.0;
       setMouseTracking(true);
       escolha = 0;
       figura = new Sculptor(nx,ny,nz);
}

void Plotter::paintEvent(QPaintEvent *event)
{
    float linha=1,coluna,limiteX,limiteY;
    Voxel voxelAtual;

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

            voxelAtual = figura->matriz(i,j,posZ);

            if(voxelAtual.isOn) {
                brush.setColor(QColor(voxelAtual.r,voxelAtual.g,voxelAtual.b));
                painter.setBrush(brush);
            } else {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
            }
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

void Plotter::setNy(int _ny)
{
    nx =_ny;
    repaint();
}

void Plotter::setNz(int _nz)
{
    posZ = _nz;
    repaint();
}

void Plotter::setPutVoxel()
{
    escolha = 0;
    qDebug() << "posição em X , Y, Z ->";
}

void Plotter::setEscolha(int posX,int posY)
{
    if(escolha == 0) {
        figura->putVoxel(posX,posY,posZ);
    }

    repaint();
}

void Plotter::setRed(int _r)
{
    qDebug() << _r;
    R = _r;
    figura->setColor(R,G,B,a);
    repaint();
}

void Plotter::setGreen(int _g)
{

    G = _g;
    figura->setColor(R,G,B,a);
    repaint();
}

void Plotter::setBlue(int _b)
{
    B = _b;
    figura->setColor(R,G,B,a);
    repaint();
}

void Plotter::mousePressEvent(QMouseEvent *event){

    if((event->button() == Qt::LeftButton)){
        // logica para pegar as posiçoes da mastriz
            float constX = width()/nx; // lagura
            float constY = height()/ny; // altura
            int posX,posY;

            posX =  (int) (event->x()/ constX);
            posY =  (int) (event->y()/ constY);
            qDebug() << "string X" << posX;
            qDebug() << "string y" << posY;

            setEscolha(posX,posY);
    }
}
