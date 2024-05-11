#ifndef __WORKER__
#define __WORKER__

#include <iostream>
#include <string>


using namespace std;

class Worker{ //dziedziczenie wielokrotne
private:
    string fullname;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname( "brak" ), id( 0L ) {}
    Worker( const string &s, long n ) : fullname( s ), id( n ) {}

    //czysto wirtualne
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0; 

};

class Waiter : virtual public Worker{
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache( 0 ) {}
    Waiter( const string &s, long n, int p = 0 ) : Worker( s, n ), panache( p ) {}
    Waiter( const Worker &w, int p = 0 ) : Worker( w ), panache( p ) {}

    void Set();
    void Show() const;

};

class Singer : virtual public Worker{
protected:
    enum{ inny, alt, kontralt, sopran, bas, baryton, tenor };
    enum{ Vtypes = 7 };

    void Data() const;
    void Get();

private:
    static char *pv[Vtypes]; //typ głosu jako tekst
    int voice;

public:
    Singer() : Worker(), voice( inny ) {}
    Singer( const string &s, long n, int v = inny ) : Worker( s, n ), voice( v ) {}
    Singer( const Worker &w, int v = 0 ) : Worker( w ), voice( inny ) {}

    void Set();
    void Show() const;

};

class SingingWaiter : public Singer, public Waiter{
protected:
    void Data() const;
    void Get();

public:
    SingingWaiter() {}
    SingingWaiter( const string &s, long n, int p = 0, int v = inny ) : Worker( s, n ), Waiter( s, n, p ), Singer( s, n, v ) {}
    SingingWaiter( const Worker& w, int  p = 0, int v = inny ) : Worker( w ), Waiter( w, p ), Singer( w, v ) {}
    SingingWaiter( const Waiter& w, int v = inny ) : Worker( w ), Waiter( w ), Singer( w, v ) {}
    SingingWaiter( const Singer& w, int p = 0 ) : Worker( w ), Waiter( w, p ), Singer( w ) {}

    void Set();
    void Show() const;

};

#endif