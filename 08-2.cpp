#include <iostream>
#include <cmath>
namespace Game {
    template <class T> class Coord {
    public:
        typedef T value_type;
        T row, col;
        explicit Coord(T x = value_type(), T y = value_type()) : row(x), col(y) {}
    };
    template <typename T>
    typename T::value_type dist(T &size, T &x1, T&x2) {
        auto l1 = x2.col - x1.col;
        auto x = std::abs(l1);
        auto l2 = x2.col/2 + x2.row - x1.col/2 - x1.row;
        auto y = std::abs(l2);
        auto dia = std::max(x, y);
        auto straight = x + y;
        if((l1 >= 0 && l2 >= 0) || (l1 < 0 && l2 < 0)) {
            return dia;
        } else {
            return straight;
        }
    }
}
