#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    char cur;
    int out = 1;
    bool turn = false;
    while(cin >> s) {
        for(unsigned int i = 0; i < s.length(); i++) {
            cur = s[i];
            if(cur != '3' && cur != '4' && cur != '1' && cur != '2') {
                out = 0;
                break;
            }
            if(!turn) {
                if(cur == '1' || cur == '2') {
                    turn = true;
                }
            } else if(cur != '1' && cur != '2') {
                out = 0;
            }
        }
        cout << out << endl;
        out = 1;
        turn = false;
    }
    return 0;
}
