
template <typename T> typename T::value_type process (const T & t)
{
    typename T::value_type res = typename T::value_type();
    auto it = t.rbegin();
    int i = 0;
    while(it != t.rend() && i <= 5) {
        if(i == 0) {
            res = res + *it;
        } else if(i == 2) {
            res = res + *it;
        } else if(i == 4) {
            res = res + *it;
        }
        i++;
        it++;
    }
    return res;
}
