#include <iostream>

class Arena {
public:
    Item *pul;
    size_t count = 0;
    bool *patt;
    explicit Arena(size_t size) {
            size_t x = sizeof(struct Item);
            if (x <= size) {
                count = size/x;
                pul = new Item[count];
                patt = new bool[count];
                for (size_t i = 0; i < count; i++) {
                    patt[i] = false;
                }
            } else {
                pul = nullptr;
                patt = nullptr;
            }
    }
    Item *get() {
        for(size_t i = 0; i < count; i++) {
            if(!patt[i]) {
                patt[i] = true;
                return &pul[i];
            }
        }
        return nullptr;
    }
    void put(Item *putt) {
            for (size_t i = 0; i < count; i++) {
                if (&pul[i] == putt) {
                    patt[i] = false;
                    break;
                }
            }
    }
    ~Arena() {
        delete [] pul;
        delete [] patt;
    }
};