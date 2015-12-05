#ifndef STACKADT_H
#define STACKADT_H

template <typename E> class Stack {
public:
//Limpar a pilha
virtual void clear() = 0;
//Adicionar item à sua pilha
virtual void push(const E& it) = 0;
//Remover item que está no topo da pilha e retorna seu valor
virtual E pop() = 0;
//Retorna valor do item que está no topo da pilha
virtual const E& topValue() const = 0;
//Retorna tamanho da pilha
virtual int length() const = 0;
};

#endif // STACKADT_H

