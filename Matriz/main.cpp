#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include "matriz.h"
int main()
{
    Matriz *caraca = new Matriz(3,3);
    MatrizADT *tiredOfit = new Matriz(3,3);
    if(caraca->isEmpty())
    {
        qDebug()<< "está vazia" << '\n';
    }
    caraca->insert(0,0,10);
    caraca->insert(0,1,1);
    caraca->insert(0,2,2);
    caraca->insert(1,0,3);
    caraca->insert(1,1,4);
    caraca->insert(1,2,5);
    caraca->insert(2,0,6);
    caraca->insert(2,1,7);
    caraca->insert(2,2,8);

    caraca->exhibit();

    tiredOfit->insert(0,0,2);
    tiredOfit->insert(0,1,3);
    tiredOfit->insert(0,2,-1);
    tiredOfit->insert(1,0,6);
    tiredOfit->insert(1,1,7);
    tiredOfit->insert(1,2,-2);
    tiredOfit->insert(2,0,-5);
    tiredOfit->insert(2,1,3);
    tiredOfit->insert(2,2,-8);

    if(caraca->isDivisible())
    {
        qDebug() << "é divisivel" << '\n';
    }
    caraca->multiply(2);
    caraca->determinant();
    caraca->getRow(0);
    caraca->getColumn(0);
    caraca->exhibit();
    caraca->transposed();
    caraca->sum(tiredOfit);
    caraca->subtract(tiredOfit);
    return 0;
};
