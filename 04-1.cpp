#include <iostream>
struct Item
{
    Item *next;
    long long value;
};
class Arena {
    Item *x;
    int siz = 0;
public:
    explicit Arena(size_t size) {
        siz = size/12;
        x = new Item [size/12];
    }
    Item *get() {
        for(int i  = 0; i < siz; i++) {
            if(&x[i] == nullptr) {
                return &x[i];
            }
        }
        return nullptr;
    };
    void put(Item *p) {

    };
    ~Arena() { delete x;}

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
