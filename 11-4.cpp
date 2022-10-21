#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
void fun(map<char, bool> &patt, bool f, char curr, map<char, set<char>> &t_no) {
    if(!f) {
        f = true;
        for(auto i = t_no[curr].begin(); i != t_no[curr].end(); i++) {
            if(!patt[*i]) {
                patt[*i] = true;
                f = false;
            }
            fun(patt, f, *i, t_no);
        }
    }
}
int main() {
    char left;
    string right;
    vector <pair<char, string>> gram;
    while(cin >> left) {
        cin >> right;
        gram.emplace_back(pair<char, string> (left, right));
    }
    map<char, set<char>> t_no;
    map<char, bool> patt;
    for(auto p = gram.begin(); p != gram.end(); p++) {
        for(auto k = (*p).second.begin(); k != (*p).second.end(); k++) {
            if(*k >= 'A' && *k <= 'Z') {
                t_no[(*p).first].insert(*k);
                patt[(*p).first] = false;
                patt[*k] = false;
            }
        }
    }
    patt['S'] = true;
    char curr = 'S';
    bool f = false;
    fun(patt, f, curr, t_no);

    for(auto p = gram.begin(); p != gram.end(); p++) {
        if(patt[(*p).first]) {
            cout << (*p).first << " " << (*p).second << endl;
        }
    }
    return 0;
}
