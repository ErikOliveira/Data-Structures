#include <QCoreApplication>
#include "queue.h"
#include <iostream>

using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Queue<int>  * p = new Queue<int>();

    cout<<"Empty queue clear test"<<endl;
    p->clear();
    cout<<"Empty queue dequeue test:\t"<<p->dequeue()<<endl;
    cout<<"Empty queue front value test:\t"<<p->frontValue()<<endl;
    cout<<"Empty queue length:\t"<<p->length()<<endl;

    cout<<"Empty enqueue test"<<endl;
    p->enqueue(1);
    p->enqueue(2);
    p->enqueue(3);
    p->show();

    cout<<"Non-empty queue lenght test:\t"<<p->length()<<endl;

    cout<<"Non-empty queue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();

    cout<<"Non-empty queue frontValue test:\t"<<p->frontValue()<<endl;

    cout<<"Non-empty queue clear test"<<endl;
    p->clear();
    p->show();
    cout<<"Non-empty queue length test:\t"<<p->length()<<endl;

    cout<<"After cleared queued enqueue test"<<endl;
    p->enqueue(5);
    p->enqueue(6);
    p->enqueue(7);
    p->enqueue(8);
    p->show();

    cout<<"After cleared queued length test:\t"<<p->length()<<endl;
    cout<<"After cleared queued re-enqueue front value test:\t"<<p->frontValue()<<endl;
    cout<<"After cleared queued re-enqueue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();

    cout<<"After cleared queued re-enqueue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();
    cout<<"After cleared queued re-enqueue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();
    cout<<"After cleared queued re-enqueue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();
    cout<<"After cleared queued re-enqueue dequeue test:\t"<<p->dequeue()<<endl;
    p->show();


    exit(0);

    return a.exec();
}
