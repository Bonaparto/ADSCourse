#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n, st, end;
    fin >> n >> st >> end;
    bool used[n];
    int d[n];
    int a[n][n];
    int inf = INT_MAX / 2;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
            if(a[i][j] == -1) a[i][j] = inf;
        }
    }
    st--;
    end--;

    for(int i = 0; i < n; ++i) {
        d[i] = inf;
        used[i] = false;
    }
    d[st] = 0;

    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!used[j]) {
                if(v == -1 || d[v] > d[j]) {
                    v = j;
                }
            }
        }
        if(d[v] >= inf) break;
        used[v] = true;
        for(int j = 0; j < n; ++j) {
            d[j] = min(d[j], d[v] + a[v][j]);
        }
    }
    if(d[end] >= inf) fout << -1;
    else fout << d[end];
}