#include <iostream>

class C {
    char static const c;
public:
    static void f() {};

};
int main()
{
    C ob;
    C::f();
    return 0;
}
