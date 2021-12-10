#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e6 + 5;
int m;

struct vertex {
    int next[10];
    string code;
    string city;
    bool isEnd = false;
    int num;
};

vertex t[N];
int sz = 1;

void init(){
    for(int i = 0; i < 10; ++i) {
        t[0].next[i] = -1;
        t[0].num = pow(10, m);
    } 
}

void add_number(string n, string s) {
    int v = 0;
    int tot = t[v].num;
    for(long long i = 0; i < n.length(); ++i) {
        int c = n[i] - '0';
        if(t[v].next[c] == -1) {
            for(int j = 0; j < 10; ++j) {
                t[sz].next[j] = -1;
            }
            t[v].next[c] = sz++;
        } 
        v = t[v].next[c];
        tot /= 10;
        t[v].num = tot;
    }
    t[v].isEnd = true;
    t[v].city = s;
}

int find_lower_cities(int v, int tot, int sum) {
    if(t[v].isEnd) { 
        return sum + tot;
    }

    for(int i = 0; i < 10; ++i) {
        if(t[v].next[i] != -1) {
            sum += find_lower_cities(t[v].next[i], tot / 10, 0);
        }
    } 

    return sum;
}

void substract(string n) {
    int v = 0;
    for(long long i = 0; i < n.length(); ++i) {
        int c = n[i] - '0';
        v = t[v].next[c];
    }
    int tot = t[v].num;

    for(int i = 0; i < 10; ++i) {
        if(t[v].next[i] != -1) {
            t[v].num -= find_lower_cities(t[v].next[i], tot / 10, 0);
        }
    } 
}

void search(string n) {
    int v = 0;
    for(long long i = 0; i < n.length(); ++i) {
        int c = n[i] - '0';
        v = t[v].next[c];
    }
    fout << t[v].city << " " << t[v].num << endl;
}

int main() {
    int n;
    fin >> n >> m;
    string a[n];
    init();
    for(int i = 0; i < n; ++i) {
        string x, s;
        fin >> x >> s;
        a[i] = x;
        add_number(x, s);
    }

    for(int i = 0; i < n; ++i) substract(a[i]);

    for(int i = 0; i < n; ++i) search(a[i]);
    
}