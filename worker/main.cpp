#include "worker1.h"

#include <cstring>

const int SIZE = 5;

int main(){
    Waiter bob( "Robert Bik", 314L, 5 );
    Singer beb( "Lola Bup", 23L, 3 );
    Waiter kep;
    Singer bep;

    Worker* workers[4] = {&bob, &beb, &kep, &bep};
    for( int i = 2; i < 4; i++ ) workers[i]->Set();
    cout << endl;

    for( int i = 0; i < 4; i++ ){
        workers[i]->Show();
        cout << endl;
    }



    Worker* boby[SIZE];
    int c;
    for( c = 0; c < SIZE; c++ ){
        char choice;
        cout << "Podaj kategorie: k - kelner, p - piosenkarz, s - spiewajacy kelner, w - wyjscie" << endl;
        cin >> choice;
        while( strchr( "kpsw", choice ) == NULL ){ //sprawdza czy char zawiera ktorys z podanych znakow
            cout << "k, p, s lub w..." << endl;
            cin >> choice;
        }

        if( choice == 'w' ) break;

        switch( choice ){
            case 'k':
                boby[c] = new Waiter;
                break;
            case 'p':
                boby[c] = new Singer;
                break;
            case 's':
                boby[c] = new SingingWaiter;
                break;
            default:
                return 1;
        }
        cin.get();
        boby[c]->Set();
    }

    cout << "Pracownicy" << endl;
    for( int i = 0; i < c; i++ ){
        boby[i]->Show();
        cout << endl;
    }

    for( int i = 0; i < c; i++ ) delete boby[i]; 

    return 0;
}