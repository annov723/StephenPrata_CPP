#include "stacktp.h"
#include "stacktp.cpp"

#include <string>
#include <cctype>

using namespace std;

int main(){
    Stack<string> stackS;
    char ch;
    string po;
    cout << "D -dodac, P - przetworzyc, Z - zakonczyc" << endl;
    while( cin >> ch && toupper( ch ) != 'Z' ){
        while( cin.get() != '\n' ) continue;

        switch( ch ){
            case 'D':
            case 'd':
                if( stackS.isFull() ) break;
                cout << "Podaj zamowienie: ";
                getline( cin, po );
                stackS.push( po );
                break;

            case 'P':
            case 'p':
                if( stackS.isEmpty() ) break;
                stackS.pop( po );
                cout << "Zamowienie zakonczone: " << po << endl;
                break;

            default: return 1;
        }
        cout << "D -dodac, P - przetworzyc, Z - zakonczyc" << endl;
    }
}