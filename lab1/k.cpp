#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long x;
    cin >> x;
    for(int i = 2; i <= sqrt(x); ++i) {
        if(x % i == 0) {
            cout << "composite";
            return 0;
        }
    }
    cout << "prime";
}