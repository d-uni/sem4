#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

bool fun (Figure *x1, Figure *x2) {
    if(x1 -> get_square() < x2 -> get_square()) {
        return true;
    } else {
        return false;
    }

}
int main ()
{
    std::vector<Figure *> out;
    std::string x;
    char a;
    double b, c;
    while(std::getline(std::cin,x)) {
        std::stringstream ss(x);
        std::ostringstream in;
        ss >> a;
        if (a == 'R') {
            ss >> b >> c;
            in << b << " " << c;
            out.push_back(Rectangle::make(in.str()));

        } else if (a == 'S') {
            ss >> b;
            in << b;
            out.push_back(Square::make(in.str()));

        } else if (a == 'C') {
            ss >> b;
            in << b;
            out.push_back(Circle::make(in.str()));

        }
    }
        std::stable_sort(out.begin(), out.end(), fun);
        for(auto it: out) {
            std::cout << it -> to_string() << std::endl;
        }
    for(auto it: out) {
        delete it;
    }
        out.clear();
        return 0;
}