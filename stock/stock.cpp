#include "stock.h"

Stock::Stock(){
    strcpy( company, "brak nazwy" );
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock( const char *co, int n, double pr ){
    strncpy( company, co, 29 );
    company[29] = '\0';

    if( n < 0 ){
        cerr << "Liczba udziałów nie może być ujemna!" << endl;
        shares = 0;
    }
    else shares = n;

    share_val = pr;
    set_total();
}

Stock::~Stock(){

}

void Stock::buy( int num, double price ){
    if( num < 0 ) cerr << "Nie można nabyć ujemnych udziałów." << endl;
    else{
        shares = shares + num;
        share_val = price;
        set_total();
    }
}

void Stock::sell( int num, double price ){
    if( num < 0 ) cerr << "Nie można sprzedawać ujemnej liczby udziałów." << endl;
    else if( num > shares ) cerr << "Nie można sprzedawać więcej niż się posiada." << endl;
    else{
        shares = shares - num;
        share_val = price;
        set_total();
    }
}

void Stock::update( double price ){
    share_val = price;
    set_total();
}

void Stock::show(){
    cout << "Nazwa: " << company << endl;
    cout << "Liczba udziałów: " << shares << endl;
    cout << "Cena udziału: " << share_val << endl;
    cout << "Łączna wartość udziałów: " << total_val << endl;
}

const Stock & Stock::top_value( const Stock &s ) const{
    if( s.total_val > total_val ) return s;
    else return *this;
}

