#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void merge_sort(int a[], int m, int l, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(i = 0; i < n1; ++i) {
        L[i] = a[l + i];
    }

    for(i = 0; i < n2; ++i) {
        R[i] = a[m + 1 + i];
    }

    j = 0, i = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = R[j];
            j++;
        } else {
            a[k] = L[i];
            i++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }    
}

void merge_sort(int a[], int l, int r) {
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
    int n;
    fin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) fin >> a[i];

    merge_sort(a, 0, n - 1);
    print_array(a, n);
}