#include <iostream>
#include <set>
using namespace std;
template <typename Iter1, typename Iter2>
Iter2 myremove (Iter1 beg1, Iter1 end1, Iter2 beg2, Iter2 end2)
{
    set<int> delnum;
    auto it1 = beg1;
    while(it1 != end1) {
        if(*it1 >= 0) {
            delnum.insert(*it1);
        }
        ++it1;
    }
    int i = 0, j = 0;
    auto it3 = delnum.begin();
    auto it2 = beg2;
    while(it2 != end2) {
        while(*it3 < i && it3 != delnum.end()) {
            ++it3;
        }
        if(*it3 != i) {
            iter_swap(it2, beg2 + j);
            ++j;
        }
        ++i;
        ++it2;
    }
    return beg2 + j;
}
