#include <cstring>
#include <iostream>
using namespace std;
// здесь могут быть нужные Вам директивы #include
class BinaryNumber
{
    string num;
public:
    BinaryNumber(const string &s): num(s) {};
    operator string () const {
        return num;
    };
    const BinaryNumber &operator++() {
        int f = 0;
        if (num.size() != 0) {
            if (num[num.size() - 1] == '1') {
                num[num.size() - 1] = '0';
                f = 1;
            } else {
                num[num.size() - 1] = '1';
            }
        }
        for (int i = num.size() -  2; i >= 0 && f == 1; i--) {
                if (num[i] == '1') {
                    num[i] = '0';
                    f = 1;
                } else {
                    num[i] = '1';
                    f = 0;
                }
        }
        if( f == 1) {
            num = "1" + num;
        }
        return *this;
    }
};
