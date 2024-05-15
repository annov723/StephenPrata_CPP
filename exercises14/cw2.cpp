#include <iostream>
#include <cstring>

using namespace std;

class Frabjus{
private:
    char fab[20];

public:
    Frabjus( const char *s = "C++" ) {
        strcpy( fab, s );
    }
    virtual void tell(){ cout << fab << endl; }
};

/*class Gloam{
private:
    int glip;
    Frabjus fb;
    
public:
    Gloam( int g = 0, const char *s = "C++" ) : glip( g ), fb( s ) {}
    Gloam( int g, const Frabjus& f ) : glip( g ), fb( f ){}
    void tell(){
        cout << glip << endl;
        fb.tell();
    }
};*/

class Gloam : private Frabjus{
private:
    int glip;
    
public:
    Gloam( int g = 0, const char *s = "C++" ) : Frabjus( s ), glip( g ) {}
    Gloam( int g, const Frabjus& f ) : Frabjus( f ), glip( g ) {
    }
    void tell(){
        cout << glip << endl;
        Frabjus::tell();
    }
};


int main(){
    Gloam a( 5, "Bob" );
    a.tell();
}