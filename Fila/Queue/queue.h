#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>
#include "queueadt.h"
#include "../../../Atividades/Lista Ligada/LList/node.h"


template <typename E>class Queue:public QueueADT<E>
{
    Node<E>* front; //Front element enqueued into it
    Node<E>* rear; //Rear element enqueued into it
    int size; //Number of elements enqueued

    //Implementation of first enqueue method helper
    void Helper_first_enqueue(const E& item){
        front = new Node<E>(item,NULL);
        rear = front;
        size++;
    }

    //Implementation of show method helper
    void Helper_show_queue(){
        Node<E>* current;
        for(current = front; current != NULL; current = current->getNext()){
            qDebug()<<"Current enqueued element: "<<QString::number(current->getContent());
        }
    }

public:

    //Implementation of standart constructor
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    //Implementation of standart desconstructor
    ~Queue()
    {
        this->clear();
    }

    //Implementation of clear method
    void clear()
    {
        while(front != NULL){
            Node<E>* it_will_delete_this_node = front;
            front = front->getNext();
            delete it_will_delete_this_node;
        }
        rear = front;
        size = 0;
    }

    //Implementation of enqueue method
    void enqueue(const E& it)
    {
        if(!size)
            this->Helper_first_enqueue(it);
        else{
            Node<E>* build_new_item_to_enqueued_here = new Node<E>(it,NULL);
            rear->setNext(build_new_item_to_enqueued_here);
            rear = build_new_item_to_enqueued_here;
            size++;
        }
    }

    //Implementation of dequeue method
    E dequeue(){
        if(size){
            E aux_front_content_holder = front->getContent();
            Node<E> * aux_new_front_holder = front->getNext();
            delete front;
            front = aux_new_front_holder;
            size--;
            return aux_front_content_holder;
        }
        else{
            qDebug()<<"Empty queue! NULL was returned by default";
            return NULL;
        }
    }

    //Implementation of frontValue method
    const E& frontValue() const{
        if(size)
            return front->getContent();
        else{
            qDebug()<<"Empty queue! FrontValue isn't available, NULL was returned by default";
            return NULL;
        }
    }

    //Implementation of length method
    int length() const{
        return size;
    }

    //Method for debugging purpose-only
    void show(){
        this->Helper_show_queue();
    }
};

#endif // QUEUE_H
