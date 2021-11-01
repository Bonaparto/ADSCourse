#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int b[501][501];
int m1;

void merge(pair <long long, int> a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0, j, k;
    pair <long long, int> L[n1], R[n2];
    for(i = 0; i < n1; ++i) {
        L[i].first = a[l+i].first;
        L[i].second = a[l+i].second;
    }
    for(i = 0; i < n2; ++i) {
        R[i].first = a[i+m+1].first;
        R[i].second = a[i+m+1].second;
    }

    i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i].first > R[j].first) {
            a[k].first = L[i].first;
            a[k].second = L[i].second;
            i++;
        } else if(L[i].first < R[j].first) {
            a[k].first = R[j].first;
            a[k].second = R[j].second;
            j++;
        } else {
            //fout << "lmao " << endl;
            for(int d = 0; d < m1; ++d) {
                if(b[L[i].second][d] > b[R[j].second][d]) {
                    a[k].first = R[j].first;
                    a[k].second = R[j].second;
                    j++;
                    break;
                } else if (b[L[i].second][d] < b[R[j].second][d]) {
                    a[k].first = L[i].first;
                    a[k].second = L[i].second;
                    i++;
                    break;
                }
                //fout << b[L[i].second][d] << " " << b[R[j].second][d] << 
                //" " << L[i].second << " " << R[j].second << endl;
            }
        } 
        k++;
    }
    //fout << "kek" << endl;
    while(i < n1) {
        a[k].first = L[i].first;
        a[k].second = L[i].second;
        k++;
        i++;
    }
    while(j < n2) {
        a[k].first = R[j].first;
        a[k].second = R[j].second;
        k++;
        j++;
    }
}

void merge_sort(pair <long long, int> a[], int l, int r) {
    if(l < r) {
        //fout << "Wtf" << endl;
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int n;
    fin >> n >> m1;
    long long sum[n];
    pair <long long, int> p[n];
    for(int i = 0; i < n; ++i) {
        sum[i] = 0;
        for(int j = 0; j < m1; ++j) {
            fin >> b[i][j];
            sum[i] += b[i][j];
        }
        //fout << ":lamo" << endl;
        pair <int,int> temp = {sum[i], i}; 
        p[i] = temp;
    }
    // for(int i = 0; i < n; ++i) {
    //     fout << p[i].first << " " << p[i].second << endl;
    // }
    merge_sort(p, 0, n - 1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m1; ++j) {
            fout << b[p[i].second][j] << " ";
        }
        fout << endl;
    }
}