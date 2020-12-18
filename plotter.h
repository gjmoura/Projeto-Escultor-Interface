#ifndef PLOTTER_H
#define PLOTTER_H

#include "sculptor.h"
#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
    //void drawShape(int shape, bool mousePressed);

    Plotter(int _nx=10,int _ny=10, int _nz=10);

    ~Plotter(){};



    int nx, ny, nz;
    int dimX, dimY, dimZ;
    int Rx, Ry, Rz;
    int R, G, B, a;
    int radius;
    int eixo;
    unsigned int plano;

public slots:
    void setNx(int _nx);

signals:

};

#endif // PLOTTER_H
