#include <QCoreApplication>
#include "lbs.h"
#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

string nome;
string idade;
string endereco;
string tlf;
string titulo;
string anopub;
string author;
string pubco;

int main(){

    int execution_flag = 1;
    int choose_operation = -1;
    cout << "\t\t------------- Welcome to LibSys 3.0 -------------" << endl;
    LbSys<QString> *p = new LbSys<QString>();

    while(execution_flag){
        switch (choose_operation) {
        case 0:
            execution_flag = 0;
            break;

        case 1:
        {
            cout << "Type User's Name..." << endl;
            getline(cin,nome);
            cout << "Type User's Age..." << endl;
            getline(cin,idade);
            cout << "Type User's Post-Mail..." << endl;
            getline(cin,endereco);
            cout << "Type User's Telephone number" << endl;
            getline(cin,tlf);
            p->regUser(nome.c_str(),idade.c_str(),endereco.c_str(),tlf.c_str());
            choose_operation = -1;
            break;
        }

        case 2:
        {
            cout << "Type its book name..." << endl;
            getline(cin,titulo);
            cout << "Type the publisher's year of it..." << endl;
            getline(cin,anopub);
            cout << "Type Author's user name of it..." << endl;
            getline(cin,author);
            cout << "Type Publisher's Co. name of it" << endl;
            getline(cin,pubco);
            p->regBook(titulo.c_str(),anopub.c_str(),author.c_str(),pubco.c_str());
            choose_operation = -1;
            break;
        }

        case 3:
        {
            cout << "Type the User's name that you wanted uregistered." << endl;
            getline(cin,nome);
            p->unrUser(nome.c_str());
            choose_operation = -1;
            break;
        }

        case 4:
        {
            cout << "Type its Book name that you wanted uregistered." << endl;
            getline(cin,titulo);
            p->unrBook(titulo.c_str());
            choose_operation = -1;
            break;
        }

        case 5:
        {
            cout << "Type the User's name that's try get borrow the book..." << endl;
            getline(cin,nome);
            cout << "... Now type Book name" << endl;
            getline(cin,titulo);
            cout << "Ok, that's all I need" << endl;
            p->getRent(nome.c_str(),titulo.c_str());
            choose_operation = -1;
            break;
        }

        case 6:
        {
            cout << "Type the User's name that's try give back the book..." << endl;
            getline(cin,nome);
            cout<<"... Now type Book name" << endl;
            getline(cin,titulo);
            p->getUnrt(nome.c_str(),titulo.c_str());
            choose_operation = -1;
            break;
        }

        case 7:
        {
            p->listUsers();
            choose_operation = -1;
            break;
        }

        case 8:
        {
            p->listTitles();
            choose_operation = -1;
            break;
        }

        case 9:
        {
            cout << "Type a Book name..." << endl;
            getline(cin,titulo);
            Node<QString>* aux = p->findaBook(titulo.c_str());
            if(aux)
                cout<< (p->bookInfo(aux)).toStdString();
            else
                cout << "\tSorry! But, It's seems doesn't exists in our database. :(" << endl;
            choose_operation = -1;
            break;
        }

        case 10:
        {
            cout << "Type an User's name..." << endl;
            getline(cin,nome);
            Node<QString>* aux = p->findaUser(nome.c_str());
            if(aux)
                cout<< (p->userInfo(aux)).toStdString();
            else
                cout<<"Sorry none user was registered with this name... :("<<"\t check the typed name and try again..."<<endl;
            choose_operation = -1;
            break;
        }

        default:
            cout<< endl << "Choose a command, typing the correspondent number:" << endl << "(1): Register a new User"
               << endl << "(2): Register a new Book" << endl << "(3): Unregister an User" << endl << "(4): Unregister a Book"
               << endl << "(5): Borrow a book" << endl << "(6): Give a Book back" << endl << "(7): List all registered User"
               << endl << "(8): List all registered Book" << endl << "(9): Search for a Book" << endl
               << "(10): Search for an User" << endl << "(0) Shutdown the sistem" << endl;
            cin >> choose_operation;
            getchar();
            break;
        }
    }
    return 0;
}
