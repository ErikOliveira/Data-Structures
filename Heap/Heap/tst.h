#ifndef TST
#define TST
#include <HeapADT.h>
#include <iostream>
#include <QString>
#include <QDebug>
#define Hparent pos/2
#define Hleft 2*pos+1
#define Hright 2*pos+2

using namespace std;

void Assert(bool condicao, std::string s) {
    if (condicao) {
        std::cout << "Falha: " << s << std::endl;
        exit(-1);
    }
}

template <typename E> class MaxHeap: public HeapADT<E>{

private:
    int *data; // Ponteiro para a array heap
    int maxSize; //tamanho maximo da heap
    int n; //numero de elemento atual na heap


public:
    MaxHeap(int size) {
        data = new int[size];
        maxSize = size;
        n = 0;
    }
    ~MaxHeap() {
        delete[] data;
    }
    void heapfy(int pos){
        if(!isLeaf(pos)){
            int temp;
            if(data[pos] < data[Hleft]){
                temp = data[pos];
                data[pos] = data[Hleft];
                data[Hleft] = temp;
            }
            else if(data[pos] < data[Hright]){
                temp = data[pos];
                data[pos] = data[Hright];
                data[Hright] = temp;
            }
        }
    }
    void bubble(int pos){
        if(pos != 0){
            int temp;
            if(data[pos] > data[Hparent]){
                temp = data[pos];
                data[pos] = data[Hparent];
                data[Hparent] = temp;
            }
        }
    }
    int size()const{
        return maxSize;
    }
    bool isLeaf(int pos)const{
        if(Hleft<n)
            return false;
        else
            return true ;
    }
    int leftchild(int pos) const{
        return Hleft;
    }
    rightchild(int pos) const{
        return Hright;
    }
    int parent(int pos) const{
        return Hparent;
    }
    void buildHeap(){
        int j = maxSize/2;
        for(int i = j; i >= 1; i--)
        {
            heapfy(i);
            bubble(i);
        }
    }

    void insert(const E& it){
            Assert(n==maxSize, "Tamanho maximo");
            data[n] = it;
            ++n;
    }
    E get(int pos) const{
        return data[pos];
    }
    void remove(const E& it){
        for (int i = 0; i < n; ++i) {
            if(data[i]==it){
                int x = i;
                while (x<n){
                    data[x] = data[++x];
                }
            }
        }
        n--;
    }


    //Funções auxiliares
    void show(){
        for (int i = 0; i < n; ++i) {
            cout<<data[i]<<endl;
        }
    }
};

template <typename E> class MinHeap: public HeapADT<E>{

private:
    int *data; // Ponteiro para a array heap
    int maxSize; //tamanho maximo da heap
    int n; //numero de elemento atual na heap


public:
    MinHeap(int size) {
        data = new int[size];
        maxSize = size;
        n = 0;
    }
    ~MinHeap() {
        delete[] data;
    }
    void heapfy(int pos){
        if(!isLeaf(pos)){
            int temp;
            if(data[pos] > data[Hleft]){
                temp = data[pos];
                data[pos] = data[Hleft];
                data[Hleft] = temp;
            }
            else if(data[pos] > data[Hright]){
                temp = data[pos];
                data[pos] = data[Hright];
                data[Hright] = temp;
            }
        }
    }
    void bubble(int pos){
        if(pos != 0){
            int temp;
            if(data[pos] < data[Hparent]){
                temp = data[pos];
                data[pos] = data[Hparent];
                data[Hparent] = temp;
            }
        }
    }
    int size()const{
        return maxSize;
    }
    bool isLeaf(int pos)const{
        if(Hleft<n)
            return false;
        else
            return true ;
    }
    int leftchild(int pos) const{
        return Hleft;
    }
    rightchild(int pos) const{
        return Hright;
    }
    int parent(int pos) const{
        return Hparent;
    }
    void buildHeap(){
        int j = maxSize/2;
        for(int i = j; i >= 1; i--)
        {
            heapfy(i);
            bubble(i);
        }
    }

    void insert(const E& it){
         Assert(n==maxSize, "Tamanho maximo");
            data[n] = it;
            ++n;
    }
    E get(int pos) const{
        return data[pos];
    }
    void remove(const E& it){
        for (int i = 0; i < n; ++i) {
            if(data[i]==it){
                int x = i;
                while (x<n){
                    data[x] = data[++x];
                }
            }
        }
        n--;
    }


    //Funções auxiliares
    void show(){
        for (int i = 0; i < n; ++i) {
            cout<<data[i]<<endl;
        }
    }
};

#endif // TST
