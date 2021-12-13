#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

int main() { 
    int n, st, end, inf = 1e8;
    fin >> n >> st >> end;
    int a[n][n];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
            if(a[i][j] == -1) a[i][j] = inf;
        }
    }

    --st; --end;

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][k] < inf && a[k][j] < inf) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    } 
    if(a[st][end] == 100000000) fout << -1 << endl;
    else fout << a[st][end];
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         fout << a[i][j] << " ";
    //     }
    //     fout << endl;
    // }
}