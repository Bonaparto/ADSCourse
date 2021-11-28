#include <iostream>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    long long g = N, l = K;
    while(l != 0) {
        int temp = g % l;
        g = l;
        l = temp;
    }
    cout << (N * K) / g << endl;
}