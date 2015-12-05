#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include <QString>
/*
 *  - Big Number
 *      Para resolver problema do numero limitado de
 *  representações dos tipos primitivos é possivel tratar
 *  os números como um Big Number, que é uma forma
 *  de  repesentar um numero de um número n de casa
 *  assim você pode fazer operações com números muito
 *  extensos sem qualquer preocupação.
 *
 *  - Recomendação
 *      Recomendo que use estrutura Pilha para fazer operações
 *
 */
class BigNumber
{
public:
    //Definir soma usando big number
    virtual BigNumber* operator +(BigNumber* num) = 0;
    //Definir subtrair usando big number
    virtual BigNumber* operator -(BigNumber* num) = 0;
    //Definir resto usando big number
    virtual BigNumber* operator %(BigNumber* num) = 0;
    //Atibuir valor do numero representado por uma string
    virtual BigNumber* operator =(QString num) = 0;
    //Retorna String do número em questão
    virtual QString toString() = 0;
};

#endif // BIGNUMBER_H
