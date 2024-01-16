#ifndef __STOCK__
#define __STOCK__

#include <iostream>
#include <cstring>

using namespace std;



class Stock{
    private:
        char company[30];
        int shares;
        double share_val;
        double total_val;
        
        void set_total(){
            total_val = shares * share_val;
        }

    public:
        Stock();
        Stock( const char *co, int n = 0, double pr = 0.0 );
        ~Stock();

        void buy( int num, double price );
        void sell( int num, double price );
        void update( double price );
        void show();

        const Stock & top_value( const Stock &s ) const; //zapewnia, że w tej funkcji obiekt wywołujący nie zostanie zmieniony
};



#endif