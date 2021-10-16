#include <iostream>
using namespace std;

int n;
int a[1005];

void divide_count(int a[], int x) {
    for(int i = 2; i * x <= n; i++) a[i*x]++;
    
}

int main(){

    int cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        a[i] = 0;
    }
    for(int i = 2; i <= n; ++i) {
        divide_count(a, i);
    }
   
    for(int i = 1; i <= n; ++i) {
        if(a[i] < 3 && a[i] > 0) cnt++;
    }
    cout << cnt;
}