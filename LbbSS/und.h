#ifndef UND
#define UND
#include <QDebug>

class UserNode{
private:
    QString name;
    QString age;
    QString adds;
    QString phone;
    QString course;
    int Bks;
    UserNode* next;
public:
    UserNode(QString nm, QString yOld, QString addrs, QString phn, QString crs){
        this->setName(nm);
        this->setAge(yOld);
        this->setAdds(addrs);
        this->setPhone(phn);
        this->setCourse(crs);
        this->setBks(0);
        this->setNext(NULL);
    }
    void emprestar(QString &Tt){
        if(getBks()>=3)
            qDebug()<<"You exceed the maximum number of books rented. Try give one back!";
    }

    QString getName() const{
        return name;
    }
    void setName(const QString &value){
        this->name = value;
    }

    QString getAge() const{
        return age;
    }
    void setAge(const QString &value){
        this->age = value;
    }

    QString getAdds() const{
        return adds;
    }
    void setAdds(const QString &value){
        this->adds = value;
    }

    QString getPhone() const{
        return phone;
    }
    void setPhone(const QString &value){
        this->phone = value;
    }

    QString getCourse() const{
        return course;
    }
    void setCourse(const QString &value){
        this->course = value;
    }

    int getBks() const{
        return Bks;
    }
    void setBks(int value){
        this->Bks = value;
    }

    UserNode *getNext() const{
        return next;
    }
    void setNext(UserNode* value)
    {
        this->next = value;
    }
};
#endif // UND
