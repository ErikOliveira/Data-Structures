#ifndef NODE
#define NODE
template <typename E> class Node{
private:
    E field1;
    E field2;
    E field3;
    E field4;
    E field5;
    int num;
    Node* next;
public:
    Node(const E& nm_ttlr, const E& age_yrpub,const E& addrs_athr,const E& phn_publshr){
        this->setField1(nm_ttlr);
        this->setField2(age_yrpub);
        this->setField3(addrs_athr);
        this->setField4(phn_publshr);
        this->setNext(NULL);
        this->setField5(NULL);
    }
    E getField1() const
    {
        return field1;
    }
    void setField1(const E &value)
    {
        field1 = value;
    }
    E getField2() const
    {
        return field2;
    }
    void setField2(const E &value)
    {
        field2 = value;
    }
    E getField3() const
    {
        return field3;
    }
    void setField3(const E &value)
    {
        field3 = value;
    }
    E getField4() const
    {
        return field4;
    }
    void setField4(const E &value)
    {
        field4 = value;
    }
    int getNum() const
    {
        return num;
    }
    void setNum(int value)
    {
        num = value;
    }
    Node *getNext() const
    {
        return next;
    }
    void setNext(Node *value)
    {
        next = value;
    }
    E getField5() const
    {
        return field5;
    }
    void setField5(const E &value)
    {
        field5 = value;
    }
};
#endif // NODE
