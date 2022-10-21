#include <iostream>
#include <string>
/* a^n 0^m b^n 1^m*/
using namespace std;
int main() {
    string in1;
    int n = 0, m = 0;
    while(cin >> in1) {
        n = 0;
        m = 0;
        auto i = in1.begin();
        for(i = in1.begin(); *i == 'a' && i != in1.end(); i++) {
            n++;
        }
        if(n > 0 && i != in1.end() && *i == '0') {
            for(; *i == '0' && i != in1.end(); i++) {
                m++;
            }
            if(m > 0 && i != in1.end() && *i == 'b') {
                for(; *i == 'b' && i != in1.end(); i++) {
                    n--;
                }
                if(n == 0 && i != in1.end() && *i == '1') {
                    for(; *i == '1' && i != in1.end(); i++) {
                        m--;
                    }
                    if(m == 0 && i == in1.end()) {
                        cout << 1 << endl;
                    } else { cout << 0 << endl;}
                } else { cout << 0 << endl;}
            } else { cout << 0 << endl;}
        } else { cout << 0 << endl;}
    }
    return 0;
}
