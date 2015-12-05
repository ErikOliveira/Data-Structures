#ifndef BTREE_H
#define BTREE_H
#include <QDebug>
#include "treeadt.h"

template <typename E> class BTree:public BinTree<E>{

    Node<E>* root; //Root tree node pointer
    Node<E>* current; //Current tree node pointered to

    //Implementation of a helper method to build a new node and add on it
    void Helper_add_node(const E &item, Node<E> *&apontador, Node<E>*& raiz){
        if(item < apontador->getContent()){
            if(current->getLeft()){
                //qDebug()<<"going to left";
                this->toLeft();
                this->Helper_add_node(item,apontador,raiz);
            }
            else{
                Node<E>* build_new_item_node_here = new Node<E>(item,NULL,NULL);
                apontador->setLeft(build_new_item_node_here);
                apontador = raiz;
                //qDebug()<<"left node added";
            }
        }
        else if(item > apontador->getContent()){
            if(apontador->getRight()){
                //qDebug()<<"going to right";
                this->toRight();
                this->Helper_add_node(item,apontador,raiz);
            }
            else{
                Node<E>* build_new_node_here = new Node<E>(item,NULL,NULL);
                apontador->setRight(build_new_node_here);
                apontador = raiz;
                //qDebug()<<"right node added";
            }
        }
    }

    //Implementation of a helper method to add subtree
    void Helper_add_subtree(Node<E>*& node, Node<E> *&apontador, Node<E> *&raiz){
        if(node){
            if(node->getContent() < apontador->getContent()){
                if(apontador->getLeft()){
                    //qDebug()<<"going by left";
                    this->toLeft();
                    this->Helper_add_subtree(node,apontador,raiz);
                }
                else{
                    apontador->setLeft(node);
                    apontador = raiz;
                    //qDebug()<<"left node linked";
                }
            }
            else if(node->getContent() > apontador->getContent()){
                if(apontador->getRight()){
                    //qDebug()<<"going by right";
                    this->toRight();
                    this->Helper_add_subtree(node,apontador,raiz);
                }
                else{
                    apontador->setRight(node);
                    apontador = raiz;
                    //qDebug()<<"right node linked";
                }
            }
        }
    }

    //Implementation of a helper method to search for a node
    void Helper_finder_node(const E& item, Node<E>*& searched_node_address_here, Node<E>*& parent_searched_node_here, Node<E>*& apontador){
        //qDebug()<<"Start over:";
        if(apontador){
            //qDebug()<<"that's a valid pointer";
            if(apontador->getContent() == item){
                //qDebug()<<"found what I want";
                searched_node_address_here = apontador;
                return;
            }
            else{
                //qDebug()<<"Dive in";
                Node<E>* sub_left_tree = apontador->getLeft();
                Node<E>* sub_right_tree = apontador->getRight();
                Helper_finder_node(item,searched_node_address_here,parent_searched_node_here,sub_left_tree);
                Helper_finder_node(item,searched_node_address_here,parent_searched_node_here,sub_right_tree);

                if(apontador->getLeft() == searched_node_address_here || apontador->getRight() == searched_node_address_here){
                    //qDebug()<<"parent node setting";
                    parent_searched_node_here = apontador;
                }
            }
        }
    }

    //Implementation of a helper method for get all tree node's content preodered into a string
    void Helper_preorder_stringizer(QString*& preordering_into_it, Node<E>* apontador){
        if(apontador){
            if(apontador->isLeaf()){
                preordering_into_it->append(apontador->getContent());
                return;
            }
            else{
                preordering_into_it->append(apontador->getContent());
                Helper_preorder_stringizer(preordering_into_it,apontador->getLeft());
                Helper_preorder_stringizer(preordering_into_it,apontador->getRight());
            }
        }
    }


    //Implementation of a helper method to look for the lowest node content in the tree
    void Helper_lower_node_content(E& lowerContent,Node<E>* apontador){
        //qDebug()<<"Start over:";
        if(apontador){
            if(apontador->isLeaf()){
                //qDebug()<<"leaf node reach";
                if(apontador->getContent() < lowerContent){
                    //qDebug()<<"... and it had low content";
                    lowerContent = apontador->getContent();
                }
                return;
            }
            else{
                //qDebug()<<"Dive in";
                if(apontador->getContent() < lowerContent){
                    //qDebug()<<"Non-leaf node had low content";
                    lowerContent = apontador->getContent();
                }

                Helper_lower_node_content(lowerContent,apontador->getLeft());
                Helper_lower_node_content(lowerContent,apontador->getRight());
            }
        }
    }

    //Implementation of a helper method to look for the greatest node content in the tree
    void Helper_greater_node_content(E& greaterContent, Node<E>* apontador){
        //qDebug()<<"Start over:";
        if(apontador){
            if(apontador->isLeaf()){
                //qDebug()<<"leaf node is reach";
                if(apontador->getContent() > greaterContent){
                    //qDebug()<<"... and its had a greater value";
                    greaterContent = apontador->getContent();
                    return;
                }
            }
            else{
                //qDebug()<<"Dive in";
                if(apontador->getContent() > greaterContent){
                    //qDebug()<<"Non-leaf node had greater content";
                    greaterContent = apontador->getContent();
                }
                Helper_greater_node_content(greaterContent,apontador->getLeft());
                Helper_greater_node_content(greaterContent,apontador->getRight());
            }
        }
    }

    //Implementation of a helper method to counting internal nodes or leafs, behaviour controller by a bool flag to Toggle
    static void Helper_counting_any_node_or_leafs(int& numberNodes, Node<E>* apontador, bool toggle_any_or_just_leafs_count){
        //qDebug()<<"Start over:";
        if(apontador){
            if(apontador->isLeaf()){
                numberNodes++;
                return;
            }
            else{
                //qDebug()<<"Dive in";
                if(toggle_any_or_just_leafs_count)
                    numberNodes++;
                Helper_counting_any_node_or_leafs(numberNodes,apontador->getLeft(),toggle_any_or_just_leafs_count);
                Helper_counting_any_node_or_leafs(numberNodes,apontador->getRight(),toggle_any_or_just_leafs_count);
            }
        }
    }

    //Implementatiton of a helper to calculate the height/maximum level of the tree
    static int Helper_height(Node<E>* apontador){
        int left = 0;
        if(apontador->getLeft())
            left = Helper_height(apontador->getLeft());
        int right = 0;
        if(apontador->getRight())
            right = Helper_height(apontador->getRight());

        return 1+((left+right+qAbs(left-right))/2);
    }

    //Implementation of helper method to counting the current pointered node level
    static void Helper_level(const E& target, bool &toggleCountPermission, Node<E>*& apontador, int &level){
        //qDebug()<<"Start over:";
        if(apontador){
            //qDebug()<<"that's a valid pointer";
            if(apontador->getContent() == target){
                //qDebug()<<"found what I want";
                toggleCountPermission = true;
                return;
            }
            else{
                //qDebug()<<"Dive in";
                if(!toggleCountPermission){
                    Node<E>* sub_left_tree = apontador->getLeft();
                    Helper_level(target,toggleCountPermission,sub_left_tree, level);
                }

                if(!toggleCountPermission){
                    Node<E>* sub_right_tree = apontador->getRight();
                    Helper_level(target,toggleCountPermission,sub_right_tree, level);
                }

                if(toggleCountPermission){
                    //qDebug()<<"counting now";
                    level++;
                }
            }
        }
    }

public:
    BTree()
    {
        current = root = NULL;
    }

    BTree(Node<E>*& sub){
        root = sub;
        current = root;
    }

    ~BTree()
    {
        this->clear();
        delete current;
        delete root;
        current = root = NULL;
    }

    void add(const E &item){
        if(!root){
            root = new Node<E>(item,NULL,NULL);
            current = root;
            //qDebug()<<"root node added";
        }
        else{
            current = root;
            this->Helper_add_node(item,current,root);
        }
    }

    void remove(E item){
        if(root){
            if(root->getContent() == item){
                if(root->isLeaf()){
                    delete root;
                    root = current = NULL;
                }
                else{
                    Node<E>* holder_old_root_node_here = root;
                    Node<E>* holder_right_sub_tree_here = root->getRight();
                    root = root->getLeft();
                    delete holder_old_root_node_here;
                    holder_old_root_node_here = NULL;
                    current = root;
                    this->addSubTree(holder_right_sub_tree_here);
                }
            }
            else{
                //qDebug()<<"Non-root node to remove";
                current = root;
                Node<E>* search_for_it = NULL;
                Node<E>* holder_parent_node = NULL;
                this->Helper_finder_node(item,search_for_it,holder_parent_node,current);
                if(search_for_it){
                    //qDebug()<<"Helper finder provide a node to be removed";
                    Node<E>* Holder_left_subtree = search_for_it->getLeft();
                    Node<E>* Holder_right_subtree = search_for_it->getRight();
                    if(holder_parent_node->getLeft() == search_for_it || holder_parent_node->getRight() == search_for_it){
                        //qDebug()<<"Helper provide a parent node that was linked with that to remove one";
                        if(holder_parent_node->getLeft() == search_for_it){
                            //qDebug()<<"left match";
                            holder_parent_node->setLeft(NULL);
                            delete search_for_it;
                        }
                        if(holder_parent_node->getRight() == search_for_it){
                            //qDebug()<<"right match";
                            holder_parent_node->setRight(NULL);
                            delete search_for_it;
                        }
                    }
                    this->addSubTree(Holder_left_subtree);
                    this->addSubTree(Holder_right_subtree);
                }
                else
                    qDebug()<<"None node element match with item passed to. Nothing was change!";
            }
        }
        else
            qDebug()<<"Empty tree! Nothing to do :D";
        current = root;
    }

    void clear(){
        if(root){
            current = root;
            while(!current->isLeaf()){
                this->remove(current->getContent());
            }
            this->remove(current->getContent());
        }
    }

    bool inTree(const E item){
        Node<E>* holder_parent_node = NULL;
        Node<E>* holder_item_node_here = NULL;
        current = root;
        this->Helper_finder_node(item,holder_item_node_here,holder_parent_node,current);
        current = root;
        return holder_item_node_here;
    }

    const E lower(){
        if(root){
            current = root;
            E lower = root->getContent();
            this->Helper_lower_node_content(lower,current);
            current = root;
            return lower;
        }
        else{
            qDebug()<<"Empty tree! Null was returned by default";
            return NULL;
        }
    }

    const E greater(){
        if(root){
            current = root;
            E greater = root->getContent();
            this->Helper_greater_node_content(greater,current);
            current = root;
            return greater;
        }
        else{
            qDebug()<<"Empty tree! Null was returned by default";
            return NULL;
        }
    }

    QString toString(){
        QString* tree_preordered_here = new QString();
        current = root;
        this->Helper_preorder_stringizer(tree_preordered_here,current);

        current = root;
        return *tree_preordered_here;
    }

    int countNode() const{
        if(root){
            int n_nodes = 0;
            Helper_counting_any_node_or_leafs(n_nodes,root,true);
            return n_nodes;
        }
        else{
            qDebug()<<"Empty tree! Zero was returned by default";
            return 0;
        }
    }

    int countLevel() const{
        if(root){
            int level = 0;
            Node<E>* pseudoRoot = root;
            bool tggcount = false;
            Helper_level(this->getHere(), tggcount,pseudoRoot,level);
            return level;
        }
        else{
            qDebug()<<"Empty tree! Zero was returned by default";
            return 0;
        }
    }

    int countLeaf() const{
        if(root){
            int n_leafs = 0;
            Helper_counting_any_node_or_leafs(n_leafs,root,false);
            return n_leafs;
        }
        else {
            qDebug()<<"Empty tree! Zero was returned by default";
            return 0;
        }
    }

    int height() const{
        if(root){
            return Helper_height(root);
        }
        else{
            qDebug()<<"Empty tree! Zero was returned by default";
            return 0;
        }
    }

    const Node<E>* getTree(){
        return root;
    }

    void addSubTree(Node<E>*& node){
        if(!root)
            current = root = node;
        else{
            current = root;
            this->Helper_add_subtree(node,current,root);
        }
    }

    void toLeft(){
        if(current)
            current = current->getLeft();
    }

    void toRight(){
        if(current)
            current = current->getRight();
    }

    const E getHere() const{
        if(current)
            return current->getContent();
        else{
            qDebug()<<"Current is nullpointer, and its was returned by default";
            return NULL;
        }
    }
};

#endif // BTREE_H
