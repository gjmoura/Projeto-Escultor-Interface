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

    int x, y, z;
    int dimX, dimY, dimZ;
    int Rx, Ry, Rz;
    int R, G, B, a;
    int radius;
    int eixo;
    unsigned int plano;

private:
    std::vector<std::vector<Voxel>> aux;
    Sculptor *figura;
    unsigned int forma;

signals:

};

#endif // PLOTTER_H
