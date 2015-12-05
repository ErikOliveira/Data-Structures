#include <QCoreApplication>
#include "pilha.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Pilha<int> * p = new Pilha<int>();

    cout<<"Empty stack clear test"<<endl;
    p->clear();
    cout<<"Empty stack pop test:    "<<p->pop()<<endl;
    cout<<"Empty stack topValue test:   "<<p->topValue()<<endl;
    cout<<"Empty stack length test:     "<<p->length()<<endl;
    cout<<"Empty push test"<<endl;
    p->push(1);
    p->push(2);
    p->push(3);

    cout<<"Non-empty stack length test:     "<<p->length()<<endl;
    cout<<"Non-empty stack pop test:        "<<p->pop()<<endl;
    p->show();
    cout<<"Non-empty stack topValue test:       "<<p->topValue()<<endl;
    cout<<"Non-empty stack clear test:      "<<endl;
    p->clear();
    p->show();
    cout<<"Non-empty stack length test:     "<<p->length()<<endl;

    cout<<"After cleared stacked push"<<endl;
    p->push(5);
    p->push(6);
    p->push(7);
    p->push(8);
    p->show();

    cout<<"After cleared stacked length test:       "<<p->length()<<endl;
    cout<<"After cleared stacked re-pushed topvalue test:       "<<p->topValue()<<endl;
    cout<<"After cleared stacked re-pushed pop test:        "<<p->pop()<<endl;
    p->show();

    cout<<"After cleared stacked re-pushed pop test:        "<<p->pop()<<endl;
    p->show();
    cout<<"After cleared stacked re-pushed pop test:        "<<p->pop()<<endl;
    p->show();
    cout<<"After cleared stacked re-pushed pop test:        "<<p->pop()<<endl;
    p->show();
    cout<<"After cleared stacked re-pushed pop test:        "<<p->pop()<<endl;
    p->show();

    return 0;


    return a.exec();
}
