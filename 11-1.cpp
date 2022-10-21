#include <iostream>
#include <string>
using namespace std;
int main() {
    string in1, in2;
    bool sinr = false;
    bool s_and_epsinr = false;
    bool onlylefterm = true;
    bool onlyrightterm = true;
    bool leftsmaller = true;
    bool autogr = true;
    bool reg = true;
    bool onenterm = false;
    while(cin >> in1) {
        cin >> in2;
        int nterminr = 0;
        int terminr = 0;
        unsigned int l2 = in2.length();
        if(in2 == "_" && in1 == "S") {s_and_epsinr = true;}
        if(in2 == "_" && in1 != "S") {
            leftsmaller = false;
            autogr = false;
        }
        for(auto i: in2) {
            if(i == 'S') {sinr = true;}
            if(i >= 'A' && i <= 'Z') {
                nterminr++;
            } else if((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
                terminr++;
            }
        }
        if(terminr == 0 && nterminr == 1 && !onenterm && in2 != "_") {
            onenterm = true;
        } else if(terminr != 1 && in2 != "_") {
            autogr = false;
        }

        if(nterminr > 0 && !(terminr == 0 && nterminr == 1)) {
            if(nterminr == 1) {
                if(!(onlylefterm && in2[0] >= 'A' && in2[0] <= 'Z')) {
                    onlylefterm = false;
                }
                if(!(onlyrightterm && in2[l2 - 1] >= 'A' && in2[l2 - 1] <= 'Z')) {
                    onlyrightterm = false;
                }

            } else {
                reg = false;
            }
        }
    }
    if(!onlyrightterm && !onlylefterm) {
        reg = false;
    }
    if(reg) {
        if(autogr) {
            if(!onenterm || !sinr) {
                if(onlylefterm) {cout << 311;}
                else {cout << 321;}
            } else {
                if(onlylefterm) {cout << 31;}
                else {cout << 32;}
            }
        } else {
            if(onlylefterm) {cout << 31;}
            else {cout << 32;}
        }
    } else {
        if(leftsmaller &&
        !(s_and_epsinr && sinr)) {
            cout << 21;
        } else {
            cout << 2;
        }
    }
    cout << endl;
    return 0;
}
