#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e5 + 5;

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        a[i] = x;
    } 

    void sift_down(int x) {
        int i = x;
        while(2 * i + 1 < hs) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(r < hs && a[r] > a[l] && a[r] > a[i]) {
                swap(a[i], a[r]);
                i = r;
            } else if(a[l] > a[i]) {
                swap(a[l], a[i]);
                i = l;
            } else break;
        }
    }

    void sort(int x) {
        if(2 * x + 2 < hs) sort(2 * x + 2);
        if(2 * x + 1 < hs) sort(2 * x + 1);
        if(2 * x + 1 < hs) sift_down(x);
    }

    void print() {
        for(int i = 0; i < hs; ++i) {
            fout << a[i] << " "; 
        }
    }
};


int main(){
    int n;
    heap h;
    fin >> n;
    while(n--) {
        int x; fin >> x;
        h.add(x);
    }
    h.sort(0);
    h.print();
}