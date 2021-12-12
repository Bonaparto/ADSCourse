#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool used[105];
int a[105][105];
int n;


void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < n; ++i) {
        if(!used[i] && a[v][i] == 1) dfs(i);
    }
}

int main(){
    fin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        used[i] = false;
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
            if(a[i][j]) cnt++;
        }
    }

    if(cnt / 2 != n - 1) {
        fout << "NO";
        return 0;
    }
    
    bool f = 0;

    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            if(f) {
                fout << "NO";
                return 0;
            }
            dfs(i);
            f = 1;
        }
    }
    fout << "YES";
}