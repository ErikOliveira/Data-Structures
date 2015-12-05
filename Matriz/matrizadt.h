#ifndef MATRIZADT
#define MATRIZADT
#include <QString>

class MatrizADT{
protected:
    int x;
    int y;
    double **matriz;
public:
    //Retornar determinante
    virtual double determinant() const = 0;
    //Adicionar linha
    virtual void addRow(double* array) = 0;
    //Adicionar coluna
    virtual void addColumn(double* array) = 0;
    //Inserir numa posição determinada
    virtual void insert(int x,int y, double value) = 0;
    //Retorna string formatada
    virtual QString toString() const = 0;
    //Soma Matriz
    virtual MatrizADT* sum(MatrizADT* matriz) = 0;
    //Multiplicar Matriz
    virtual MatrizADT* multiply(const double z) = 0;
    //Subtrair Matriz
    virtual MatrizADT* subtract(MatrizADT* matriz) = 0;
    //Verificar se Matriz é divisivel
    virtual bool isDivisible() = 0;
    //Verificar se Matriz está vazia
    virtual bool isEmpty() = 0;
    //Retorne a linha pedida
    virtual double* getRow(const int y) = 0;
    //Retorne a coluna pedida
    virtual double* getColumn(const int x) = 0;
    //Retorne Matriz transposta
    virtual MatrizADT* transposed() = 0;
};


#endif // MATRIZADT


