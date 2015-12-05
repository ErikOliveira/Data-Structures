#ifndef LISTADT
#define LISTADT

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Editado pelo Ranger Vermelho


template <typename E> class ListADT { // List ADT

private:

    /* Dicas Shows®:
     * Ao declarar um método private numa ADT (Classe Abstrata)
     * eu impeço as filhas dessa classe de criar esse método.
     * Ou seja, eu defino o que não poderá ser implementado na
     * classe que herdar essa ADT.
     */

    void operator =(const ListADT&) {}      // Protejo o operador = para que nenhuma filha possa implementá-lo
    void operator *(const ListADT&) {}      // Faço o mesmo para o operador *
    ListADT(const ListADT&) {}                 // Protejo o construtor de receber uma cópia

public:
    ListADT() {}          // Construtor padrão
    virtual ~ListADT() {} // Destrutor padrão

    // Sobrescreve o operador + para concatenar duas listas
    //virtual ListADT* operator +(const ListADT&) = 0;

    // Limpa o conteúdo da lista, faz ela ficar vazia.
    virtual void clear() = 0;

    // Insere um elemento na atual posição do cursor
    /* Dicas Shows®:
     * Se o cursor está na posição 3, então esse novo elemento
     * ocupará a posição 3, e quem ocupava a posição 3 antes ocupará
     * a 4. E assim sucessivamente...
     */
    virtual void insert(const E& item) = 0;

    // Adiciona um elemento no final da lista
    virtual void append(const E& item) = 0;

    // Remove e retorna o elemento da atual posição do cursor
    virtual E remove() = 0;

    // Move o cursor para o começo da lista
    virtual void moveToStart() = 0;

    // Move o cursor para o fim da lista
    virtual void moveToEnd() = 0;

    // Move o cursor uma célula para a esquerda.
    // Não altera se ele já estiver no começo.
    virtual void prev() = 0;

    // Move o cursor uma cédula para a direita.
    // Não altera se ele já estiver no começo.
    virtual void next() = 0;

    // Retorna o número de elementos da lista
    virtual int length() const = 0;

    // Retorna a atual posição do cursor
    virtual int currPos() const = 0;

    // Move o cursor para uma determinada posição
    // pos: nova posição do cursor
    virtual void moveToPos(int pos) = 0;

    // Retorna o elemento da atual posição do cursor
    virtual const E& getValue() const = 0;

};


#endif // LISTADT
