#include<iostream>
using namespace std;

class A {
public:
    void Afunc() {
        cout << "\nFuncA";
    }
};

class B {
public:
    void Bfunc() {
        cout << "\nFuncB";
    }
};

class C : public A, public B {
public:
};

int main() {
    C c;
    c.Afunc(); // Corrected instance name
    c.Bfunc(); // Corrected instance name
    return 0;
}
