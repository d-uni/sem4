#include <iostream>
#include <complex>
#include <array>
#include <vector>
namespace Equations {
    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>>
    quadratic (std::array<std::complex<T>, 3> ar) {
        std::complex<T> a, b, c, d, x1, x2;
        std::vector<std::complex<T>> out;
        a = ar[2];
        b = ar[1];
        c = ar[0];
        bool x = true;
        if (a == std::complex<T>(0, 0)) {
            if (b == std::complex<T>(0, 0)) {
                if(c == std::complex<T>(0, 0)) {
                    x = false;
                }
            } else {
                x1 = -c / b;
                out.push_back(x1);
            }
        } else {
            d = b * b - a * c * std::complex<T>(4, 0);
            x1 = ((-b) + sqrt(d)) / (std::complex<T>(2, 0) * a);
            x2 = ((-b) - sqrt(d)) / (std::complex<T>(2, 0) * a);
            out.push_back(x1);
            out.push_back(x2);
        }
        return std::pair<bool, std::vector<std::complex<T>>>(x, out);

    }
}
