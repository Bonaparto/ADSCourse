#include <fstream>
#include <stack>
using namespace std;

const int N = 1e5 + 5;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        a[hs++] = x;
    }

    void sift_down(int x) {
        int i = x;
        while(2 * i + 1 < hs) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(r < hs && a[r] > a[l] && a[r] > a[i]) {
                swap(a[r], a[i]);
                i = r;
            } else if(a[l] > a[i]) {
                swap(a[l], a[i]);
                i = l;
            } else break;
        }
    }

    void sort(int x) {
        sift_down(x);
        // if(2 * x + 2 < hs) sort(2 * x + 2);
        // if(2 * x + 1 < hs) sort(2 * x + 1);
        // if(2 * x + 1 < hs) sift_down(x);
    } 

    int extract() {
        int top = a[0];
        a[0] = a[--hs];
        sift_down(0);
        return top;
    }

    void print() {
        for(int i = 0; i < hs; ++i) {
            fout << a[i] << " ";
        }
        fout << "\n";
    }
};

int main(){
    int n;
    heap h;
    stack <int> s;
    fin >> n;
    for(int i = 0; i < n; ++i) {
        int x; fin >> x;
        h.add(x);
    }

    for(int i = n / 2 - 1; i >= 0; --i) h.sort(i);
    //h.sort(0);
    
    for(int i = 0; i < n; ++i) s.push(h.extract());
    
    while(!s.empty()) {
        fout << s.top() << " ";
        s.pop();
    }
}