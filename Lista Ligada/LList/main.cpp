#include <QCoreApplication>
#include <iostream>
#include "linkedlist.h"

using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList<int> *p = new LinkedList<int>();

    cout<<"test removing from empty list..."<<endl;
    cout<<"removed item content: "<<p->remove()<<endl;
    cout<<"insertions now..."<<endl;

    p->insert(1);
    p->insert(2);
    p->insert(3);
    p->moveToEnd();
    p->insert(4);
    p->insert(5);
    p->append(6);
    p->moveToStart();
    p->insert(7);
    p->moveToPos(2);
    p->insert(8);

    cout<<"see list..."<<endl;
    p->moveToStart();
    for(int i=0; i<p->length(); i++){
       cout<<"Current list element: "<<p->getValue()<<endl;
       p->next();
    }

    return 0;
}
