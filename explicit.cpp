//ex. 1
class String {
public:
    String(int n); // allocate n bytes to the String object
    String(const char *p); // initializes object with char *p
};

String s = 'x'; //pójdzie, piersze konwersja 'x' na int a potem String( int )

class String {
public:
    explicit String (int n); //allocate n bytes
    String(const char *p); // initialize sobject with string p
};

String s = 'x'; //nie pójdzie


//ex. 2
struct Z { };

struct X { 
  explicit X(int a); // X can be constructed from int explicitly
  explicit operator Z (); // X can be converted to Z explicitly
};

struct Y{
  Y(int a); // int can be implicitly converted to Y
  operator Z (); // Y can be implicitly converted to Z
};

void foo(X x) { }
void bar(Y y) { }
void baz(Z z) { }

foo(2);                     // error: no implicit conversion int to X possible
foo(X(2));                  // OK: direct initialization: explicit conversion
foo(static_cast<X>(2));     // OK: explicit conversion

bar(2);                     // OK: implicit conversion via Y(int) 
bar(Y(2));                  // OK: direct initialization
bar(static_cast<Y>(2));     // OK: explicit conversion

X x2 = 2;                   // error: no implicit conversion int to X possible
X x3(2);                    // OK: direct initialization
X x4 = X(2);                // OK: direct initialization
X x5 = static_cast<X>(2);   // OK: explicit conversion 

Y y2 = 2;                   // OK: implicit conversion via Y(int)
Y y3(2);                    // OK: direct initialization
Y y4 = Y(2);                // OK: direct initialization
Y y5 = static_cast<Y>(2);   // OK: explicit conversion