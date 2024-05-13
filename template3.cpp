#include <iostream>

using namespace std;

template<typename T>
class Bob{
private:
    template<typename V>
    class Hold{
    private:
        V val;
    public:
        Hold( V v = 0 ) : val( v ) {}
        void show() const { cout << val << endl; }
        V value() const { return val; }

        void count(); //definicja poza deklaracją
    };

    Hold<T> q;
    Hold<int> n;

public:
    Bob( T t, int i ): q( t ), n( i ) {}

    template<typename U>
    U blab( U u, T t ) { return ( ( n.value() + q.value() ) * u / t ); }

    template<typename P>
    P bobik( T t, P p ); //definicja poza deklaracją

    void show() const { q.show(); n.show(); }
};

template<typename T>
    template<typename V>
    void Bob<T>::Hold<V>::count(){
        cout << 2 + 2 << endl;
    }

template<typename T>
    template<typename P>
    P Bob<T>::bobik( T t, P p ){
        return t * p;
    }



int main(){
    Bob<double> g( 3.4, 6 );
    g.show();
    cout << g.blab( 10.6F, 4.5 ) << endl;
}