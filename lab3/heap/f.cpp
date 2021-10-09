#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt"); 

const int N = 1e5 + 5; 

struct heap {
    int h[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        h[i] = x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    void print() {
        for(int i = 0; i < hs; ++i) {
            fout << h[i] << " ";
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
    h.print();
}