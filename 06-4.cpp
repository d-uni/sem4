#include <iostream>
#include <map>
using namespace std;
enum
{
    MAX = 4294967161
};
int
main() {
    map <pair <unsigned int, unsigned int>, unsigned long long> a;
    unsigned int x, y;
    unsigned long long z;
    while(cin >> x >> y >> z) {
        if(x == 0 && y == 0 && z == MAX) {
            break;
        }
        a.insert(pair<pair<unsigned int, unsigned int>,
                unsigned long long>(pair <unsigned int, unsigned int>(x,y),z));
    }
    map <pair <unsigned int, unsigned int>, unsigned long long> ::iterator it;
    while(cin >> x >> y >> z) {
        it = a.find(pair <unsigned int, unsigned int> (x, y));
        if (it != a.end()) {
            it -> second = (it -> second + z) % MAX;
            if(it -> second == 0) {
                a.erase(it);
            }
        } else {
            a.insert(pair<pair<unsigned int,unsigned int>,
                    unsigned long long>(pair<unsigned int,unsigned int>(x,y),z));
        }
    }
    for (auto itt = a.begin(); itt != a.end(); itt++) {
        cout << itt -> first.first << " " << itt -> first.second << " " << itt -> second << endl;
    }
    return 0;
}
