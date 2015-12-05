#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <QDebug>
#include "heapadt.h"



template <typename E> class MaxHeap
{
    E* heap;
    int max_size;
    int sz;

public:
    MaxHeap(int maximum_size){
        heap = new E[maximum_size];
        sz = 0;
        max_size = maximum_size;
    }

    ~MaxHeap(){
        delete heap;
        heap = NULL;
    }

    int size() const{
        return sz;
    }

    bool isLeaf(int pos) const{
        if(pos>=0 && pos<max_size){

        }
    }
};

#endif // MAXHEAP_H
