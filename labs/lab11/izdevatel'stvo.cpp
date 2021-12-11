#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n, m = 3001, f, s, t;
    fin >> n;
    int a[n][n]; 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        } 
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            for(int k = j+1; k < n; ++k) {
                int cur = a[i][j] + a[j][k] + a[k][i]; 
                if(cur < m) {
                    m = cur;
                    f = i;
                    s = j;
                    t = k; 
                }
            }
        }
    }
    fout << f + 1 << " " << s + 1 << " " << t + 1; 
}