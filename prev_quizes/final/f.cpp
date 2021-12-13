#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");   

int partition(long long a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j <= r - 1; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quicksort(long long a[], int l, int r) {
    if(l < r) {
        int pivot = partition(a, l, r);
        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, r);
    }
}

int main() {
    int n;
    fin >> n;
    int a[n];
    long long pref[n+1];
    int sum = 1e8;
    pref[0] = 0;
    for(int i = 0; i < n; ++i) {
        fin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    quicksort(pref, 0, n);
    for(int i = 0; i <= n; ++i) {
        long long cur = abs(pref[i+1] - pref[i]);
        if(sum > cur) sum = cur;
    }
    fout << sum;
}