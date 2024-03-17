#include "str.h"

#include <ctime>
#include <cstdlib>

/*wywoływanie konstruktora kopiującego
ClassN bob( hop );
classN bob = hop;
ClassN bob = ClassN( hop );
ClassN *bob = new ClassN( hop );s
*/

using namespace std;

const int AR_SIZE = 10;

void ref( Str & );
void val( Str );

int main( void ){
    Str one( "Bob" );
    Str two( "Pup" );
    Str three( "Loop" );

    cout << "nowa wiadomosc: " << one << endl;
    cout << "nowa wiadomosc: " << two << endl;
    cout << "nowa wiadomosc: " << three << endl;

    cout << endl;

    ref( one );
    cout << "nowa wiadomosc: " << one << endl;
    val( two ); //psuje nam two, bo orzekazywanie obiektu przez wartość powoduje wywołanie konstruktora kopiującego!
    cout << "nowa wiadomosc: " << two << endl;

    cout << endl;
    
    //domyślny konstruktor kopiujący nie rusza statycznej składowej klasy!
    //jak mamy jawny konstruktor kopiujący to wtedy na potrzebę funkcji utworzy się nowy obiekt,a po jej wywołaniu zostanie zniszczony
    Str four = one;
    cout << "nowa wiadomosc: " << one << endl;
    cout << "nowa wiadomosc: " << four << endl;

    cout << endl;

    Str five;
    //musimy overload operator przypisania, bo bez tego tworzy się obiekt który wskazuje na elementy obiektu do niego przypisanego
    five = one;
    cout << "nowa wiadomosc: " << one << endl;
    cout << "nowa wiadomosc: " << five << endl;

    cout << "\n\n\n";

    Str name;
    cout << "Podaj imie: ";
    cin >> name;

    Str favs[AR_SIZE];
    char temp[Str::get_max()];
    int total;
    cout << "Wpisz swoje ulubione rzeczy (max " << AR_SIZE << ") - wcisnij enter aby zakonczyc wprowadzanie:" << endl;
    for( total = 0; total < AR_SIZE; total++ ){
        cout << total + 1 << ". ";
        cin.get( temp, Str::get_max() );

        while( cin && cin.get() != '\n' ) continue; //czyścimy buffer

        if( !cin || temp[0] == '\0' ) break; //sprawdzamy czy nie ma pustego wiersza

        else favs[total] = temp;
    }

    if( total > 0 ){
        cout << "Twoje ulubione rzeczy:" << endl;
        for( int i = 0; i < total; i++ ) cout << i + 1 << ": " << favs[i] << endl;

        int shortest = 0;
        int alfa = 0;
        for( int i = 1; i < total; i++ ){
            if( favs[i].lenght() < favs[shortest].lenght() ) shortest  = i;
            if( favs[i] < favs[alfa] ) alfa = i;
        }

        cout << "Najkrotsze: " << favs[shortest] << endl;
        cout << "Pierwsze alfabetycznie: " << favs[alfa] << endl;

        cout <<  endl;
        cout << ( favs[0] + favs[1] ) << endl; //w funkcji powstaje nam nowy obiekt, który ulega destrukcji po zakończeniu funkcji
        cout << endl;

        srand( time( 0 ) );
        int choice = rand() % total;
        Str *fav = new Str( favs[choice] );
        cout << "Ja najbardziej z twoich rzeczy lubie: " << *fav << endl;
        delete fav;
    }
    else cout << "Jak nie to nie" << endl;
    



    return 0;   
}

void ref( Str &a ){
    cout << "through ref: " << a << endl;
}

void val( Str a ){
    cout << "through val: " << a << endl;
}