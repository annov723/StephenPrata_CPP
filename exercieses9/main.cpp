#include <iostream>
#include <cstring>
#include "golf.h"
#include "names.h"

//zad3
struct chaff{
    char doss[20];
    int slag;
};

char buffer[500];

int main( void ){
    //zad1
    /*using std::cout;
    using std::endl;

    golf a, b, c;
    setgolf( a );
    setgolf( b, "Bubba", 65 );
    setgolf( c );

    if( c.handicap == 0 ) handicap( c, 5 );

    showgolf( a );
    showgolf( b );
    showgolf( c );*/

    //zad3
    /*using namespace std;

    chaff *one, *two;
    one = new ( buffer ) chaff[2];
    char name1[20] = "bob", name2[20] = "loop";
    strcpy( one[0].doss, name1 ); 
    strcpy( one[1].doss, name2 ); 
    one[0].slag = 99;
    one[1].slag = 67;
    for( int i = 0; i < 2; i++ ) cout << one[i].doss << " " << one[i].slag << endl;*/



    return 0;
}