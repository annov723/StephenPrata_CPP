#include <iostream>
#include <cctype>

using namespace std;

void num(){
    static int n = 1;
    cout << "### ZADANIE " << n << " ###" << endl;
    n++;
}

void zad1( string a, int n = 0 );

struct Batonik{
    string marka;
    double waga;
    int cena;
};
void zad2( Batonik *b, string const s = "Millennium Munch", double const d = 9.66, int const c = 350 ){
    b->cena = c;
    b->waga = d;
    b->marka = s;
}
void zad2_show( Batonik const *b ){
    cout << b->marka << ", cena: " << b->cena << ", waga: " << b->waga << endl;
}

string zad3_string( string *a ){
    string::iterator it;
    for( it = a->begin(); it < a->end(); it++ ) *it = toupper( *it );
    return *a;
}
void zad3(){
    string a = "";
    cout << "Podaj lancuch (q, aby skonczyc): ";
        cin >> a;
    while( a != "q" ){
        a = zad3_string( &a );
        cout << a << endl;
        cout << "Podaj lancuch (q, aby skonczyc): ";
        cin >> a;
    }
}




int main( void ){
    num();
    zad1( "test" );
    zad1( "bob", 5 );    
    zad1( "bobek", 5 );

    num();
    Batonik bab = { "lupka", 5.5, 10 };
    zad2( &bab, "kosmos" );
    zad2_show( &bab );

    num();
    zad3();
    




    return 0;
}

void zad1( string a, int n ){
    static int count = 0;
    count++;
    if( n == 0 ){
        cout << a << endl;
        return;
    }
    
    for( int i = 0; i < count; i++ ){
        cout << a << endl;
    }
}