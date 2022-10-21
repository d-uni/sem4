#include <iostream>
#include <string>
using namespace std;

int main() {
    int pattern1[2];
    pattern1[0] = pattern1[1] = 0;
    int pattern2[2];
    pattern2[0] = pattern2[1] = 0;
    bool first = true;
    int out = 1;
    int in;
    bool turn = false;
    bool f = false;
    while((in = cin.get()) != EOF) {
        if (!isspace(in)) {
            f = true;
            if(!(in == '0' || in == '1')) {
                out = 0;
            } else if(out != 0) {
                if (first) {
                    if (in == '0' && !turn) {
                        pattern1[0]++;
                        pattern2[0]++;
                    } else if(in == '0'){
                        first = false;
                        turn = false;
                        pattern2[0] = 1;
                        pattern2[1] = 0;
                    } else {
                        pattern1[1]++;
                        pattern2[1]++;
                        turn = true;
                    }
                } else {
                    if(in == '0' && !turn) {
                        pattern2[0]++;
                    } else if(in == '0') {
                        if(pattern1[0] != pattern2[0]) {
                            out = 0;
                        }
                        if(pattern1[1] != pattern2[1]) {
                            out = 0;
                        }
                        turn = false;
                        pattern2[0] = 1;
                        pattern2[1] = 0;
                    } else {
                        pattern2[1]++;
                        turn = true;
                    }
                }
            }
        } else {
            if(pattern1[0] != pattern2[0]) {
                out = 0;
            }
            if(pattern1[1] != pattern2[1]) {
                out = 0;
            }
            if(pattern1[0] == 0 || pattern1[1] == 0) {
                out = 0;
            }
            if(f) {
                cout << out << endl;
            }
            pattern1[0] = pattern1[1] = 0;
            pattern2[0] = pattern2[1] = 0;
            first = true;
            out = 1;
            turn = false;
            f = false;
        }
    }
    if(pattern1[0] != pattern2[0]) {
        out = 0;
    }
    if(pattern1[1] != pattern2[1]) {
        out = 0;
    }
    if(pattern1[0] == 0 || pattern1[1] == 0) {
        out = 0;
    }
    if(f) {
        cout << out << endl;
    }
    return 0;
}

