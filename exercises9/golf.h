const int LEN = 40;

struct golf{
    char fullname [ LEN ] ;
    int handicap ;
};

void setgolf ( golf &g , const char *name , int hc );
void setgolf ( golf &g );
void handicap ( golf & g , int hc );
void showgolf ( const golf & g );