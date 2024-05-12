#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Pair{
private:
    T1 a;
    T2 b;

public:
    T1& first(); //pozwala na przypisanie nowej wartosci do zmiennej
    T2& second();

    T1 first() const { return a; }
    T2 second() const { return b; }

    Pair( const T1& aval, const T2& bval ) : a( aval ), b( bval ) {}
    Pair() {}
};

template<typename T1, typename T2>
T1& Pair<T1, T2>::first(){
    return a;
}

template<typename T1, typename T2>
T2& Pair<T1, T2>::second(){
    return b;
}



int main(){
    Pair<string, int> ratings[4] = {
        Pair<string, int>( "Bob", 555 ),
        Pair<string, int>( "Pof", 111 ),
        Pair<string, int>( "Pup", 0 ),
        Pair<string, int>( "Puf", 23 )
    };

    int join = sizeof( ratings ) / sizeof( ratings[0] );
    cout << "ocena:\trestauracja:" << endl;

    for( int i = 0; i < join; i++ ){
        cout << ratings[i].second() << "\t" << ratings[i].first() << endl;
    }

    ratings[3].first() = "Pufof";
    ratings[3].second() = 56;
    cout << "\n" << ratings[3].second() << "\t" << ratings[3].first() << endl;
}