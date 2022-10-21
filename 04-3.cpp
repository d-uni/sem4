#include <iostream>
#include <cmath>
int main() {
    int r1, c1,r2,c2;
    int m, n, a ,b;
    std::cin >> m >> n;
    while(std::cin >> r1 >> c1 >> r2 >> c2) {
        a = abs(r2 - r1);
        b = abs(c2 - c1);
        if(a > (m/2)) {
            a = m - a;
        }
        if(b > (n/2)) {
            b = n - b;
        }
        std::cout << a + b << std::endl;
    }
    return 0;
}
