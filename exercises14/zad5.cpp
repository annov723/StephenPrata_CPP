#include "emp.h"

int main(){
    Employee em( "Tadeusz", "Hubert", "Sprzedawca" );
    cout << em << endl;
    em.showAll();
    cout << endl;

    Manager ma( "Antek", "Bob", "Malarz", 7 );
    cout << ma << endl;
    ma.showAll();
    cout << endl;

    Fink fi( "Tadek", "Pop", "Hydraulik", "PoF" );
    cout << fi << endl;
    fi.showAll();
    cout << endl;

    HighFink hf( ma, "Bobie Górne" );
    hf.showAll();
    cout << endl;

    cout << "press coś" << endl;
    cin.get();
    HighFink hff;
    hff.setAll();
    cout << endl;

    cout << "wskaźnik AbsEmp:" << endl;
    AbsEmp* tri[4] = { &em, &fi, &hf, &hff };
    for( int i = 0; i < 4; i++ ){
        tri[i]->showAll();
        cout << endl;
    }

    return 0;
}