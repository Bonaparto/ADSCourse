#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int x; cin >> x;
    long long i = 1, j = 1, a = 1, b = 1;
    long long res = 0;
    while(x) {
        if (a <= b) {
            x += a == b;
            res = a;
            i++;
            a = i * i;
        }
        else {
            res = b;
            j++;
            b = j * j * j;
        }
        x -= 1;
    }
    cout << res;
}