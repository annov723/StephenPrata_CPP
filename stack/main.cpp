#include "stack.h"

#include <iostream>
#include <cctype>

using namespace std;



int main( void ){
    Stack st;
    char ch;
    Item po;
    cout << "Nacisnij \"D\", aby wprowadzić deklarację, \"P\" żeby przetworzyć deklarację lub \"K\" żeby zakończyć." << endl;
    while( cin >> ch && toupper( ch ) != 'K' ){
        while( cin.get() != '\n' ) continue;

        if( !isalpha( ch ) ){
            cout << "\a"; //sygnał dźwiękowy
            continue; //pobranie danych po raz kolejny (wraca do głównej pętli)
        }
        switch( ch ){
            case 'd':
            case 'D':
                cout << "Podaj numer nowej deklaracji: ";
                cin >> po;
                if( st.isfull() ) cout << "Stos pełny!" << endl;
                else st.push( po );
                break;

            case 'p':
            case 'P':
                if( st.isempty() ) cout << "Stos pusty!" << endl;
                else{
                    st.pop( po );
                    cout << "Przetworzona deklaracja nr " << po << endl;
                }
                break;
        }

        cout << "Nacisnij \"D\", aby wprowadzić deklarację, \"P\" żeby przetworzyć deklarację lub \"K\" żeby zakończyć." << endl;
    }
    st.show();


    return 0;
}