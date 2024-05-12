#include <iostream>

using namespace std;

template<typename T1, typename T2 = int>
class Typos{

};

int main(){
    Typos<string, string> t1;
    Typos<double> t2;

    //konkretyzacja niejawna
    Typos< int, 100> stuff; //genereacja definicji klasy
    Typos<double, 30> *pt;
    pt = new Typos<double, 30>;

    //konkretyzacja jawna
    template class Typos<string, 100>; //zdefiniowana zostaje klasa o podanym template
}