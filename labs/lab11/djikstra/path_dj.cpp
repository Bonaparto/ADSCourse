#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n, st, end, inf = 200;
    fin >> n >> st >> end;
    int a[n][n];
    int d[n];
    int p[n];
    bool used[n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
            if(a[i][j] == -1) a[i][j] = inf;
        }
    } 

    for(int i = 0; i < n; ++i) {
        used[i] = 0;
        d[st] = inf;
    }
    --st; --end;
    d[st] = 0;

    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!used[j] && (v == -1 || d[j] < d[v])) v = j;
        }        
        if(d[v] >= inf) break;
        used[v] = 1;
        for(int j = 0; j < n; ++j) {
            if(d[j] > d[v] + a[v][j]) {
                d[j] = d[v] + a[v][j];
                p[j] = v;
                // fout << j << " " << d[j] << endl;
            }
        }
    }

    if(d[end] >= inf) fout << -1;
    else {
        vector <int> ans;
        for(int i = end; i != st; i = p[i]) {
            ans.push_back(i);
        }
        ans.push_back(st);
        reverse(ans.begin(), ans.end());
        for(auto i: ans) {
            fout << i + 1 << " ";
        }
    }
}