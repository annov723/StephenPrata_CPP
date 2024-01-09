#include <iostream>
#include "namesp.h"



#define SIZE 3

void other( void );
void another( void );



int main( void ){
    using debts::Debt;
    using debts::showDebt;
    Debt riding = { { "Bob", "Kopacz" }, 45.33 };
    showDebt( riding );
    other();
    another();

    return 0;
}

void other( void ){
    using std::cout;
    using std::endl;

    using namespace debts;

    Person dg = { "Daria", "Bobek" };
    showPerson( dg );
    Debt arr[SIZE];
    
    for( int i = 0; i < SIZE; i++ ) getDebt( arr[i] );
    for( int i = 0; i < SIZE; i++ ) showDebt( arr[i] );
    cout << "Suma: " << sumDebts( arr, SIZE ) << endl;
}

void another( void ){
    using std::cout;
    using std::endl;

    using pers::Person;

    Person man = { "Gubby", "Pubby" };
    pers::showPerson( man );
}