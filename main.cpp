#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Sum {
    double sum = 0;
    void operator()(double i ) {
        sum += i;
    }
};
int main() {
    double a;
    vector <double> v1;
    while(cin >> a) {
        v1.push_back(a);
    }
    size_t del = v1.size() * 0.1;
    v1.erase(v1.begin(), v1.begin() + del);
    v1.erase(v1.end() - del, v1.end());
    sort(v1.begin(), v1.end());
    del = v1.size() * 0.1;
    v1.erase(v1.begin(), v1.begin() + del);
    v1.erase(v1.end() - del, v1.end());
    double sum = for_each(v1.begin(), v1.end(), Sum()).sum;
    cout << fixed;
    cout.precision(10);
    cout << sum/v1.size() << endl;
    return 0;
}
