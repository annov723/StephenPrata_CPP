#include <iostream>
#include <string>

using namespace std;

class Plorg{
private:
    string name;
    int syty;

public:
    Plorg( string name = "Plorga" ){
        syty = 50;
        if( name.length() > 19 ) this->name = "Plorga";
        else this->name = name;
    }

    void change_syty( int a ){
        syty = a;
    }

    void call(){
        cout << name << " " << syty << endl;
    }


};

int main( void ){
    Plorg a, b( "Bob" );
    a.change_syty( 4 );
    a.call();
    b.call();

    return 0;
}
