#include <fstream>
#include <stack>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    string s;
    fin >> s;
    int n = s.size();
    stack <char> d;
    for(int i = 0; i < n; ++i) {
        if(d.empty()) d.push(s[i]);
        else if(d.top() == s[i]) d.pop();
        else d.push(s[i]);
    } 
    fout << (d.empty() ? "YES" : "NO");
}