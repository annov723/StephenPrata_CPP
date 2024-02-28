#include "stone.h"

int main(){

    using std::cout;
    using std::endl;

    Stone pop( 9, 2.8 );
    double pup = pop; //konwersja overloading
    cout << "Konwersja na typ double: " << pup << endl;
    cout << "Konwersja na typ int: " << ( int ) pop << endl; // int( pop )
    cout << "Jeszcze raz double: " << double( pop ) << endl;

    Stone total;
    total = total + pop;

    return 0;
}