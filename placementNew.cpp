#include <iostream>
#include <new>

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF]; //alokacje w buferze nie podlegają dealokacji



int main( void ){
    double *pd1, *pd2;

    cout << "Wywołanie new zwykłego i miejscowego #1:" << endl;
    pd1 = new double[ N ];
    pd2 = new ( buffer ) double[ N ];
    for( int i = 0; i < N; i++ ){
        pd2[ i ] = pd1[ i ] = 1000 + 20.0 * i;
    } 

    cout << "Adresy buforów" << endl;
    cout << "sterta: " << pd1 << endl;
    cout << "pamięć statyczna: " << ( void * ) buffer << endl;
    cout << "zawartość bufora:" << endl;
    for( int i = 0; i < N; i++ ){
        cout << pd1[ i ] << ", adres: " << &pd1[ i ] << " | " << pd2[ i ] << ", adres: " << &pd2[ i ] << endl;
    }

    cout << "Wywołanie new zwykłego i miejscowego #2:" << endl;
    double *pd3, *pd4;
    pd3 = new double[ N ];
    pd4 = new ( buffer ) double[ N ]; //alokowane od początku bufora, wykorzystuje to samo miejsce co pd2
    for( int i = 0; i < N; i++ ){
        pd3[ i ] = pd4[ i ] = 1000 + 20.0 * i;
    }
    cout << "zawartość bufora:" << endl;
    for( int i = 0; i < N; i++ ){
        cout << pd3[ i ] << ", adres: " << &pd3[ i ] << " | " << pd4[ i ] << ", adres: " << &pd4[ i ] << endl;
    }

    cout << "Wywołanie new zwykłego i miejscowego #3:" << endl;
    delete [] pd1;
    pd1 = new double[ N ]; //jest alokowana znowu od tego samego miejsca co poprzednio
    pd2 = new ( buffer + N * sizeof( double ) ) double[ N ]; //alokujemy pamięć przesuniętą o N elementów od początku bufera
    for( int i = 0; i < N; i++ ){
        pd2[ i ] = pd1[ i ] = 1000 + 20.0 * i;
    }
    cout << "zawartość bufora:" << endl;
    for( int i = 0; i < N; i++ ){
        cout << pd1[ i ] << ", adres: " << &pd1[ i ] << " | " << pd2[ i ] << ", adres: " << &pd2[ i ] << endl;
    }

    delete [] pd1;
    delete [] pd3;



    return 0;
}