#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    char pr;
    if (cin.get(pr) && !cin.eof()) {
        while (cin.get(ch)  && !cin.eof()) {
            if (pr == ch) {
                count++;
            } else {
                if (count >= 4 || pr == '#') {
                    cout << '#';
                    cout << pr;
                    cout << hex << count + 1 << dec;
                    cout << '#';
                } else {
                    for (int i = 0; i < count + 1; i++) {
                        cout << pr;
                    }
                }
                count = 0;
                pr = ch;
            }
        }
            if (count >= 4 || pr == '#') {
                cout << '#';
                cout << pr;
                cout << hex << count + 1 << dec;
                cout << '#';

            } else {
                for (int i = 0; i < count + 1; i++) {
                    cout << pr;
                }
            }
    }
    return 0;
}
