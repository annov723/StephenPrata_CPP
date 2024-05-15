#include "queuetp.h"
#include "worker1.h"
#include <cstring>



int main(){
    MyQueue<Worker*> boby( SIZE );
    int c;
    for( c = 0; c < SIZE; c++ ){
        char choice;
        cout << "Podaj kategorie: k - kelner, p - piosenkarz, s - spiewajacy kelner, w - wyjscie" << endl;
        cin >> choice;
        while( strchr( "kpsw", choice ) == NULL ){ //sprawdza czy char zawiera ktorys z podanych znakow
            cout << "k, p, s lub w..." << endl;
            cin >> choice;
        }

        if( choice == 'w' ) break;

        switch( choice ){
            case 'k':
                boby.enqueue( new Waiter );
                break;
            case 'p':
                boby.enqueue( new Singer );
                break;
            case 's':
                boby.enqueue( new SingingWaiter );
                break;
            default:
                return 1;
        }
        cin.get();
        boby[c]->Set();
    }

    cout << "Pracownicy" << endl;
    for( int i = 0; i < c; i++ ){
        Worker* ptr = boby.dequeue();
        ptr->Show();
        delete ptr;
        cout << endl;
    }

}