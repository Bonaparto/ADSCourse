#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, ans = 0;
    fin >> n;
    int a[n][n];    
    int color[n];
    bool used[n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        } 
        used[i] = false;
    }
    for(int i = 0; i < n; ++i) {
        fin >> color[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == 1 && !used[j] && color[i] != color[j]) {
                ans++;
            } 
        }
        used[i] = true;
    }
    fout << ans;
}