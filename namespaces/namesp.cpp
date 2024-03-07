#include <iostream>
#include "namesp.h"



namespace pers{
    using std::cout;
    using std::cin;
    using std::endl;
    
    void getPerson( Person &p ){
        cout << "Podaj imie: ";
        cin >> p.fname;
        cout << "Podaj nazwisko: ";
        cin >> p.lname;
    }

    void showPerson( const Person &p ){
        cout << p.fname << " " << p.lname << endl;
    }
}

namespace debts{
    using std::cout;
    using std::cin;

    void getDebt( Debt &d ){
        getPerson( d.name );
        cout << "Podaj kwote: ";
        cin >> d.amount;
    }

    void showDebt( const Debt &d ){
        showPerson( d.name );
        cout << "kwota: " << d.amount << endl;
    }

    double sumDebts( const Debt ar[], int n ){
        double total = 0;
        for( int i = 0; i < n; i++ ) total = total + ar[i].amount;
        return total;
    }

}