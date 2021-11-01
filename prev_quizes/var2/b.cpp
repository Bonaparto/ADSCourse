#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e5 + 5;

string convert_back(int l) {
    int year = floor(l / 400);
    l %= 400;
    int month = floor(l / 31);
    l %= 31;
    int day = l;
    string s = to_string(month) + " " + to_string(day) + " " + to_string(year);
    return s;
}

long long convert_to_days(int a, int b, int c) {
    return a + b * 31 + c * 400;
}

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        a[i] = x;
        int p = (i - 1) / 2;
        while(i && a[i] < a[p]) {
            swap(a[i], a[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    string extract() {
        int top = a[0];
        a[0] = a[--hs];
        int i = 0;
        while(2 * i + 1 < hs) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(r < hs && a[r] < a[0] && a[r] < a[l]) {
                swap(a[r], a[i]);
                i = r;
            } else if(a[l] < a[i]) {
                swap(a[l], a[i]);
                i = l;
            } else break;
        }
        return convert_back(top);
    }

};
 
int main(){
    int n;
    fin >> n;
    heap h;
    for(int i = 0; i < n; ++i) {
        int day, month, year;
        fin >> month >> day >> year;
        h.add(convert_to_days(day, month, year));
        fout << convert_to_days(day, month, year) << endl;
    }
    for(int i = 0; i < n; ++i) {
        fout << h.extract() << endl;
    }
}