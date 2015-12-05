#include <QCoreApplication>
#include <iostream>
#include "btree.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BTree<char> *p = new BTree<char>();

    cout<<"Empty-tree tests..."<<endl<<"call clear..."<<endl;
    p->clear();
    cout<<"after clear empty caller"<<endl;
    cout<<"call Remove"<<endl;
    p->remove('\0');
    cout<<"after remove empty caller"<<endl;
    cout<<"Empty-tree leafs count:\t"<<p->countLeaf()<<endl
       <<"Empty-tree nodes count:\t"<<p->countNode()<<endl
      <<"Empty-tree levels count:\t"<<p->countLevel()<<endl
     <<"Empty-tree height cout:\t"<<p->height()<<endl
    <<"Empty-tree lower get:\t"<<p->lower()<<endl
    <<"Empty-tree greater get:\t"<<p->greater()<<endl
    <<"Empty-tree get here:\t"<<p->getHere()<<endl
    <<"Empty-tree get tree:\t"<<p->getTree()<<endl;

    cout<<"filling the tree..."<<endl;

    p->add('I');
    p->add('E');
    p->add('T');
    p->add('D');
    p->add('H');

    cout<<"All itens add"<<endl;
    cout<<p->toString().toStdString()<<endl;
    p->remove('H');
    cout<<"after existent removed called"<<endl;
    cout<<p->toString().toStdString()<<endl;

    cout<<"subtree tests..."<<endl;
    Node<char>* addlike_subTree = new Node<char>('J',NULL,NULL);
    Node<char>* addlike_subTree_left_sub = new Node<char>('A',NULL,NULL);
    Node<char>* addlike_subTree_right_sub = new Node<char>('B',NULL,NULL);
    Node<char>* addlike_subTree_left_right = new Node<char>('c', NULL,NULL);

    addlike_subTree->setLeft(addlike_subTree_left_sub);
    addlike_subTree->setRight(addlike_subTree_right_sub);
    p->addSubTree(addlike_subTree);

    //forced add for debbuging purposes only
    addlike_subTree_left_sub->setRight(addlike_subTree_left_right);

    cout<<"after addsubtree caller"<<endl;
    cout<<p->toString().toStdString()<<endl;
    cout<<"after in tree caller"<<endl<<p->inTree('H')<<endl;
    cout<<"completing remove method test: removing the root"<<endl;
    p->remove('I');
    cout<<p->toString().toStdString()<<endl;

    cout<<"lower testing"<<endl<<p->lower();
    cout<<"greater test"<<endl<<p->greater();
    cout<<"counting nodes test:\t"<<p->countNode()<<endl
       <<"couting height test:\t"<<p->height()<<endl
      <<"counting leafs test:\t"<<p->countLeaf()<<endl;
    cout<<"Completing remove method test - final: try remove inexistent item"<<endl;
    p->remove('z');
    cout<<p->toString().toStdString()<<"\t|\tnodes:\t"<<p->countNode()
       <<"\t|\tleafs:\t"<<p->countLeaf()<<endl;

    cout<<"gets tree components test..."<<endl;
    const Node<char>* gettedRoot = p->getTree();
    cout<<"root in main test:\t"<<gettedRoot->getContent()
       <<"\t|\twhere current is?:\t"<<p->getHere()<<endl;

    cout<<"desconstructor test..."<<endl;
    p->~BTree();

    cout<<"construct with subtree"<<endl;
    addlike_subTree = new Node<char>('J',NULL,NULL);
    addlike_subTree_left_sub = new Node<char>('A',NULL,NULL);
    addlike_subTree_right_sub = new Node<char>('B',NULL,NULL);
    addlike_subTree_left_right = new Node<char>('c', NULL,NULL);

    addlike_subTree->setLeft(addlike_subTree_left_sub);
    addlike_subTree->setRight(addlike_subTree_right_sub);
    addlike_subTree_left_sub->setLeft(addlike_subTree_left_right);

    BTree<char> *q = new BTree<char>(addlike_subTree);
    cout<<"after construct w sub caller:    "<<q->toString().toStdString()<<endl;
    cout<<"adding"<<endl;
    q->add('d');
    q->add('D');
    q->add('C');
    cout<<"added!"<<endl;
    cout<<q->toString().toStdString()<<endl;
    cout<<q->height()<<endl;
    cout<<"level counting test, after add an already existency key. Expec 0 | result:\t"<<q->countLevel()<<endl;
    cout<<"moving..."<<endl;
    q->toLeft();
    q->toRight();
    q->toLeft();
    cout<<"movement done"<<endl;
    cout<<"level counting test, after built w sub caller. Expec: 3 | result:\t"<<q->countLevel()<<endl;
    return 0;
}
