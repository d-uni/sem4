#include <iostream>
class A {
    std::string s;
public:
    A(std::string x): s(x) {}
    ~A() {
        if (s.size() != 0) {
            std::cout << s << std::endl;
        }
    }
};
void fun() {
    std::string s;
    while(std::cin >> s) {
        A a(s);
        fun();
    }
    throw 1;
}
int main() {
    try {
        fun();
    } catch (int i) {
    }
    return 0;
}
