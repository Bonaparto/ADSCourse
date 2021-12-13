#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void bfs(int st, int end) {
    queue <long long> q;
    vector <long long> p(20005);
    p.assign(20005, -1);
    q.push(st);
    while(!q.empty()) {
        long long temp = q.front();
        q.pop();
        if(temp == end) break;
        if(temp * 2 <= 10000 && p[temp*2] == -1) {
            q.push(temp * 2);
            p[temp*2] = temp;
        }
        if(p[temp-1] == -1) {
            q.push(temp - 1);
            p[temp-1] = temp;
        }
        fout << temp << endl;
    }
    vector <long long> ans;
    for(long long i = end; i != st; i = p[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    fout << ans.size() << endl; 
    for(auto i: ans) fout << i << " ";
}

int main() {
    int n, m;
    fin >> n >> m;
    bfs(n, m);
}