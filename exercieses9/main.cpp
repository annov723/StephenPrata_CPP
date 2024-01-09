#include <iostream>
#include "golf.h"

int main( void ){
    //zad1
    using std::cout;
    using std::endl;

    golf a, b, c;
    setgolf( a );
    setgolf( b, "Bubba", 65 );
    setgolf( c );

    if( c.handicap == 0 ) handicap( c, 5 );

    showgolf( a );
    showgolf( b );
    showgolf( c );




    return 0;
}