#include <iostream>
using namespace std;
template <typename Iter, typename Comp >
void selection_sort (Iter first, Iter last, Comp compare)
{
    if(first != last) {
        for(auto cur = first; cur != last; ++cur) {
            auto min = cur;
            auto frw = cur;
            while (++frw != last) {
                if(compare(*frw,  *min)) {
                    min = frw;
                }
            }
            iter_swap(min, cur);
        }
    }
}
template <typename Iter>
void selection_sort(Iter first, Iter last)
{
    selection_sort(first,last,std::less
    <typename std::iterator_traits<Iter>::value_type>());
}
