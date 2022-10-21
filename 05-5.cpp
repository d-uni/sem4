#include <iostream>
#include <list>
using namespace std;
int main() {
    long long a, b;
    list <long long> list;
    auto itt = list.begin();
    while(cin >> a && a != 0) {
        list.push_back(a);
    }
    while (cin >> a) {
        if (a < 0) {
            a++;
            if((size_t)(-a) >= list.size()) {
                continue;
            } else {
                itt = list.begin();
                advance(itt, -a);
                list.erase(itt);
            }
        } else if (a > 0){
            cin >> b;
            a--;
            if (a >= list.size()) {
                list.push_back(b);
            } else {
                itt = list.begin();
                for(long long i = 0; i < a; i++) {
                    itt++;
                }
                list.insert(itt, b);
            }

        }
    }
    for(auto it = list.begin(); it != list.end(); it++) {
        cout << *it << endl;
    }
    list.erase(list.begin(), list.end());
    return 0;
}
