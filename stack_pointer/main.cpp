#include "stacktp.h"
#include "stacktp.cpp"

#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>

const int NUM = 10;

using namespace std;

int main(){
    srand( time( 0 ) );
    cout << "Rozmiar stosu: ";
    int stackSize;
    cin >> stackSize;

    Stack<const char*> stos( stackSize );
    const char* in[NUM]={
        "1: H e n r y k G i l g a m e s z" , "2: K i n g a I s z t a r" ,
        "3: B e a t a Ro k e r" , "4: J a n F l a g r a n t i" ,
        "5: W o l f g a n g M o c n y" , "7: P a t r y c j a K u p" ,
        "6: J a c e k A l m o n d" , "8: K s a w e r y P a p r y k a" ,
        "9: J u l i a n M o r" , "10: M a r i a n M a c h e r"
    };

    const char *out[NUM];

    int processed = 0;
    int next = 0;
    while( processed < NUM ){
        if( stos.isEmpty() ) stos.push( in[next++] );
        else if( stos.isFull() ) stos.pop( out[processed++] );
        else if( rand() % 2 && next < NUM ) stos.push( in[ next++] );
        else stos.pop( out[processed++] );
    }

    for( int i = 0; i < NUM; i++ ) cout << out[i] << endl;
    
}