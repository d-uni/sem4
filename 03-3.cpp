#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
int
main(int argc, char *argv[]) {
    numbers::complex C = numbers::complex(argv[1]);
    std::string::size_type sz;
    double R = std::stod(argv[2], &sz);
    int N = std::stoi(argv[3], &sz);
    std::vector<std::string> S;
    int i = 4;
    while(argv[i]) {
        S.emplace_back(argv[i]);
        i++;
    }
    double diam = 2*(M_PI)/N;
    numbers::complex sum;
    for(int i = 1; i < N + 1; i++) {
        sum = sum +
                numbers::eval(S,numbers::complex(C.re()+R*cos((i-1)*diam),C.im()+R*sin((i-1)*diam)))*
                numbers::complex(R*(cos(i*diam)-cos((i-1)*diam)),R*(sin(i*diam)-sin((i-1)*diam)));
    }
    std::cout << sum.to_string() << std::endl;
}
