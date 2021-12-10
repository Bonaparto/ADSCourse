#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n;
    fin >> n;
    bool used[n];
    int d[n];
    int a[n][n];
    int inf = INT_MAX / 2;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
            if(a[i][j] == 0) a[i][j] = inf;
        }
    }
    
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] < inf && a[k][j] < inf)
                a[i][j] = min(a[i][j], a[i][j] + a[k][j]);
            }
        }
    }

}