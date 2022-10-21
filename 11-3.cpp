#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main() {
    map<string, map<char, string>> gram;
    string s3;
    char s2;
    set <string> end;
    string start;
    string in;
    string check;
    cin >> in;
    bool result1 = true;
    int result2 = 0;
    string result3;
    while(in != "END") {
        cin >> s2 >> s3;
        gram[in][s2] = s3;
        cin >> in;
    }
    cin >> in;
    while(in != "END") {
        end.insert(in);
        cin >> in;
    }
    cin >> start;
    result3 = start;
    cin >> check;
    for(auto i = check.begin(); i != check.end() && result1; i++) {
        auto it1 = gram.find(result3);
        if(it1 != gram.end()) {
            auto it2 = (it1->second).find(*i);
            if(it2 != it1->second.end()) {
                result2++;
                result3 = gram[result3][*i];
            } else { result1 = false; }
        } else { result1 = false; }
    }
    if(result1) {
        result1 = false;
        for(string i: end) {
            if(i == result3) {
                result1 = true;
            }
        }
        cout << result1 << endl;
        cout << result2 << endl;
        cout << result3 << endl;
    } else {
        cout << result1 << endl;
        cout << result2 << endl;
        cout << result3 << endl;
    }
    return 0;
}
