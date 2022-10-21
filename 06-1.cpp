#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool mycomp (int a, int b)
{
    unsigned int count1 = 0;
    for(; a; a>>=1) {
        if(a & 1) {
            count1++;
        }
    }
    unsigned int count2 = 0;
    for(; b; b>>=1) {
        if(b & 1) {
            count2++;
        }
    }
    return (count1 < count2);

}
int main() {
    vector <int> a;
    int x;
    while(cin >> x) {
        a.push_back(x);
    }
    stable_sort(a.begin(), a.end(), mycomp);
    for(auto itt = a.begin(); itt != a.end(); itt++) {
        cout << *itt << endl;
    }
    return 0;
}
