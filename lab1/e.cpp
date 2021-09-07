#include <iostream>
#include <deque>
using namespace std;
int main(){
    int cnt = 0; deque <int> d, d1;
    for(cnt = 0; cnt < 5; ++cnt) {
        int x; cin >> x;
        d.push_back(x);
    }
    for(cnt = 0; cnt < 5; ++cnt) {
        int x; cin >> x;
        d1.push_back(x);
    }
    cout << d.size() << endl << d1.size() << endl;
    for(cnt = 1; cnt <= 20; ++cnt) {
        cout << d.back() << " " << d1.back() << endl;
        if(d.back() > d1.back()) {
            d.push_front(d.back());
            d.pop_back();
            d.push_front(d1.back());
            d1.pop_back();
        }
        else {
            d1.push_front(d.back());
            d.pop_back();
            d1.push_front(d1.back());
            d1.pop_back();
        }
        if(d.size() == 0) {
            cout << "first " << cnt;
            return 0; 
        }
        if(d1.size() == 0) {
            cout << "second " << cnt;
            return 0;
        }
        //cout << d.size() << " " << d1.size() << endl;
    }
    cout << "botva";
}