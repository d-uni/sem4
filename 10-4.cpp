#include <iostream>
#include <string>
using namespace std;
int main() {
    string in1, in2;
    bool s_start = false;
    bool not_ter = true;
    bool wrong_left = false;
    bool wrong_right = false;
    bool ks = true;
    bool sinr = false;
    bool ksnsh = true;

    while(cin >> in1) {
        cin >> in2;
        unsigned int l1 = in1.length();
        unsigned int l2 = in2.length();

        not_ter = true;
        for(char i : in1) {
            if (i >= 'A' && i <= 'Z') {
                not_ter = false;
            }
        }
        if(not_ter) {
            wrong_left = true;
        }

        for(char i : in2) {
            if(i == 'S') {
                sinr = true;
            }
        }

        bool s_loc_start = false;
        if(l1 == (unsigned)1 && in1[0] == 'S') {
            s_start = true;
            s_loc_start = true;
        }
        if(l1 != (unsigned)1) {
            ks = false;
        }
        if(l2 == (unsigned)1 && in2[0] == '_' && s_loc_start) {
            wrong_right = true;
        } else if(l2 == (unsigned)1 && in2[0] == '_'){
            ksnsh = false;
        }
        if(l1 > l2) {
            ksnsh = false;
        }


    }

    if(!s_start || wrong_left) {
        cout << -1;
    } else if(ks && ksnsh && !(wrong_right && sinr)) {
        cout << 23;
    } else if(ks && (!ksnsh || (wrong_right && sinr))) {
        cout << 2;
    } else {
        cout << 10;
    }
    return 0;
}
