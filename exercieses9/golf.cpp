#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf ( golf &g , const char *name , int hc ){
    strcpy( g.fullname, name );
    g.handicap = hc;
}

void setgolf ( golf &g ){
    using std::cin;
    using std::cout;
    
    int hc;
    char name[LEN];
    cout << "Podaj nazwe: ";
    if( cin >> name ) strcpy( g.fullname, name );
    else g.fullname[0] = '\0';

    while( getchar() != '\n' ) continue;

    cout << "Podaj handicap: ";
    if( cin >> hc ) g.handicap = hc;
    else g.handicap = 0;

    while( getchar() != '\n' ) continue;

    cin.clear();
}

void handicap ( golf & g , int hc ){
    g.handicap = hc;
}

void showgolf ( const golf & g ) {
    using std::cout;
    using std::endl;
    
    cout << g.fullname << " " << g.handicap << endl;
}
