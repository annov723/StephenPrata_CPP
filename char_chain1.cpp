#include <iostream>

using namespace std;

const int SIZE = 80;
char* left( const char *str, int n = 1 );

int main( void ){
    char sample[SIZE];
    cout << "Write a word: ";
    cin.get( sample, SIZE ); //reads also whitespaces
    char *ps = left( sample, 5 );
    cout << ps << endl;
    delete [] ps;
    ps = left( sample );
    cout << ps << endl;
    delete [] ps;

    return 0;
}

char* left( const char *str, int n ){
    if( n < 0 ) n = 0;
    char *ret = new char[n + 1];
    for( int i = 0; i < n && str[i]; i++ ) ret[i] = str[i];
    ret[n] = '\0';
    return ret; 

}
