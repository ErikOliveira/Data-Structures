/*#include <QCoreApplication>
#include <QDebug>
#include "lbs.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

int main()
{
    LbSys<QString>* p = new LbSys<QString>();
    p->regUser("Erik","21","Beco diagonal, ao lado da loja de doces do irmãos wisley's","0800-Hot-AND-Dangerous");
    qDebug()<<"1st user added";
    p->regBook("Calculo","1982","Munem, A. Mustafa","Atila");
    qDebug()<<"1st book added";
    p->regBook("Logica","1946","Mortari","Atual");
    qDebug()<<"2nd book added";
    p->regUser("Brigitt","Não se revela idade de damas","Isto é uma tentativa de stalking?", "0^9");
    qDebug()<<"2nd user added";
    p->regUser("Eddie","23","Atualmente no mesmo lugar","Não me ligue");
    qDebug()<<"3rd user added";
    p->regUser("Rob", "hot", "Red light neighbhoor", "1239457");
    qDebug()<<"4th user added";
    p->regUser("Brendon", "32", "NYC", "Do you wanna know");
    qDebug()<<"5th user added";
    p->regBook("Capiyu","1960","Fulano Esqueci o nome","Não ganhos dinheiro com isso :(");
    qDebug()<<"3rd book added";
    p->listTitles();
    p->regUser("Erik", "22", "lalala", "9900");
    p->regBook("Logica", "1986", "Sandiego", "Trashpublisher");
    cout<< "Tail before delete root:" << p->getTail() << endl << "current:" << p->getCurrent() << endl;
    p->unrUser("Brendon");
    cout<< "Tail after delete root:" << p->getTail() << endl << "current:" << p->getCurrent() << endl;
    //p->listUsers();
    cout<< "Tail before delete root:" << p->getTail() << endl << "current:" << p->getCurrent() << endl;
    p->unrUser("Rob");
    cout<< "Tail after delete root:" << p->getTail() << endl << "current:" << p->getCurrent() << endl;
    p->listUsers();
    p->regBook("Karma","1989","Palmita","Broke impress");
    p->listTitles();
    p->searchByTitle("Karma",0);
    p->listTitles();
    p->getRent("Eric","Calculo");
    p->getRent("Erik", "Logica");
    p->getRent("Erik","Karma");
    p->listTitles();
    p->listUsers();
    p->unrUser("Erik");
    p->listTitles();
    p->listUsers();
    return 0;
}*/
