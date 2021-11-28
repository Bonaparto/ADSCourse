#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m + 1 - l;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;
    for(int i = 0; i < n1; ++i) L[i] = a[l+i];
    for(int i = 0; i < n2; ++i) R[i] = a[m+1+i];
    i = 0, k = l, j = 0;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int n, m, i, j;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; ++i) cin >> b[i];

    merge_sort(a, 0, n - 1);
    merge_sort(b, 0, m - 1);

    i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            while(i + 1 < n && a[i] == a[i+1]) i++;
            while(j + 1 < m && b[j] == b[j+1]) j++;
            i++; j++;
        } else {
            cout << "NO";
            return 0;
        }

    }
    while(i < n) {
        if(j == m) j--;
        if(a[i] != b[j]) {
            cout << "NO";
            return 0;
        }
        i++;
    }
    while(j < m) {
        if(i == n) i--;
        if(a[i] != b[j]) {
            cout << "NO";
            return 0;
        }
        j++;
    }
    cout << "YES";
}