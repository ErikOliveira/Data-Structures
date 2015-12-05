#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QDebug>
#include "listadt.h"
#include "node.h"


template<typename E> class LinkedList:public ListADT<E>
{
    Node<E> *m_head;
    Node<E> *m_current;
    Node<E> *m_tail;
    int m_length;

    //Implementação do assistente para a inserção do primeiro elemento da lista
    void helper_first_insertion(const E& item){
        qDebug()<<"first prepend";
        this->moveToStart(); //assegurando que o apontador está no inicio da lista
        m_head = new Node<E>(item,NULL); //criando o nó com o primeiro elemento
        m_current = m_tail = m_head; //todos os ponteiros apontando para o unico elemento da lista
        m_length++; //atualizando o numero de nós na lista
    }

    //Implementação do assistente para a inserção de um elemento qualquer no inicio da lista
    void helper_prepend(const E& item){
        qDebug()<<"prepend";
        this->moveToStart(); //assegurando que o apontador está no inicio da lista
        m_head = new Node<E>(item,m_current); //criando o nó com o primeiro elemento
        m_current = m_head; // apontador para o novo item
        m_length++; //atualizando o numero de nós na lista
    }

public:

    //Implementação do construtor padrão
    LinkedList(){
        m_current = m_head = m_tail = NULL;
        m_length = 0;
    }

    //Implementação do destrutor padrão
    ~LinkedList(){

    }

    //Implementação do metodo para limpar a lista
    void clear(){
        while(m_head != NULL){ //verificar se a lista não está vazia
           m_current = m_head; //apontar para o inicio da lista
           m_head = m_head->getNext(); //substituir o nó inicial pelo respectivo sucessor
           delete m_current; //deletando o antigo nó inicial
           m_length--; //atualizando o numero de nós na lista
        }
    }

    //Implementação do método para inserir um no na lista na atual posição apontada
    void insert(const E &item){
        if(!m_length) //se a lista é vazia
            this->helper_first_insertion(item); //chamando o assistente para inserção do primeiro nó
        else if(m_current == m_head){ //se a lista não é vazia, mas o item será inserido no inicio da mesma
            this->helper_prepend(item); //chamando o assistente para inserção do nó no inicio da lista
        }
        else{ //se o item será inserido em uma posição qualquer da lista
            Node<E>* build_new_item_node_here = new Node<E>(item,m_current); //construindo o nó do novo item
            this->prev(); //movendo para o item anterior
            m_current->setNext(build_new_item_node_here); //fazendo a ligação entre os elementos
            m_current = build_new_item_node_here; //apontando para o novo item
            m_length++; //atualizando o numero de nós na lista
        }
    }

    void append(const E &item){
        if(!m_length) //verificar se a lista está vazia
            this->helper_first_insertion(item); //chamando o assistente para inserção do primeiro nó
        else{ //se a lista não é vazia
            Node<E>* build_new_node_to_append_here = new Node<E>(item,NULL); //criando o nó do novo elemento
            this->moveToEnd(); //apontar para o final da lista
            m_current->setNext(build_new_node_to_append_here);
            m_tail = build_new_node_to_append_here;
            m_length++;
        }
    }

    E remove(){
        E aux_removed_node_content = 0;
        if(m_length){
            Node<E> *aux_remove_this_node;
            if(m_current == m_head){
                qDebug()<<"removing the head node";
                aux_remove_this_node = m_head;
                aux_removed_node_content = m_head->getContent();
                m_current = m_head->getNext();
                delete aux_remove_this_node;
                m_length--;
                m_head = m_current;
            }
            else if(m_current == m_tail){
                qDebug()<<"removing the tail node";
                aux_remove_this_node = m_tail;
                aux_removed_node_content = m_tail->getContent();
                this->prev();
                delete aux_remove_this_node;
                m_length--;
                m_tail = m_current;
                m_tail->setNext(NULL);
            }
            else{
                qDebug()<<"removing an any node";
                aux_remove_this_node = m_current;
                aux_removed_node_content = m_current->getContent();
                this->prev();
                m_current->setNext(aux_remove_this_node->getNext());
                delete aux_remove_this_node;
                m_length--;
            }
        }
        else{
            qDebug()<<"Empty List. Zero was returned by Default";
        }
        return aux_removed_node_content;
    }

    void moveToStart(){
        m_current = m_head;
    }

    void moveToEnd(){
        m_current = m_tail;
    }

    void prev(){
        if(m_current != m_head){
            Node<E> *aux_search_this_node_prev = m_current;
            for(m_current = m_head; m_current->getNext() != aux_search_this_node_prev; m_current = m_current->getNext());
        }
    }

    void next(){
        if(m_current != m_tail){
            m_current = m_current->getNext();
        }
    }

    int length() const{
        return m_length;
    }

    int currPos() const{
        int position = 0;
        if(m_length){
            Node<E> *node_next_target_node_here = m_head;
            for(; position<m_length; position++){
                node_next_target_node_here = node_next_target_node_here->getNext();
            }
        }
        else{
            qDebug()<<"Empty List. Zero was returned by default";
        }
        return position;
    }

    void moveToPos(int pos){
        if(pos>=00 && pos < m_length){
            this->moveToStart();
            for(int i =0; i<pos; i++){
                this->next();
            }
        }
        else
            qDebug()<<"Oh no! "+QString::number(pos)+" that's position is out of valid range. All integer number positive less than "+QString::number(m_length)+" is valid! Btw, Nothing changed!";
    }

    const E& getValue() const{
        try{
            return (m_current->getContent());
        }
        catch(...){
            qDebug()<<"Empty list. NULL was returned by default";
            return NULL;
        }
    }
};

#endif // LINKEDLIST_H
