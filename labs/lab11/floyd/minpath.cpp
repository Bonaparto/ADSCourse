#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

int main() { 
    int n, ans = 1e8, inf = 1e8;
    fin >> n;
    int a[n][n];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[k][j] < inf && a[j][j] < 0 && a[j][i] < inf) {
                    fout << -1;
                    return 0;
                }
                if(a[i][j] < ans && i != j) ans = a[i][j];
            }
        }
    } 
    fout << ans;
}
