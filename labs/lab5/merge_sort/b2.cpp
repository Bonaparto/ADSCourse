#include <fstream>
using namespace std;

int cnt = 0, n;

ifstream fin("input.txt");
ofstream fout("output.txt");

void merge_sort(long long a[], int m, int l, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    long long L[n1], R[n2];

    for(i = 0; i < n1; ++i) {
        L[i] = a[l + i];
    }

    for(i = 0; i < n2; ++i) {
        R[i] = a[m + 1 + i];
    }

    j = 0, i = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] >= R[j]) {
            a[k] = R[j];
            j++;
        } else {
            a[k] = L[i];
            i++;
        }
        if(n1 + n2 == n && ((k != 0 && a[k] != a[k-1]) || k == 0)) cnt++;
        k++;
    }

    while(i < n1) {
        if(n1 + n2 == n && k != 0 && a[k-1] != L[i]) cnt++;
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        if(n1 + n2 == n && k != 0 && a[k-1] != R[j]) cnt++;
        a[k] = R[j];
        j++;
        k++;
    }    
}

void merge_sort(long long a[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge_sort(a, m, l, r);
    }
}

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) fout << a[i] << " "; 
}

int main(){
    fin >> n;
    long long a[n];
    for(int i = 0; i < n; ++i) fin >> a[i];
    merge_sort(a, 0, n - 1);
    fout << cnt; 
}