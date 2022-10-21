#include <iostream>
#include <vector>
#include <functional>
using namespace std;
template <typename Iter, typename Fun>
void myapply (Iter beg, Iter end,  Fun f)
{
    auto it1 = beg;
    auto it2 = end;
    while(it1 != it2) {
        f(*it1);
        it1++;
    }
}
template <typename Iter, typename Pred>
vector<reference_wrapper<typename iterator_traits<Iter>::value_type>>
myfilter2(Iter beg, Iter end,  Pred f)
{
    vector <reference_wrapper<typename iterator_traits<Iter>::value_type>> out;
    auto it1 = beg;
    auto it2 = end;
    while(it1 != it2) {
        if(f(*it1)) {
            out.push_back(*it1);
        }
        it1++;
    }
    return out;
}
