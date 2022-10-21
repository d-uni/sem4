#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void process( const vector <int> &v1, vector <int> &v2) {
    if (v2.begin() == v2.end()) {
        return;
    }
    vector<int> v3 = v1;
    sort(v3.begin(), v3.end());
    auto it1 = unique(v3.begin(), v3.end());
    v3.erase(it1, v3.end());
    auto it3 = v3.begin();
    auto it2 = v2.begin();
    int i = 0;
    while (it3 != v3.end() && *it3 < 0) {
        it3++;
    }
    v3.erase(v3.begin(), it3);
    it3 = v3.begin();
    for (auto itt2 = v2.begin(); itt2 != v2.end(); itt2++) {
            if (it3 < v3.end() && i >= *it3) {
                it3++;
            } else {
                swap(*it2, *itt2);
                it2++;
            }
            i++;
    }
    v2.erase(it2, v2.end());
}
