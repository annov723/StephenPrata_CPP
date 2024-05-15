#include <iostream>
#include <string>

using namespace std;

class AbsEmp{
private:
    string fname;
    string lname;
    string job;

public:
    AbsEmp(){}
    AbsEmp( const string& fn, const string& ln, const string& j ) : fname( fn ), lname( ln ), job( j ){}

    virtual void showAll() const{
        cout << "name: " << fname << " " << lname << endl;
        cout << "job: " << job << endl;
    }

    virtual void setAll(){
        cout << "First name: ";
        cin >> fname;
        cout << "Last name: ";
        cin >> lname;
        cout << "Job: ";
        cin >> job;
    }

    friend ostream& operator<<( ostream& os, AbsEmp &e ){
        return os << e.fname << " " << e.lname;
    }

    virtual ~AbsEmp(){};

};



class Employee : public AbsEmp{
private:

public:
    Employee(){}
    Employee( const string &fn, const string &ln, const string& j ) : AbsEmp( fn, ln, j ){}

    virtual void showAll() const{
        AbsEmp::showAll();
    }

    virtual void setAll(){
        AbsEmp::setAll();
    }

};



class Manager : virtual public AbsEmp{
private:
    int inChargeOf;

protected:
    int getInChargeOf() const { return inChargeOf; }
    int& getInChargeOf() { return inChargeOf; }

public:
    Manager(){}
    Manager( const string& fn, const string& ln, const string& j, int ico = 0 ) : AbsEmp( fn, ln, j ), inChargeOf( ico ){}
    Manager( const AbsEmp& e, int ico = 0 ) : AbsEmp( e ), inChargeOf( ico ){}
    Manager( const Manager& m ) : AbsEmp( m ), inChargeOf( m.getInChargeOf() ){}

    virtual void showAll() const{
        AbsEmp::showAll();
        cout << "In charge of: " << inChargeOf << endl;
    }

    virtual void setAll(){
        AbsEmp::setAll();
        cout << "In charge of: ";
        cin >> inChargeOf;
    }

};



class Fink : virtual public AbsEmp{
private:
    string report;

protected:
    const string getReport() const { return report; }
    string& getReport() { return report; };

public:
    Fink(){}
    Fink( const string& fn, const string& ln, const string& j, const string& rep ) : AbsEmp( fn, ln, j ), report( rep ){}
    Fink( const AbsEmp& e,  const string& rep ) : AbsEmp( e ), report( rep ){}
    Fink( const Fink& f ) : AbsEmp( f ), report( f.getReport() ){}

    virtual void showAll() const{
        AbsEmp::showAll();
        cout << "Reports to: " << report << endl;
    }

    virtual void setAll(){
        AbsEmp::setAll();
        cout << "Reports to: ";
        cin >> report;
    }

};



class HighFink : public Manager, public Fink{
private:

public:
    HighFink(){}
    HighFink( const string& fn, const string& ln, const string& j, const string& rep, int ico ) : AbsEmp( fn, ln, j ), Manager( fn, ln, j, ico ), Fink( fn, ln, j, rep ){}
    HighFink( const AbsEmp& e, const string& rep, int ico ) : AbsEmp( e ), Manager( e, ico ), Fink( e, rep ){}
    HighFink( const Fink& f, int ico ) : AbsEmp( f ), Manager( f, ico ), Fink( f ){}
    HighFink( const Manager& m, const string rep ) : AbsEmp( m ), Fink( m, rep ), Manager( m ){}
    HighFink( const HighFink& h ) : AbsEmp( h ), Fink( h ), Manager( h ){}

    virtual void showAll() const{
        AbsEmp::showAll();
        cout << "Reports to: " << getReport() << endl;
        cout << "In charge of: " << getInChargeOf() << endl;
    }

    virtual void setAll(){
        AbsEmp::setAll();
        cout << "Reports to: ";
        cin >> getReport();
        cout << "In charge of: ";
        cin >> getInChargeOf();
    }

};