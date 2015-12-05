#ifndef NODE_H
#define NODE_H


template <typename E> class Node
{
    E content;
    Node* next;
public:
    Node(){

    }

    ~Node(){

    }

    Node(E content, Node* next){
        this->setContent(content);
        this->setNext(next);
    }

    E getContent() const{
        return this->content;
    }
    void setContent(const E &value){
        this->content = value;
    }

    Node *getNext() const{
        return this->next;
    }
    void setNext(Node *value){
        this->next = value;
    }
};

#endif // NODE_H
