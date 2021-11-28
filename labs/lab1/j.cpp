#include <iostream>
using namespace std;
int main(){
    long long n, m, ans;
    cin >> n >> m;
    while(m != 0) {
        ans = n % m;
        n = m;
        m = ans;
    }
    cout << n;
}