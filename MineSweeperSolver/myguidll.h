
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QList>
#include <QDebug>
#include <QButtonGroup>
#include <QInputDialog>
#include <QPalette>
#include <QColor>
#include <QFont>
#include <vector>
#include <iostream>

#ifndef MYGUIDLL_H
#define MYGUIDLL_H

#include "myguidll_global.h"


class MYGUIDLL_EXPORT Myguidll: public QWidget
{
    Q_OBJECT
using cell=std::pair<int,int>;
    using grid=std::vector<std::vector<cell>>;
public:
    Myguidll(int h,int w,QWidget *parent = nullptr);
    grid get_grid();
    void set_grid(grid);
    void printgrid();
    ~Myguidll();

private:
    int height,width;
    //Myguidll *ui;
    QList<QList<QPushButton*>> mygrid;
    QSize sizeHint() const;
    //int size=10;
    QButtonGroup *buttonGroup;
    grid returnGrid;


private slots:
    //void button_clicked();
     void on_calculate();


    void on_pushButton_clicked(QAbstractButton *button);
    //void on_pushButton_clicked_id(int id);


};

#endif // MYGUIDLL_H
