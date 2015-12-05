#ifndef LBS
#define LBS
#include <cstddef>
#include <QDebug>
#include <QString>
#include "node.h"
template <typename E> class LbSys
{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* current;
    Node<E>* hd;
    Node<E>* tl;
    Node<E>* curr;
    int flag;

    Node<E>* Search (Node<E> *apontador, Node<E> *inicio, Node<E> *fim, const E &busca){
        apontador = inicio;
        while(apontador){
            if((busca)== (apontador->getField1())){
                return apontador;
            }
            else if((apontador->getNext())== fim){
                if((busca) == (fim->getField1())){
                    return fim;
                }
                else{
                    if(flag)
                        qDebug()<< "\tSorry! But It's seems doesn't exists in our database. :(";
                    return NULL;
                }
            }
            apontador = apontador->getNext();
        }
    }

    void Unregister (Node<E> *apontador, Node<E> *&inicio, Node<E> *fim, Node<E> *toRemove, const E& Nome_ttl){
        if(((toRemove->getField1())== Nome_ttl)&&(toRemove == inicio)){
            qDebug() << "Unregistering: " + toRemove->getField1() + "...";
            Node<E>* aux = toRemove->getNext();
            delete toRemove;
            inicio = aux;
            apontador = inicio;
        }
        else{
            apontador = inicio;
            while(apontador){
                if((apontador->getNext() == toRemove)&&((apontador->getNext())!= fim)){
                    qDebug()<< "Unregistering: " + toRemove->getField1() + "..";
                    Node<E>* aux = toRemove->getNext();
                    delete toRemove;
                    apontador->setNext(aux);
                    break;
                }
                else if((apontador->getNext() == toRemove)&&((apontador->getNext()) == fim)){
                    qDebug()<< "Unregistering: " + toRemove->getField1() + ".";
                    Node<E>* aux = (apontador->getNext());
                    delete aux;
                    fim = apontador;
                    apontador->setNext(NULL);
                    break;
                }
                else
                    apontador = apontador->getNext();
            }
        }
    }

    void cadastr(Node<E> *&apontador, Node<E> *&inicio, Node<E> *&fim, const E& nm_ttl,const E& age_yrpub,const E& end_atr,const E& tlf_edt){
        if(!inicio){
            inicio = new Node<E>(nm_ttl,age_yrpub,end_atr,tlf_edt);
            inicio->setNum(0);
            fim = inicio;
            apontador = fim;
        }
        else{
            if(!(apontador->getNext())){
                Node<E>* aux = new Node<E>(nm_ttl,age_yrpub,end_atr,tlf_edt);
                aux->setNum(0);
                apontador = fim;
                apontador->setNext(aux);
                fim = apontador->getNext();
            }
            else{
                apontador = apontador->getNext();
                cadastr(apontador,inicio,fim,nm_ttl,age_yrpub,end_atr,tlf_edt);
            }
        }
    }

    void Helperdevolution(Node<E> *apontador, Node<E> *&inicio, Node<E> *fim, const E& busca, E &string){
        apontador = inicio;
        while(apontador){
            if((busca)== (apontador->getField5())){
                string += apontador->getField1();
                string += " | ";
            }
            if((apontador->getNext())== fim){
                if((busca) == (fim->getField5())){
                    string += apontador->getField1();
                    string += " | ";
                }
            }
            apontador = apontador->getNext();
        }
    }

    Node<E>* HelperUnregister(Node<E> *apontador, Node<E> *&inicio, Node<E> *fim, const E& busca){
        apontador = inicio;
        while(apontador){
            if((busca)== (apontador->getField5())){
                return apontador;
            }
            if((apontador->getNext())== fim){
                if((busca) == (fim->getField5())){
                    return fim;
                }
            }
            apontador = apontador->getNext();
        }
    }

public:
    LbSys() {
        head = NULL;
        current = tail = head;
        hd = NULL;
        curr = tl = hd;
        flag = 1;

    }
    ~LbSys();
    void regUser(const E& nome,const E& idade,const E& endereco,const E& telefone){
        flag = 0;
        if(!findaUser(nome))
            this->cadastr(current,head,tail,nome,idade,endereco,telefone);
        else{
            qDebug()<< "\tOh No! Already has a user registered with this username. If that's really another one, try typing a second/last name to its name to avoid conflicts and try it again :(";
        }
        flag = 1;
    }
    void regBook(const E& titulo,const E& ano_publicacao,const E& autor, const E& Editora){
        flag = 0;
        if(!findaBook(titulo))
            this->cadastr(curr,hd,tl,titulo,ano_publicacao,autor,Editora);
        else
            qDebug()<<"\tOh No! Already has a book registered with this name. If that's really another one, try typing some suffix to its name to avoid conflicts and try it again :(";
        flag = 1;
    }

    E userInfo(Node<E> *Usr){
        E aux = "";
        aux += "\tUsuario (Nome e idade):\n\t\t\t";
        aux += (Usr->getField1()) + ", " + (Usr->getField2()) + ".\n";
        aux += "\tEndereço:\n\t\t\t";
        aux += Usr->getField3() + '\n';
        aux += "\tTelefone:\n\t\t\t";
        aux += Usr->getField4() + '\n';
        aux += "\tLivros em seu poder (" + QString::number(Usr->getNum()) + ')';
        if(Usr->getNum()){
            aux += ": " + Usr->getField5() + '\n';
        }
        else
            aux += '\n';
        return aux;
    }
    E bookInfo(Node<E> *&book){
        E aux = "";
        aux += "\tLivro (Titulo e Ano):\n\t\t\t";
        aux += (book->getField1()) + ", " + (book->getField2()) + ".\n";
        aux += "\tAutor:\n\t\t\t";
        aux += book->getField3() + '\n';
        aux += "\tEditora:\n\t\t\t";
        aux += book->getField4() + '\n';
        aux += "\t!: ";
        if(itsAvaliable(book))
            aux += "It's available to be lend :)\n";
        else
            aux += "Sorry, this title, it's already borrowed by... " + (book->getField5()) + '\n';
        return aux;
    }

    void listUsers(){
        current = head;
        qDebug()<<"\t\t------------- Listing All Users -------------\n";
        if(!head)
            qDebug()<<"\tOh No! There no users registered :(";
        else
            while(current){
                qDebug() << qPrintable(userInfo(current));
                if((current->getNext())!= tail)
                    current = current->getNext();
                else{
                    qDebug() << qPrintable(userInfo(tail));
                    break;
                }
            }
        qDebug()<<"\t-------------------------------------------------------------\n";
    }
    void listTitles(){
        curr = hd;
        qDebug()<<"\t\t------------- Listing All Titles -------------\n";
        if(!hd)
            qDebug()<<"\tOh No! There no books registered :(";
        else
            while(curr){
                qDebug() << qPrintable(bookInfo(curr));
                if((curr->getNext())!= tl)
                    curr = curr->getNext();
                else{
                    qDebug() << qPrintable(bookInfo(tl));
                    break;
                }
            }
        qDebug()<<"\t-------------------------------------------------------------\n";
    }

    bool itsAvaliable(Node<E> *&book){
        return !book->getNum();
    }

    Node<E>* findaBook(const E& Title){
        Node<E>* aux = this->Search(curr,hd,tl,Title);
        return aux;
    }
    Node<E>* findaUser(const E& Nome){
        Node<E>* aux = this->Search(current,head,tail,Nome);
        return aux;
    }

    void unrUser(const E& Nome){
        Node<E>* aux = findaUser(Nome);
        if(aux){
            if(!aux->getNum())
                this->Unregister(current,head,tail,aux,Nome);
            else{
                int x = aux->getNum();
                for(int i=0; i<x; i++){
                    Node<E>* auy = HelperUnregister(curr,hd,tl,Nome);
                    getUnrt(Nome,auy->getField1());
                }
                unrUser(Nome);
            }
        }
        else
            qDebug() << "\t\t      ...None Users was unregistered, :D";
    }
    void unrBook(const E& Title){
        Node<E>* aux = findaBook(Title);
        if(aux){
            if(itsAvaliable(aux))
                this->Unregister(curr,hd,tl,aux,Title);
            else
                qDebug()<<"\tSorry, can't unregister a book borrowed...";
        }
        else
            qDebug()<< "\t\t      ...None Books was unregistered, :D";
    }

    void getRent(const E &User, const E &Title){
        Node<E>* aux = findaUser(User);
        Node<E>* auy = findaBook(Title);
        if(aux&&auy){
            if(itsAvaliable(auy)){
                if(aux->getNum()<3){
                    auy->setField5(aux->getField1());
                    auy->setNum(1);
                    E ax = "";
                    ax += aux->getField5();
                    ax += " | ";
                    ax += auy->getField1();
                    ax += " |";
                    aux->setField5(ax);
                    aux->setNum(((aux->getNum())+1));
                }
                else
                    qDebug()<<"\tOh No! Did you like reading ham?. But, sadly you reached the maximum allowed number of books borrow. Sorry!";
            }
            else{
                E ax = auy->getField5();
                qDebug()<< "\tOh No! This title, it's was already borrowed by... " + ax;
            }
        }
        else
            qDebug()<< "\tOh No! Either one parameter or both was not find, none book was borrowed :(";
    }
    void getUnrt(const E &User,const E &Title){
        Node<E>* aux = findaUser(User);
        Node<E>* auy = findaBook(Title);
        if(aux&&auy){
            if(!itsAvaliable(auy)){
                if(aux->getNum()){
                    auy->setField5(NULL);
                    auy->setNum(0);
                    E ax = "";
                    Helperdevolution(curr,hd,tl,aux->getField1(),ax);
                    aux->setField5(ax);
                    aux->setNum(((aux->getNum())-1));
                }
                else
                    qDebug()<<"\tOh No! This User, it isn't get any book. Nothing to do :)";
            }
            else{
                qDebug()<< "\tOh No! This title, it isn't borrowed. Nothing to do :)";
            }
        }
        else
            qDebug()<< "\tOh No! Either one parameter or both was not find, none book was gave back :(";
    }
};

#endif // LBS

