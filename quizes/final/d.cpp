#include <iostream>
#include <map>
using namespace std;

// ifstream fin("intput.txt");
// ofstream fout("output.txt");

const int N = 1e6;

typedef pair<int,int> pii;

int ans = 0;

struct node {
    int val;
    node * right;
    node * left;
    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst {
    private: 

        node * root;

        node * add(node * current, int x) {
            if(current == NULL) return new node(x);
            if(current->val < x) current->right = add(current->right, x);
            else if(current->val > x) current->left = add(current->left, x);
            return current;
        }

        // int right_height(node * current) {
        //     int l = 0, r = 0;
        //     if(current != NULL) {
        //         r++;
        //         r += right_height(current->right);
        //         l += right_height(current->left);
        //     }
        //     return max(r, l);
        // }

        int height(node * current, int len) {
            int l = 0, r = 0;
            if(current != NULL) {
                l = height(current->left, 0);
                r = height(current->right, 0);
                len += max(l, r);
                if(current != root) len++;
            }
            return len;
        }

        void max_dst(node * current) {
            int l = 0, r = 0;
            // cout << l << " " << r << " " << endl;
            if(current != NULL){
                // cout << current->val << endl;
                max_dst(current->left);
                max_dst(current->right);
                l = height(current->left, 0);
                r = height(current->right, 0);
                // cout << l << " " << r << " " << current->val << endl;
                if(l + r + 1 > ans) ans = l + r + 1;
            }
        }

    public: 

        bst() {
            root = NULL;
        }

        void add(int x) {
            node * res = add(root, x);
            if(root == NULL) root = res;
        }

        void find_max_dist() {
            max_dst(root);
        }
};

int main() {
    int n;
    cin >> n;
    bst bs;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        bs.add(x);
    }
    // int ans 
    bs.find_max_dist();
    cout << ans;
}