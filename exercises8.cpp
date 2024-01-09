#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

void num(){
    static int n = 1;
    cout << "### ZADANIE " << n << " ###" << endl;
    n++;
}

//zad1
void zad1( string a, int n = 0 );

//zad2
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

//zad3
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

//zad6
template<typename T>
void Show( vector<T> vec ){
    cout << "ARRAY" << endl;
    for( auto i : vec ) cout << i << " ";
    cout << endl;
}

template<typename T>
void sum( vector<T> vec ){
    T sum = 0;
    for( auto i : vec ) sum = sum + i;
    cout << "Sum = " << sum << endl; 
}

void sum( vector<string> vec, char s ){
    int sum = 0;
    for( int i = 0; i < vec.size(); i++ ){
        for( int j = 0; j < vec[i].length(); j++ ){
            if( vec[i][j] == s ) sum++;
        }
    }
    cout << "Sum = " << sum << endl; 
}

template<typename T>
void min( vector<T> vec ){ //the smallest element
    T ret = vec[0];
    for( auto i : vec ){
        if( ret > i ) ret = i;
    }
    cout << "Min = " << ret << endl; 
}

template <> void min<string>( vector<string> vec ){ //the shortest element
    string ret = vec[0];
    for( int i = 0; i < vec.size(); i++ ){
        if( vec[i].length() < ret.length() ) ret = vec[i];
    }
    cout << "Min = " << ret << endl; 
}

template<typename T>
T elem( vector<T> vec, int num ){
    if( num < 1 ) return 0;
    return vec[num - 1];
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

    num();
    vector<int> int1;
    vector<double> dou2;
    vector<string> str3;
    int1.push_back( 3 );
    int1.push_back( 90 );
    int1.push_back( 54 );
    dou2.push_back( 5.6 );
    dou2.push_back( 0.33 );
    dou2.push_back( 9.433 );
    str3.push_back( "bob" );
    str3.push_back( "sunny" );
    str3.push_back( "dinner" );

    Show( int1 );
    Show( dou2 );
    Show( str3 );
    cout << endl;
    sum( int1 );
    sum( dou2 );
    sum( str3, 'n' );
    cout << endl;
    min( int1 );
    min( dou2 );
    min( str3 );
    cout << endl;
    cout << elem( int1, 3 ) << " " << elem( dou2, 1 ) << " " << elem( str3, 2 ) << endl;
    




    return 0;
}

//zad1
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