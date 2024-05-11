#include "worker1.h"

//nawet czystowirtualny destruktor musi zostać zaimplementowany
Worker::~Worker() {}

void Worker::Data() const{
    cout << "Nazwa: " << fullname << endl;
    cout << "Id: " << id <<  endl;
}

void Worker::Get(){
    cout << "Podaj nazwe: ";
    getline( cin, fullname );
    cout << "Podaj id: ";
    cin >> id;
    while( cin.get() != '\n' ) continue;
}



void Waiter::Set(){
    Worker::Get();
    Get();
}

void Waiter::Show() const{
    cout << "Kelner" << endl;
    Worker::Data();
    Data();
}

void Waiter::Data() const{
    cout << "Elegancja: " << panache << endl;
}

void Waiter::Get(){
    cout << "Podaj elegancje: ";
    cin >> panache;
    while( cin.get() != '\n' ) continue;
}


char* Singer::pv[] = {"inny", "alt", "kontralt", "sopran", "bas", "baryton", "tenor"};

void Singer::Set(){
    Worker::Get();
    Get();
}

void Singer::Show() const{
    cout << "Piosenkarz" << endl;
    Worker::Data();
    Data();
}

void Singer::Data() const{
    cout << "Glos: " << pv[voice] << endl;
}

void Singer::Get(){
    cout << "Podaj numer skali glosu:" << endl;
    for( int i = 0; i < Vtypes; i++ ){
        cout << i << ": " << pv[i] << endl;
    }
    cin >> voice;
    while( cin.get() != '\n' ) continue;
}


void SingingWaiter::Data() const{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get(){
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set(){
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const{
    cout << "Śpiewający kelner" << endl;
    Worker::Data();
    Data();
}