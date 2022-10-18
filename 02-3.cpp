#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    char pr;
    cin.get(pr);
    if (pr != EOF) {
        while (cin.get(ch)) {
                if (pr == ch) {
                    count++;
                } else {
                    if(count >= 4 || pr == '#') {
                        cout << '#';
                        cout << pr;
                        cout << hex << count + 1 << dec;
                        cout << '#';

                    } else {
                        for(int i = 0; i < count + 1; i++) {
                            cout << pr;
                        }
                    }

                    count = 0;
                    pr = ch;
                }

        }

    }
    return 0;
}
