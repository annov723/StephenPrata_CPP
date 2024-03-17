#include "str.h"

/*wywoływanie konstruktora kopiującego
ClassN bob( hop );
classN bob = hop;
ClassN bob = ClassN( hop );
ClassN *bob = new ClassN( hop );s
*/

using namespace std;

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

    cout << endl;

    return 0;   
}

void ref( Str &a ){
    cout << "through ref: " << a << endl;
}

void val( Str a ){
    cout << "through val: " << a << endl;
}