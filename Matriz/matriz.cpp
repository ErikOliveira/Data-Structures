#include "matriz.h"
#include <QDebug>
#include <iostream>
#include <QString>
using namespace std;

//Implementation of Custom Matriz Constructor.
Matriz::Matriz(int a, int b)
{
    this->x = a; // Determinando o tamanho do meu objeto (Linhas).
    this->y = b; // Determinando o tamanho do meu objeto (Colunas).
    this->matriz = new double *[a]; // Alocando memoria para as linhas.
    int i, j; // variaveis controladoras de Loops (contadoras).
    for(i=0; i<a; i++)
    {
        this->matriz[i] = new double[b]; // Alocando memoria para as colunas.
        for(j=0; j<b; j++)
        {
            this->matriz[i][j] = 0; // Zerando o bojeto, para garantir que não haja lixo de memoria. Visando compatibilidade Cross-plataform
        }
    }
}

//Implementation of Matriz Standard Constructor.
Matriz::Matriz()
{

}

//Implementation of Matriz Standard Descontructor.
Matriz::~Matriz()
{

}

//Method only for debug proposes.
void Matriz::exhibit()
{
    int i, j; // Variaveis contadoras
    for(i=0; i<this->x; i++)
    {
        for(j=0; j<this->y; j++)
        {
            cout << '\t' << this->matriz[i][j] << '\t'; // "imprimindo" elemento-a-elemento do objeto na saida padrão.
        }
        cout << '\n' << '\n'; // Quebra de linha, evitando que elementos distindo fiquem "aninhados".
    }

}

//Implementation of Matriz::determinant method.
double Matriz::determinant() const
{
    double rsp=0, aux=1, auy=1; // Variaveis de Resposta, Auxiliar-principal e auxiliar-secundaria respectivamente.
    int i;
    if(this->x==this->y && this->x==2)
    {
        for(i=0; i<this->x; i++)
        {
            aux *= this->matriz[i][i]; // Obtendo a diagonal principal.
        }
        for(i=((this->y)-1); i>=0; i--)
        {
            auy *= this->matriz[i][i]; // Obtendo a diagonal secundaria.
        }
        rsp = aux - auy; // Determinante é igual a diagonal principal menos diagonal secundaria.
    }
    else if(this->x==this->y && this->x==3)
    {
        auy=1;
        auy*= this->matriz[0][0]; // Obtendo o valor do elemento "a"
        auy*= this->matriz[1][1]; // Obtendo o valor do elemento "e"
        auy*= this->matriz[2][2]; // Obtendo o valor do elemento "i"
        aux = auy; // Realizando (a.e.i)
        auy =1;
        auy *= this->matriz[0][0]; // Obtendo o valor do elemento "a"
        auy *= this->matriz[1][2]; // Obtendo o valor do elemento "f"
        auy *= this->matriz[2][1]; // Obtendo o valor do elemento "h"
        aux -= auy; // Realizando -(a.f.h)
        auy = 1;
        auy *= this->matriz[0][1]; // Obtendo o valor do elemento "b"
        auy *= this->matriz[1][0]; // Obtendo o valor do elemento "d"
        auy *= this->matriz[2][2]; // Obtendo o valor do elemento "i"
        aux -= auy; // Realizando -(a.b.i)
        auy = 1;
        auy *= this->matriz[0][1]; // Obtendo o valor do elemento "b"
        auy *= this->matriz[1][2]; // Obtendo o valor do elemento "f"
        auy *= this->matriz[2][0]; // Obtendo o valor do elemento "g"
        aux += auy; // Realizando +(b.f.g)
        auy = 1;
        auy *= this->matriz[0][2]; // Obtendo o valor do elemento "c"
        auy *= this->matriz[1][0]; // Obtendo o valor do elemento "d"
        auy *= this->matriz[2][1]; // Obtendo o valor do elemento "h"
        aux += auy; // Realizando +(c.d.h)
        auy = 1;
        auy *= this->matriz[0][2]; // Obtendo o valor do elemento "c"
        auy *= this->matriz[1][1]; // Obtendo o valor do elemento "e"
        auy *= this->matriz[2][0]; // Obtendo o valor do elemento "g"
        aux -= auy; // Realizando -(c.e.g)
        rsp=aux; // O determinante é dado por (aej)-(afh)-(bfi)+(bfg)+(cdh)-(ceg)
    }
    else
    {
        qDebug()<< "Invalid Operation! determinant method expected a squared matrix of order 2 or 3. 0(zero) was returned by default";
    }
    return rsp;
}

//Implementation of Matriz::addRow
void Matriz::addRow(double *array)
{
    static int i=0;
    if(sizeof(array) == sizeof(this->matriz))
    {
        for(int j=0; j<x; j++)
        {
            this->matriz[i][j] = array[j]; // Atribuindo valores do array fornencido como parametro para a matriz do objeto que disparou o metodo.
        }

        i++;
        qDebug() << "Row added";
        if(i==x)
        {
            i=i%x; // Após chamado "x" vezes, volte para a linha 0
            qDebug()<< "Success! All rows were filled, call this method again will overwrite the first row";
        }
    }
    else
    {
        qDebug()<< "Invalid Operation! addRow method can't handle with an array greater than the length of matrix line";
    }
}

void Matriz::addColumn(double *array)
{
    static int i=0;
    if(sizeof(array) == sizeof(this->matriz))
    {
        for(int j=0; j<y; j++)
        {
            this->matriz[j][i] = array[j]; // Atribuindo valores do array fornecido como parametro para a matriz do objeto que disparou o metodo.
        }

        i++;
        qDebug() << "Column added";
        if(i==y)
        {
            i=i%y; // Após ser chamado "y" vezes, volta para a coluna 0
            qDebug() << "Success! All Column were filled, call this method again will overwrite the first Column";
        }
    }
    else
    {
        qDebug()<< "Invalid Operation! addColumn method can't handle with an array greater than the length of matrix column";
    }
}

void Matriz::insert(int a, int b, double value)
{
    if(((a>=0)&&(a<x)) &&((b>=0)&&(b<y)))
        this->matriz[a][b]= value; // Atribuindo o valor passado como parametro para a matriz do objeto que disparou o metodo, na posicao informada.
    else
    {
        qDebug()<< "Invalid Operation! insert method can't handle negatives indexes or indexes greater than matrix length line or column";
    }

}


QString Matriz::toString() const
{
    QString formatar = ""; // Criando uma string vazia
    formatar = '\t'; // Tabulação para formartar
    for(int i=0; i<this->x; i++)
    {
        for(int j=0; j<this->y; j++)
        {
            formatar+=QString::number(this->matriz[i][j]); // Atribuindo o conteudo da matriz do objeto que disparou o metodo para a string.
            formatar+='\t'; // Tabulação para formatar.
            if(j+1>=this->y)
            {
                if(i!=((this->x)-1))
                    formatar+='\n'; // Quebra de linha, Para ao fazer um "cout" ou "qDebug" os elementos fiquem na forma de matriz[subscrito(ixj)].
                    formatar+='\t'; // Tabulção para formatar.
            }
        }
        if((i+1)>=this->x)
            formatar+=""; // Adicionando caracterer 'Null' a String para simbolizar o fim da mesma.
    }
    return formatar;
}

//Implementation of Matriz::sum method
MatrizADT *Matriz::sum(MatrizADT *matriz)
{
    int i, j; // Variaveis controladoras de loop.
    double *ax = 0; // Array auxiliar para obter os valores da ADT.
    Matriz *aux = new Matriz(this->x, this->y); // Objeto auxiliar-principal ao qual serão atribuidos os valores obtidos da ADT pelo array ax.
    Matriz *auy = new Matriz(this->x, this->y); // Objeto auxiliar-secundario no qual serão armazenados os valores da operação.
    MatrizADT* sum = new Matriz(this->x, this->y); // Objeto de Retorno.
        for(i=0; i<this->x; i++)
        {
            ax = matriz->getRow(i); // Obtendo o endereço de uma linha de elementos da ADT.
            aux->addRow(ax); // Transferindo os valores obtidos da minha ADT para a minha Auxiliar.
        }
        for(i=0; i<this->x; i++)
        {
            for(j=0; j<this->y; j++)
            {
                auy->matriz[i][j] += aux->matriz[i][j] + this->matriz[i][j]; // Realizando a adição da ADT com o objeto que disparou o metodo.
            }
        }
        for(i=0; i<this->x; i++)
        {
            ax = auy->getRow(i); // Obtendo o endereço de um linha de elementos da minha auxiliar-secundaria.
            sum->addRow(ax); // Transferindo os valores para a ADT soma.
        }
    return sum;

}



MatrizADT *Matriz::multiply(const double z)
{
    Matriz* aux = new Matriz(this->x,this->y); // Criando uma Auxiliar para multiplicar os valores, visto que o "const"...
    for(int i=0; i<x; i++) // ..., impossibilita que se opere com o objeto que disparou o metodo.
    {
        for(int j=0; j<y; j++)
        {
            aux->insert(i,j,(this->matriz[i][j])*z); // Inserido na auxiliar o valor do "objeto-gatilho" já operando-o pelo z fornecido.
        }
    }
    return aux;
}

MatrizADT *Matriz::subtract(MatrizADT *matriz)
{
    int i, j; // Variaveis controladoras de Loops
    double *ax = 0; // Array auxiliar para obter os valores da ADT.
    Matriz *aux = new Matriz(this->x, this->y); // Objeto auxiliar-principal ao qual serão atribuídos os valores obtidos da ADT.
    Matriz *auy = new Matriz(this->x, this->y); // Objeto auxiliar-secundario no qual serão atribuidos os valores operados.
    MatrizADT* sub = new Matriz(this->x, this->y); // Objeto de retorno.
        for(i=0; i<this->x; i++)
        {
            ax = matriz->getRow(i); // Obtendo o endereço de uma linha de elementos da ADT.
            aux->addRow(ax); // Transferindo os valores obtidos da ADT para minha auxiliar-principal.
        }
        for(i=0; i<this->x; i++)
        {
            for(j=0; j<this->y; j++)
            {
                auy->matriz[i][j] += this->matriz[i][j] - aux->matriz[i][j]; // Realizando a subtração dos valores do objeto-gatilho aos da ADT
            }
        }
        for(i=0; i<this->x; i++)
        {
            ax = auy->getRow(i); // Obtendo o endereço de uma linha de elementos da minha auxiliar-secundária.
            sub->addRow(ax); // Transferindo os valores para uma ADT subtração.
        }
    return sub;

}

bool Matriz::isDivisible()
{
    return false;
}

bool Matriz::isEmpty()
{
    double rsp =0; // Uma tecnica de PI (Já suponho que meu objeto está vazio, visto que pelo construtor este é seu estado inicial)
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            rsp += this->matriz[i][j]; // Procuro elementos no meu objeto
        }
    }
    if(!rsp) // Se o objeto está vazio, rsp =0, e !rsp=1.
    {
//        qDebug()<< "It's Empty!";
        return true;
    }

    else
    {
//        qDebug()<< "It's Filled. Be careful!";
        return false;
    }
}

double *Matriz::getRow(const int b)
{
    Matriz *aux = new Matriz (1, this->x); // Criando um objeto-vazio para obter valores do objeto-gatilho.
    if(((b>=0)&&(b<this->y)))
    {
        for(int i=0; i<this->y; i++)
        {
            aux->matriz[0][i] = this->matriz[b][i]; // Obtendo os valores do Objeto-gatilho.
        }
    }
    else
        qDebug() << "Invalid Operation! getRow method can't handle negatives indexes or indexes greater than matrix length line";
//    aux->exhibit();
    return &(aux->matriz[0][0]);
}

double *Matriz::getColumn(const int a)
{
    Matriz *aux = new Matriz(1, this->y); // Criando um objeto vazio para obter valores do objeto gatilho.
    if(((a>=0)&&(a<this->x)))
    {
        for(int i=0; i<this->x; i++)
        {
            aux->matriz[0][i] = this->matriz[i][a]; // Obtendo valores do objeto-gatilho.
        }
    }
    else
        qDebug()<< "Invalid Operation! getColumn method can't handle negatives indexes or indexes greater than matrix length column";
//    aux->exhibit();
    return &(aux->matriz[0][0]);
}

MatrizADT *Matriz::transposed()
{
    double* aux = 0; // Criando um objeto auxiliar para salvar o endereço de uma linha de elementos do objeto-gatilho.
    MatrizADT* trans = new Matriz(this->x, this->y); // Novo objeto vazio onde serão salvos os valores transpostos do objeto-gatilho.
    if(this->x==this->y)
    {
        for(int i=0; i<this->x; i++)
        {
                aux = this->getRow(i); // Obtendo o entereço de uma linha de objetos.
                trans->addColumn(aux); // Adicionando-os à uma coluna do Objeto "trans"
        }

    }
    else
        qDebug()<< "Invalid Operation! transposed method can't handle with not squared matrices. A pointer to Null matrix was return by default";
    return trans;
}
