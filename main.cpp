#include <iostream>
void fun(unsigned int n,unsigned int m ) {
    if(n == 0) {
        return m+1;
    }
    unsigned int res = m;
    for(int i = 0; i < m + 1; i++) {
        res = fun(n - 1, res);
    }
    return res;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
