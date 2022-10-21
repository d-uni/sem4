#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct VEC {
    int index;
    char *p;
};
bool myfunction (VEC i,VEC j) {
    if (strcmp(i.p, j.p) > 0) {
        return false;
    } else {
        return true;
    }
}
int main() {
    string st;
    getline(cin, st);
    st.erase(st.find_last_not_of(" \n\r\t") + 1);
    int size = st.size();
    vector<VEC> sub;
    for(int i = 0; i < size; i++) {
        sub.push_back(VEC());
        sub[i].index = i;
        sub[i].p = &st[i];
    }
    sort (sub.begin(), sub.end(), myfunction);
    for(int i = 0; i < size; i++) {
        cout << sub[i].index << endl;
    }
    return 0;
}
