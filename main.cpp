#include <iostream>
#include <cstring>
using namespace std;
class STR {
public:
    int i = 0;
    char arr[32768] = {};
    STR(){}
    STR(char *poi, int x = 0): i(x) {
        strcpy(arr, poi);
    }
    STR (int x, const STR a) {
        i = x;
        strcpy(arr, &a.arr[i]);
    }

};
void qs(STR *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last;
        char middle [32768];
        strcpy(middle, &s_arr[(left + right) / 2].arr[0]);
        cout << middle << "   - "<< endl;
        do
        {
            while (s_arr[left].arr < middle) left++;
            while (s_arr[right].arr > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left].i;
                s_arr[left].i = s_arr[right].i;
                s_arr[right].i = tmp;
                char m [32768] = {};
                strcpy(m, &s_arr[left].arr[0]);
                strcpy(s_arr[left].arr, &s_arr[right].arr[0]);
                strcpy(s_arr[right].arr, &m[0]);
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}
int main() {
    char arr[32768] = {};
    std::cin >> arr;
    int i = 32767;
    while(arr[i] == ' ' || arr[i] <= '\0') {
        arr[i] = '\0';
        i--;
    }
    STR a[i + 1];
    a[0] = STR(arr, 0);
    for(int j = 1; j < i + 1; j++) {
        a[j] = STR(j, a[0]);
        cout<< j << ") : "<< a[j].arr<<endl;
    }
    char m [32768] = {};
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 9; k++) {
            if (a[k].arr > a[k + 1].arr) {
                cout << a[k].arr << " VS " << a[k + 1].arr;
                int tmp = a[k].i;
                a[k].i = a[k + 1].i;
                a[k + 1].i = tmp;
                strcpy(m, &a[k].arr[0]);
                strcpy(a[k].arr, &a[k + 1].arr[0]);
                strcpy(a[k + 1].arr, &m[0]);
                memset(m, 0, sizeof(m));
            }
        }
    }
    for(int j = 0; j < i; j++) {
        cout << a[j].i << endl;
    }
    return 0;
}
