#include <iostream>
#include <cmath>
using namespace std;

struct node {
    long long val;
    node * left;
    node * right;
    node(long long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst { 
    node * root;

    bst() {
        root = NULL;
    }

    node * add(node * current, long long x) {
        if(current == NULL) return new node(x);

        if(current->val > x) current->left = add(current->left, x);
        else if(current->val < x) current->right = add(current->right, x);

        return current;
    }

    void add(long long x) {
        node * res = add(root, x);
        if(root == NULL) root = res;
    }

    void print(node * current) {
        if(current != NULL) {
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    void print() {
        print(root);
    }
};

void merge(long long a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0, j, k;
    long long L[n1], R[n2];
    for(int i = 0; i < n1; ++i) L[i] = a[l+i];
    for(int i = 0; i < n2; ++i) R[i] = a[m+i+1];

    i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void merge_sort(long long a[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int k, n;
    cin >> k;
    n = pow(2, k) - 1;
    long long a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    merge_sort(a, 0, n - 1);

    int m = (n - 1) / 2;

    bst bs;

    bs.add(a[m]);

    for(int i = 0; i < n; ++i) {
        if(i == m) continue;
        else bs.add(a[i]);
    }   

    bs.print();

}