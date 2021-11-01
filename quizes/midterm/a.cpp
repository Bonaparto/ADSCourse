#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int b[501][501];
int m1;

long long sum[501];

void heapify(pair <long long, int> a[], int n, int i) {
    int largest = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    
    if(c1 < n && a[c1].first < a[largest].first) largest = c1;
    if(c2 < n && a[c2].first < a[largest].first) largest = c2;
    if(largest != i && a[c1].first == a[largest].first || a[c2].first == a[largest].first) {
        if(a[c1].first == a[largest].first) {
            for(int j = 0; j < m1; ++j) {
                if(b[a[c1].second][j] < b[a[largest].second][j]) {
                    largest = c1;
                    break;
                }
            }
        } else if(a[c2].first == a[largest].first) {
            for(int j = 0; j < m1; ++j) {
                if(b[a[c2].second][j] < b[a[largest].second][j]) {
                    largest = c2;
                    break;
                }
            }
        }
    }
    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(pair <long long, int> a[], int n) {
    for(int i = n / 2 - 1; i >= 0; --i) heapify(a, n, i);
    for(int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n;
    fin >> n >> m1;
    pair <long long, int> p[n];
    for(int i = 0; i < n; ++i) {
        sum[i] = 0;
        for(int j = 0; j < m1; ++j) {
            fin >> b[i][j];
            sum[i] += b[i][j];
        }
        //fout << ":lamo" << endl;
        pair <int, int> temp = {sum[i], i}; 
        p[i] = temp;
    }
    // for(int i = 0; i < n; ++i) {
    //     fout << p[i].first << " " << p[i].second << endl;
    // }
    heap_sort(p, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m1; ++j) {
            fout << b[p[i].second][j] << " ";
        }
        fout << endl;
    }
}