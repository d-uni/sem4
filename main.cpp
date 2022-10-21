
template <typename T, typename Pred> T myfilter (const T &t, Pred pred)
{
    T out;
    auto tt = t.begin();
    while(tt != t.end()) {
        if(pred(*tt)) {
            out.insert(out.end(),*tt);
        }
        tt++;
    }
    return out;
}
