#include<iostream>

using namespace std;

#define SIZE 10

void strcount( const char* str );



int main( void ){
    char input[SIZE];
    char next;

    cout << "Enter a line: " << endl;
    cin.get( input, SIZE );
    while( cin ){
        cin.get( next );
        while( next != '\n' ) cin.get( next ); //if the line doesn't fit in the buffor, we have to clear the line
        strcount( input );
        cout << "Enter the next line (empty line ends the program):" << endl;
        cin.get( input, SIZE );
    }

    cout << "Goodbye!" << endl;



    return 0;
}



void strcount( const char* str ){
    static int total = 0;
    int count = 0;

    cout << str << " consists of ";
    while( *str++ ) count++;
    total = total + count;
    cout << count << " chars, and the whole amount of chars is " << total << endl;
}