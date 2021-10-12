#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    
    if(c1 < n && a[c1] > a[largest]) largest = c1;
    if(c2 < n && a[c2] > a[largest]) largest = c2;
    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; --i) heapify(a, n, i);
    for(int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    heap_sort(a, n);
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
}