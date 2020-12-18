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
       dimX = 1;
       dimY = 1;
       dimZ = 1;
       Rx = 1;
       Ry = 1;
       Rz = 1;
       radius = 1;
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

Plotter::~Plotter()
{
    deleteMatriz();
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

void Plotter::setCutVoxel()
{
    escolha =1;

}

void Plotter::setPutBox()
{
    escolha =2;
    qDebug() << "putbox";
}

void Plotter::setCutBox()
{
    escolha =3;
}

void Plotter::setPutEsphere()
{
    escolha =4;
}

void Plotter::setCutEsphere()
{
 escolha =5;
}

void Plotter::setPutElipse()
{
 escolha =6;
}

void Plotter::setCutElipse()
{
 escolha =7;
}

void Plotter::setEscolha(int posX,int posY)
{
    if(escolha == 0) {
        figura->putVoxel(posX,posY,posZ);
    } else if(escolha == 1) {

        figura->cutVoxel(posX,posY,posZ);
    } else if(escolha == 2) {
        int xF,yF,zF;
        xF =posX+dimX;
        yF = posY+dimY;
        zF = posZ+dimZ;

        if(xF >= nx) {
            xF = nx;
        }

        if(yF >= ny) {
            yF = ny;
        }

        if(zF >= nz) {
            zF = nz;
        }

            figura->putBox(posX,xF,posY,yF,posZ,zF);

    } else if(escolha == 3) {
        int xF,yF,zF;
        xF =posX+dimX;
        yF = posY+dimY;
        zF = posZ+dimZ;

        if(xF >= nx) {
            xF = nx;
        }

        if(yF >= ny) {
            yF = ny;
        }

        if(zF >= nz) {
            zF = nz;
        }

            figura->cutBox(posX,xF,posY,yF,posZ,zF);
    } else if(escolha == 4) {

        figura->putSphere(posX,posY,posZ,radius);
    } else if(escolha == 5) {

        figura->cutSphere(posX,posY,posZ,radius);
    } else if(escolha == 6){
        figura->putEllipsoid(posX,posY,posZ,Rx, Ry, Rz);
    }else if(escolha == 7){
        figura->cutEllipsoid(posX,posY,posZ,Rx, Ry, Rz);
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

void Plotter::setDimX(int _dimX)
{
    dimX = _dimX;
}

void Plotter::setDimY(int _dimY)
{
    dimY = _dimY;
}

void Plotter::setDimZ(int _dimZ)
{
    dimZ = _dimZ;
}

void Plotter::setRx(int _Rx)
{
    Rx = _Rx;
}

void Plotter::setRy(int _Ry)
{
    Ry = _Ry;
}

void Plotter::setRz(int _Rz)
{
    Rz = _Rz;
}

void Plotter::setRadius(int _radius)
{
    radius = _radius;
}

void Plotter::deleteMatriz()
{
    figura->~Sculptor();
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
