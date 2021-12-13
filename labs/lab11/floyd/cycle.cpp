#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

int main() { 
    int n;
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
                if(a[i][k] != 0 && a[k][j] != 0) {
                    a[i][j] = max(a[i][j], a[i][k] + a[k][j]);                   
                }
            }
        }
    } 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] != 0 && a[j][i] != 0) {
                fout << 1;
                return 0;
            }
        }
    }
    fout << 0;
}

