#ifndef QUEUEADT_H
#define QUEUEADT_H


template <typename E> class QueueADT {
public:
//Limpar Fila
virtual void clear() = 0;
//Enfileirar
virtual void enqueue(const E& it) = 0;
//Desenfileirar
virtual E dequeue() = 0;
//Retorna valor da frente
virtual const E& frontValue() const = 0;
//Retorna tamanho da fila
virtual int length() const = 0;
};

#endif // QUEUEADT_H

