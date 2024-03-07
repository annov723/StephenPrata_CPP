#include "stock.h"

#define STK 3

int main( void ){
    Stock stocks[STK] = {
        Stock( "Nano", 5, 2.22 ),
        Stock( "Bob-ek", 2, 0.11 ),
        Stock( "Supas", 90, 2 )
    };

    cout.precision( 2 ); //ustawienie formatu z 2 miejscami po przecinku
    cout.setf( ios_base::fixed, ios_base::floatfield );
    cout.setf( ios_base::showpoint );

    Stock top = stocks[0];
    for( int i = 0; i < STK; i++ ) top = top.top_value( stocks[ i ] );
    cout << "Najbardziej wartościowe udziały..." << endl;
    top.show();

    return 0;
}