#include <iostream>
#include <stack>
using namespace std;

int to_int(string s) {
    if(s.length() == 1) return int(s[0] - 48);
    else return(stoi(s));
}

int main(){
    stack <long long> st;
    char c;
    string s, temp = "";
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == ' ' && temp.length() != 0) {
            long long num = to_int(temp);
            st.push(num);
            temp = "";
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9') {
            temp = temp + s[i];
        } else if(s[i] != ' '){
            long long l = 0;
            if(s[i] == '+') {
                l += st.top();
                st.pop();
                l += st.top();
                st.pop();
            }
            else if(s[i] == '-') {
                l -= st.top();
                st.pop();
                l += st.top();
                st.pop();
            }
            else {
                l += st.top();
                st.pop();
                l *= st.top();
                st.pop();
            }
            st.push(l);
        }
    }
    cout << st.top();
}