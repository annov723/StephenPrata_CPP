#include <iostream>
#include "names.h"



namespace SALES{
    using namespace std;

    void setSales( Sales &s, const double ar[] ){
        double sum = 0;
        double min = ar[0];
        double max = ar[0];
        for( int i = 0; i < QUARTERS; i++ ){
            s.sales[i] = ar[i];
            sum = sum + ar[i];
            if( min > ar[i] ) min = ar[i];
            if( max < ar[i] ) max = ar[i];
        }
        s.max = max;
        s.min = min;
        s.average = sum / QUARTERS;
    }

    void setSales( Sales &s ){
        double sum = 0;
        
        cout << "Podaj kwartalne sprzedaze:" << endl;
        for( int i = 0; i < QUARTERS; i++ ) cin >> s.sales[i];
        double min = s.sales[0];
        double max = s.sales[0];

        for( int i = 0; i < QUARTERS; i++ ){
            sum = sum + s.sales[i];
            if( min > s.sales[i] ) min = s.sales[i];
            if( max < s.sales[i] ) max = s.sales[i];
        }
        s.max = max;
        s.min = min;
        s.average = sum / QUARTERS;
    }

    void howSales( const Sales &s ){
        cout << "\n***SPRZEDAZE***" << endl;
        for( int i = 0; i < QUARTERS; i++ ) cout << s.sales[i] << " ";
        cout << "\nnajmniejsza: " << s.min << endl;
        cout << "najwieksza: " << s.max << endl;
        cout << "srednia: " << s.average << endl;
    }
}
