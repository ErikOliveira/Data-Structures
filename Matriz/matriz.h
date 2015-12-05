#ifndef MATRIZ_H
#define MATRIZ_H
#include "matrizadt.h"
#include <QDebug>


class Matriz: public MatrizADT
{
public:
    Matriz(int a, int b);
    Matriz();
    ~Matriz();
    void exhibit();
    double determinant() const;
    void addRow(double *array);
    void addColumn(double *array);
    void insert(int a, int b, double value);
    QString toString() const;
    MatrizADT *sum(MatrizADT *matriz);
    MatrizADT* multiply(const double z);
    MatrizADT* subtract(MatrizADT *matriz);
    bool isDivisible();
    bool isEmpty();
    double* getRow(const int b);
    double* getColumn(const int a);
    MatrizADT* transposed();
};

#endif // MATRIZ_H
