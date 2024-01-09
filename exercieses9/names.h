namespace SALES{
    const int QUARTERS = 4 ;
    struct Sales{
        double sales [ QUARTERS ] ;
        double average ;
        double max ;
        double min ;
    };

    void setSales( Sales &s, const double ar[] );
    void setSales( Sales &s );
    void howSales( const Sales &s );
}