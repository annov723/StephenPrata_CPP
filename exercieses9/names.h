namespace SALES{
    const int QUARTERS = 4 ;
    struct sales{
        double sales [ QUARTERS ] ;
        double average ;
        double max ;
        double min ;
    };

    void setSales( Sales &s, const double ar[], int n );
    void setSales( Sales &s );
    void howSales( const Sales &s );
}