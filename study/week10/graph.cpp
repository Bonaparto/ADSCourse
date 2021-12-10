#include <fstream>
#include <queue>
using namespace std;

ifstream fin("inputgraph.txt");
ofstream fout("outputgraph.txt");

#define N 100

bool used[N];
int a[N][N];
int n;

// void dfs(int v) {
//     used[v] = true;
//     fout << v << " ";
//     for(int i = 0; i < n; ++i) {
//         if(a[v][i] == 1 && !used[i]) {
//             dfs(i);
//         }
//     }
// }


int main(){
   fin >> n;
   int cnt = 0;
   for(int i = 0; i < n; ++i) {
       for(int j = 0; j < n; ++j) {
           fin >> a[i][j];
       }
   }  

   queue<int> q;
   q.push(0);
   used[0] = true;
   fout << 0 << " ";
   while(!q.empty()) {
       int cur = q.front();
       q.pop();
       for(int i = 0; i < n; ++i) {
           if(a[cur][i] == 1 && !used[i]) {
               q.push(i);
               fout << i << " ";
               used[i] = true;
           }
       }
   }
    //    dfs(0);
    // обход циклом 
    //    for(int i = 0; i < n; ++i) {
    //        for(int j = 0; j < n; ++j) {
    //            if(a[i][j] == 1) cnt++;
    //        }
    //    } 
   fout << cnt;
}