#include <iostream>
#include <vector>
using namespace std;
int main() {
    int size1 = 0, size2 = 0;
    vector <vector <unsigned int>> mx;
    int x,y,z;
    while(cin >> x >> y >> z) {
        if(x == 0 && y == 0 && z == 4294967161) {
            break;
        }
        mx[x][y] = z;
        size1 = max(size1, x);
        size2 = max(size2, y);
    }
    while(cin >> x >> y >> z) {
        mx[x][y] = mx[x][y] + z;
        size1 = max(size1, x);
        size2 = max(size2, y);
    }
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(mx[i][j] != 0) {
                cout << x <<" " << y << mx[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
