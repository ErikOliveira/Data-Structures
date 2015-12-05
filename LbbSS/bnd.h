#ifndef BND
#define BND
#include <cstddef>
#include <qdebug.h>

class BookNode{
private:
    QString ttl;
    QString athr;
    QString pub_yr;
    int dsp;
    QString who;
    BookNode* next;
public:
    BookNode(QString ttlr, QString authr, QString pubyr){
        this->setTtl(ttlr);
        this->setAthr(authr);
        this->setPubyr(pubyr);
        this->setDsp(1);
        this->setWho(NULL);
        this->setNext(NULL);
    }
    QString getTtl() const{
        return ttl;
    }
    void setTtl(const QString &value){
        this->ttl=value;
    }
    QString getAthr() const{
        return athr;
    }
    void setAthr(const QString &value){
        this->athr = value;
    }
    QString getPubyr() const{
        return pub_yr;
    }
    void setPubyr(const QString &value){
        this->pub_yr = value;
    }

    int getDsp() const{
        return dsp;
    }
    void setDsp(int value){
        this->dsp=value;
    }

    QString getWho() const{
        return who;
    }
    void setWho(const QString &value){
        this->who = value;
    }

    BookNode *getNext() const{
        return next;
    }
    void setNext(BookNode *value){
        this->next=value;
    }
};

#endif // BND
