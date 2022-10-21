#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map <string, double> a;
    map <string, double> b;
    string s;
    int gr;
    auto it = a.begin();
    while(cin >> s >> gr) {
        it = a.find(s);
        if(it != a.end()) {
            a[s] = a[s] + gr;
            b[s]++;
        } else {
            a[s] = gr;
            b[s] = 1;
        }
    }
    for(auto it = a.begin(); it != a.end(); it++) {
        auto itt = b.find(it -> first);
        if(itt != b.end()) {
            it -> second = it -> second/ itt->second;
        }

        cout << it -> first << " " << it -> second << endl;
    }
    return 0;
}
