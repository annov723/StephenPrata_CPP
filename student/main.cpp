#include "student.h"

void set( Student &stu, int n );

#define STU 3
const int quizzes = 5;

int main(){
    Student pup[STU] = { Student( quizzes ), Student( quizzes ), Student( quizzes ) };
    for( int i = 0; i < STU; i++ ) set( pup[i], quizzes );

    cout << "###LISTA###" << endl;
    for( int i = 0; i < STU; i++ ) cout << pup[i].Name() << endl;

    for( int i = 0; i < STU; i++ ){
        cout << endl << pup[i];
        cout << "average: " << pup[i].Average() << endl;
    }

    return 0;
}

void set( Student &stu, int n ){
    cout << "Podaj imie i nazwisko: ";
    getline( cin, stu );
    cout << "Podaj " << n << " wynikow:" << endl;
    for( int i = 0; i < n; i++ ) cin >> stu[i];
    while( cin.get() != '\n' ) continue;
}