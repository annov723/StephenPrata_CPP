#include <iostream>

using namespace std;



//funkcje zaprzyjaźnione spoza szablonu
/*template<typename T>
class Friend{
private:
    T item;
    static int ct;

public:
    Friend( const T& a ) : item( a ) { ct++; }
    ~Friend(){ ct--; }

    friend void counts();
    friend void reports<>( Friend<T>& fr );

};

template<typename T>
int Friend<T>::ct = 0;

void counts(){
    cout << "ile int: " << Friend<int>::ct << endl;
    cout << "ile double: " << Friend<double>::ct << endl;
}

void reports( Friend<int>& fr ){
    cout << fr.item << endl; 
}

void reports( Friend<double>& fr ){
    cout << fr.item << endl;
}*/



//zależne szablony funkcji zaprzyjaźnionej - specjalizacja szablonów zadeklarowanych poza klasą
//np. jak obiekt <int> to współpracuje tylko z count<int>
/*template<typename T>
void counts();
template<typename T>
void reports( T& fr );

template<typename TT>
class Friend{
private:
    TT item;
    static int ct;

public:
    Friend( const TT& a ) : item( a ) { ct++; }
    ~Friend(){ ct--; }

    friend void counts<TT>();
    friend void reports<>( Friend<TT>& fr );

};

template<typename T>
int Friend<T>::ct = 0;

template<typename T>
void counts(){
    cout <<  "miejsce obiketu: " << sizeof( Friend<T> ) << endl;
    cout << "ile: " << Friend<T>::ct << endl;
}

template<typename T>
void reports( T& fr ){
    cout << fr.item << endl; 
}*/



//niezależne szablony funkcji zaprzyjaźnionych - każda specjlalizacja funkcji zaprzyjaźniona z każdą specjalizacją klasy
template<typename TT>
class Friend{
private:
    TT item;

public:
    Friend( const TT& a ) : item( a ) {}
    template<typename C, typename D> friend void show( C& c, D& d );

};

template<typename C, typename D> void show( C& c, D& d ){
    cout << c.item << ", " << d.item << endl;
}


int main(){
    //1
    /*counts();

    Friend<int> fi( 90 );
    Friend<int> fii( 33 );
    Friend<double> fd( 4 );
    counts();
    counts();

    reports( fi );
    reports( fii );
    reports( fd );
    */
    
    //2
    /*counts<int>();
    cout << endl;

    Friend<int> fi( 90 );
    Friend<int> fii( 33 );
    Friend<double> fd( 4 );
    counts<int>();
    counts<double>();

    reports( fi );
    reports( fii );
    reports( fd );*/

    //3
    Friend<int> fi( 33 );
    Friend<int> fii( 2 );
    Friend<double> fd( 444.3 );
    cout << "1, 2:" << endl;
    show( fi, fii );
    cout << "2, 3:" << endl;
    show( fii, fd );
}