#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector <vector<int>> vv;
vector <int> color;
vector <bool> used;

bool has_cycle(int v) {
    color[v] = 1;
    fout << v+1 << endl;
    for(int i = 0; i < vv[v].size(); ++i) {
        int next = vv[v][i];
        fout << next+1 << " " << color[next] << endl;
        if(color[next] == 1 || (color[next] == 0 && has_cycle(next))) return true;
    }
    color[v] = 2;
    return false;
}

int main(){
    int n, m;
    fin >> n >> m;
    color.assign(n, 0);
    used.assign(n, false);
    vv.resize(n);
    for(int i = 0; i < m; ++i) {
        int x, y; fin >> x >> y;
        vv[--x].push_back(--y);
        // vv[y].push_back(x);
    }   

    for(int i = 0; i < n; ++i) {
        // fout << i << endl;
        if(has_cycle(i)) {
            fout << "NO " << i;
            return 0;
        }
    }
}
