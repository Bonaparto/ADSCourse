#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l < n && a[l] > a[largest]) {
        largest = l;
    }

    if(r < n && a[r] > a[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }

    for(int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
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

    heap_sort(a, n);
    print_array(a, n);

}