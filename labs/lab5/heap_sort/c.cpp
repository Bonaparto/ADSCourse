#include <iostream>
using namespace std;

const int N = 1e5 + 5e4 + 2;
int n, m;
// это один хип, но каждый раз нужно удалять первый вошедший
// элемент, когда заходит новый

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    int add(int x) {
        int i = hs++;
        a[i] = x;
        int p = (i - 1) / 2;
        while(i && a[i] > a[p]) {
            swap(a[i], a[p]);
            i = p;
            p = (i - 1) / 2;
        }
        if(hs == 1) return i;
        else return -1; 
    }

    int find(int x) {
        
    }
    
};

int heapify(int a[], int i, int k) {
    int least = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < k && a[least] > a[l]) least = l;
    if(r < k && a[least] > a[r]) least = r;
    if(least != i) {
        swap(a[least], a[i]);
        return(heapify(a, i, least));
    } else return(a[least]);
}

int main(){
    heap h;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i < m) h.add(a[i]);
    }
    for(int i = 0; i < n - m + 1; ++i) {
        cout << heapify(a, i, m+i) << endl;
    }
}