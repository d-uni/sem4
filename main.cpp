#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector <int> x = {9,8,7,6,5,4,3,2,1};
    auto it1 = x.begin();
    for(it1 = x.begin() + 1; it1 != x.end(); it1++) {
        sort(x.begin(), it1);
        for(auto it2 = x.begin(); it2 != x.end(); it2++) {
            cout << *it2<< " ";
        }
        cout << '\n';
    }


}