#ifndef NODE_H
#define NODE_H
#include <QDebug>

template <typename E> class Node{
    E content;
    Node* left;
    Node* right;
public:
    Node(){
        this->setLeft(NULL);
        this->setRight(NULL);
    }
    ~Node(){

    }

    Node(const E &content, Node* leftchildren, Node* rightchildren){
        this->setContent(content);
        this->setLeft(leftchildren);
        this->setRight(rightchildren);
    }

    bool isLeaf(){
        return ((left == NULL) && (right == NULL));
    }

    E getContent() const
    {
        return content;
    }
    void setContent(const E &value)
    {
        content = value;
    }

    Node *getLeft() const
    {
        return left;
    }
    void setLeft(Node *value)
    {
        left = value;
    }

    Node *getRight() const
    {
        return right;
    }
    void setRight(Node *value)
    {
        right = value;
    }
};

#endif // NODE_H
