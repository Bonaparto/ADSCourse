#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector <int> max_substring_length(string s, string s1) {
    string s2 = s + '#' + s1;
    int n = s2.length();
    vector <int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s2[i] != s2[j]) j = pi[j-1];
        if(s2[i] == s2[j]) j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
    int n;
    string s, s1;
    fin >> n >> s >> s1;
    vector <int> pi = max_substring_length(s, s1);
    for(int i = pi.size() - 1; i > int(s.length()); --i) {
        string temp = s;
        rotate(temp.begin(), temp.begin() + pi[i], temp.end());
        if(temp == s1) {
            fout << s.length() - pi[i];
            return 0;
        }
    }
    fout << -1;
}