#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt"); 

const int N = 1e5 + 5; 
int n;

struct heap {
    int h[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {

        if(hs == n) {
            fout << -1 << endl;
            return;
        }

        int i = hs++;
        h[i] = x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
        fout << i + 1 << endl;
    }
 
    void del(int x) {
        if(x > hs || x <= 0) {
            fout << -1 << endl;
            return;
        }
        int rem = h[--x];
        h[x] = h[--hs];
        if(h[x] < rem) {
            while(x * 2 + 1 < hs) {
                int c1 = x * 2 + 1;
                int c2 = x * 2 + 2;
                if(c2 < hs && h[c2] > h[c1] && h[c2] > h[x]) {
                    swap(h[c2], h[x]);
                    x = c2;
                } else if(h[c1] > h[x]) {
                    swap(h[c1], h[x]);
                    x = c1;
                } else break;
            }
        } else {
            int p = (x - 1) / 2;
            while(x && h[x] > h[p]) {
                swap(h[x], h[p]);
                x = p;
                p = (x - 1) / 2;
            }
        }
        fout << rem << endl;
    }

    void extract() {

        if(hs == 0) {
            fout << -1 << endl;
            return;
        }
        
        int mx = h[0];
        if(hs == 1) {
            fout << 0 << " " << mx << endl;
            hs--;
            return;
        }

        h[0] = h[--hs];
        int i = 0;
        while(2 * i + 1 < hs) {
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            if(c2 < hs && h[c2] > h[c1] && h[c2] > h[i]) {
                swap(h[c2], h[i]);
                i = c2;
            } else if(h[c1] > h[i]) {
                swap(h[c1], h[i]);
                i = c1; 
            } else break;
        }
        fout << i + 1 << " " << mx << endl;
    }

    void print() {
        for(int i = 0; i < hs; ++i) {
            fout << h[i] << " ";
        }
    }
};

int main(){
    int m;
    heap h;
    fin >> n >> m;
    while(m--) {
        int x; fin >> x;
        if(x == 1) h.extract();
        else if(x == 2) {
            int y; fin >> y;
            h.add(y);
        } else {
            int y; fin >> y;
            h.del(y);
        }
    }
    h.print();
}