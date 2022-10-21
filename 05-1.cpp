#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void process( const vector <int> &v1, vector <int> &v2) {
    if(v2.begin() == v2.end()) {
        return;
    }
    vector <int> v3 = v1;
    sort(v3.begin(), v3.end());
    auto it1 = unique(v3.begin(), v3.end());
    v3.erase(it1, v3.end());
    auto it3 = v3.begin();
    int i = 0;
    while(it3 != v3.end() && *it3 < 0) {
        it3++;
    }
    for(it3 = v3.begin(); it3 != v3.end(); it3++) {
        if((*it3) >= 0 && ((size_t)(*it3)) < v2.size()) {
            swap(*(v2.begin() + *it3), *(v2.begin() + i));
            i++;
        }
    }
    v2.erase(v2.begin(), v2.begin() + i);
}
