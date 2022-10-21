#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
    char in;
    list <string> out;
    while(cin>>in) {
        string c;
        c += in;
        if(c == "+"||c == "-"||c == "*"||c == "/") {
            string b = out.back();
            out.pop_back();
            string a = out.back();
            out.pop_back();
            out.push_back("(" + a + c + b + ")");
        } else {
            out.push_back(c);
        }
    }
    cout << *out.rbegin();
    return 0;
}
