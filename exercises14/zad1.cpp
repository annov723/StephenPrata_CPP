#include <iostream>
#include <valarray>
#include <iomanip>

using namespace std;

typedef valarray<int> ArrayInt;

template<typename A, typename B>
class Pair{
private:
    ArrayInt a;
    ArrayInt b;
    int siz;
    int where = 0;

public:
    Pair() {}
    Pair( int s ) : siz( s ){
        a.resize( s );
        b.resize( s );
    }
    Pair( const int* aa, const int* bb, int s ) : siz( s ){
        a.resize( s );
        b.resize( s );
        for( int i = 0; i < siz; i++ ){
            a[i] = aa[i];
            b[i] = bb[i];
        }
    }

    void add( int first, int second ){
        if( where == siz ) return;
        a[where] = first;
        b[where++] = second;
    }

    ArrayInt getA() { return a; }
    ArrayInt getB() { return b; }

};

typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine{
private:
    string label;
    int years;
    Pair<int, int> data;

public:
    Wine() {}
    Wine( const char* l, int y, const int yr[], const int bot[] ) : label( l ), years( y ), data( yr, bot, y ) {}
    Wine( const char* l, int y ) : label( l ), years( y ), data( y ){

    }

    void GetBottles(){
        cout << "Podaj dane o winie " << label << " dla " << years << " roczników:" << endl;
        int p1, p2;
        for( int i = 0; i < years; i++ ){
            cout << "Podaj rocznik: ";
            cin >> p1;
            cout << "podaj liczbę butelek: ";
            cin >> p2;
            data.add( p1, p2 );
        }
    }

    string& Label(){
        return label;
    }

    int sum(){
        return data.getB().sum();
    }

    void Show(){
        cout << "Wino: " << label << endl;
        for( int i = 0; i < years; i++ ){
            cout << setw(10) << " " << setw(10) << ( data.getA() )[i] << setw(10) << ( data.getB() )[i] << endl;
        }
    }

};

int main(){
    cout << "Nazwa wina: ";
    char lab[50];
    cin.getline( lab, 50 );
    cout << "Liczba roczników: ";
    int yrs;
    cin >> yrs;

    Wine comx( lab, yrs );
    comx.GetBottles();
    comx.Show();

    string& nowaNazwa = comx.Label();
    nowaNazwa = "Roso Puposso";
    cout << "Nowa nazwa wina: " << comx.Label() << endl;
    cout << endl;



    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };

    Wine comxps( "Boba Poba Lupp", YRS, y, b );
    comxps.Show();
    cout << "Liczba butelek " << comxps.Label() << ": " << comxps.sum() << endl;
    
}