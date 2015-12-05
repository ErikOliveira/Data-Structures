#ifndef PILHA_H
#define PILHA_H
#include <QDebug>
#include "stackadt.h"
#include "../../../Atividades/Lista Ligada/LList/node.h"


template <typename E> class Pilha:public Stack<E>
{
    Node<E>* top; //Top element pushed into it
    int size; //Number of elements stacked

    //Implementation of show method helper
    void Helper_show_stacked_itens(){
        Node<E>* current;
        for(current = top; current != NULL; current = current->getNext()){
            if(current == top)
                qDebug()<<"Top element:     "+QString::number(current->getContent());
            else
                qDebug()<<"Under element:   "+QString::number(current->getContent());
        }
    }

public:

    //Implementation of standart constructor
    Pilha()
    {
        top = NULL;
        size = 0;
    }

    //Implementation of standart desconstructor
    ~Pilha()
    {
        this->clear();
    }

    //Implementation of clear method
    void clear(){
        while(top != NULL){
            Node<E>* it_will_delete_this_node = top;
            top = top->getNext();
            delete it_will_delete_this_node;
        }
        size = 0;
    }

    //Implementation of push method
    void push(const E &it){
        if(!size){
            top = new Node<E>(it,NULL);
            size++;
        }
        else{
            Node<E>* build_new_item_node_to_push_here = new Node<E>(it,top);
            top = build_new_item_node_to_push_here;
            size++;
        }
    }

    //Implementation of pop method
    E pop(){
        if(size){
            E top_value_content_holder = top->getContent();
            Node<E>* next_top_element_holder = top->getNext();
            delete top;
            size--;
            top = next_top_element_holder;
            return top_value_content_holder;
        }
        else{
            qDebug()<<"Empty Stack! No top element is available, NULL was returned by default";
            return NULL;
        }
    }

    //Implementation of topValue method
    const E& topValue() const{
        if(size)
            return top->getContent();
        else{
            qDebug()<<"Empty Stack! No top element is available, NULL was returned by default";
            return NULL;
        }
    }

    //Implementation of length method
    int length() const{
        return size;
    }

    //Method for debugging purpose-only
    void show(){
        this->Helper_show_stacked_itens();
    }
};

#endif // PILHA_H
