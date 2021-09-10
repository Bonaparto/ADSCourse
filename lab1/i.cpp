#include <fstream>
#include <stack>
#include <queue>
using namespace std;
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    bool f = 1;
    stack <int> st, st1;
    queue <int> q;
    fin >> n;
    for(int i = 0; i < n; ++i) {
        int x; fin >> x;
        for(int j = 0; j < x; ++j) {
            int z; fin >> z;
            if(z > n) {
                fout << 0;
                return 0;
            }
            if(f && z != i + 1) f = 0;
            if(i == 0) st1.push(z);
            else st.push(z);
        }
        if(i != 0) {
            q.push(st.size());
            for(int j = 0; j < x; ++j) {
                if(n == 2 && st.top() == 1 && st1.top() == 2) {
                    fout << 0;
                    return 0;
                }
                st1.push(st.top());
                st.pop();
            }
        }
    }
    
    if(f) return 0;
    int cnt = 2;

    while(q.size() != 0) {
        for(int i = 0; i < q.front(); ++i) fout << cnt << " " << 1 << endl;
        q.pop(); cnt++;
    }
    
    for(int i = 1; i <= n - 2; ++i) {
        int m = st1.size();
        for(int j = 0; j < m; ++j) {
            if(i + 1 != st1.top()) {
                st.push(st1.top());
                fout << 1 << " " << i + 2 << endl;
            } else {
                fout << 1 << " " << i + 1 << endl;
            }
            st1.pop();   
        }
        m = st.size();
        for(int j = 0; j < m; ++j) {
            fout << i + 2 << " " << 1 << endl;
            st1.push(st.top());
            st.pop();
        }
    } 

    int r = st1.size(); 
 
    for(int i = 0; i < r; ++i) { 
        if(st1.top() == n) fout << 1 << " " << n << endl;
        else {
            fout << 1 << " " << 2 << endl;
            st.push(st1.top());
        }
        st1.pop();    
    }
    r = st.size();
    for(int i = 0; i < r; ++i) fout << 2 << " " << 1 << endl;
}
