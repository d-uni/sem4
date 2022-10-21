#include <iostream>
#include <map>
using namespace std;
enum
{
    MAX = 4294967161
};
int
main() {
    multimap <unsigned int, pair <unsigned int, unsigned long long>> a;
    unsigned int x, y;
    unsigned long long z;
    while(cin >> x >> y >> z) {
        if(x == 0 && y == 0 && z == MAX) {
            break;
        }
        a.insert(pair <unsigned int,pair <unsigned int, unsigned long long>>
            (y, pair <unsigned int, unsigned long long>(x,z)));
    }
    map <pair<unsigned int, unsigned int >,unsigned long long> b;
    while(cin >> x >> y >> z) {
        auto it = a.equal_range(x);
        for (auto itr = it.first; itr != it.second; ++itr) {
            unsigned long long out = ((itr->second.second % MAX) * (z % MAX)) % MAX;
            auto itt = b.find(pair<unsigned int,unsigned int>(itr->second.first, y));
            if(itt != b.end()) {
                itt -> second = (itt -> second + out) % MAX;
            } else {
                if(out != 0) {
                    b.insert(pair <pair<unsigned int,unsigned int>,unsigned long long>
                        (pair<unsigned int,unsigned int>(itr->second.first, y), out));
                }
            }
        }
    }
    for (auto iit = b.begin(); iit != b.end(); iit++) {
        cout << iit -> first.first << " " << iit -> first.second << " " << iit -> second << endl;
    }
    return 0;
}