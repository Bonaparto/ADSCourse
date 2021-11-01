#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e5 + 5;
long long sum = 0;

struct heap {
    long long h[N];
    int hs;

    heap(){
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        h[i] = x;
    }

    void extract() {
        int i = 0, k = 0;
        if(h[2*i+1] <= h[2*i+2]) {
            k = 2 * i + 1;
            h[k] += h[i];
        } else {
            if(2 * i + 2 < hs){ 
                k = 2 * i + 2;
                h[k] += h[i];
            } else {
                k = 2 * i + 1;
                h[k] += h[i];
            }
        }
        sum += h[k];
        sift_down(k);
        h[0] = h[--hs];
        sift_down(0);
    }

    void sift_down(int x) {
        int i = x;
        while(2 * i + 1 < hs) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(r < hs && h[r] < h[l] && h[r] < h[i]) {
                swap(h[r], h[i]);
                i = r;
            } else if(h[l] < h[i]) {
                swap(h[l], h[i]);
                i = l;
            } else break;
        }
    }

    void sort() {
        for(int i = hs / 2 - 1; i >= 0; --i) sift_down(i);
    }

    void print() {
        int i = 0;
        while(i < hs) {
            fout << h[i] << " ";
            i++;
        }
        fout << endl;
    }
};


int main(){
    int n;
    fin >> n;
    heap h;
    for(int i = 0; i < n; ++i) {
        int x; fin >> x;
        h.add(x);
    }
    h.sort();
    // h.print();
    for(int i = 0; i < n - 1; ++i) {
        h.extract();
        //h.print();
    } 
    fout << sum;
}