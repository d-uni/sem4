#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        auto it1 = args.begin();
        complex_stack st;
        for (it1 = args.begin(); it1 != args.end(); it1++) {
            if (*it1 == "z") {
                st = st << z;
            } else if (std::string::npos != (*it1).find(',')) {
                st = st << complex(*it1);
            } else if (*it1 == "!") {
                st = st << +st;
            } else if (*it1 == ";") {
                st = ~st;
            } else if (*it1 == "~") {
                complex p = ~(+st);
                st = ~st;
                st = st << p;
            } else if (*it1 == "#") {
                complex p = -(+st);
                st = ~st;
                st = st << p;
            } else if(*it1 == "+" || *it1 == "-" || *it1 == "*" || *it1 == "/") {
                complex a = +st;
                st = ~st;
                complex b = +st;
                st = ~st;
                if(*it1 == "+") {
                    st = st << (b+a);
                } else if (*it1 == "-") {
                    st = st << (b-a);
                } else if (*it1 == "*") {
                    st = st << (b*a);
                } else if (*it1 == "/") {
                    st = st << (b/a);
                }
            }
        }
        return +st;
    }
}
