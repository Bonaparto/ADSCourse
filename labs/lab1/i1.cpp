#include <iostream>
using namespace std;

struct Elem {
    int val;
    Elem *pr;
};

struct Stack {
    Elem *up;
    Stack () {
        up = NULL;
    }

    void push (int a) {
        Elem *tmp;
        tmp = new Elem();
        tmp->val = a;
        tmp->pr = up;
        up = tmp;
    }

    int pop () {
        if (up != NULL) {
            int v = up->val;
            Elem *tmp = up;
            up = up->pr;
            delete tmp;
            return v;
        } else {
            cerr << "empty stack" << endl;
            return 0;
        }
    }
    
    int back () {
        return up->val;
    }

    bool empty () {
        return up == NULL;
    }

    void free () {
        while (!empty ()) pop ();
    }

    ~Stack () {
        free ();
    }
};

int N, k;

Stack cont[501];

int main () {

    int tmp, i, j = 0, save = 1, qsave = 0;
    cin >> N;
    save = 1;
    if (N == 2) {
        bool ok = true, first = true;
        cin >> k;
        if (k) {
            cin >> tmp;
            i = 1;
            while (tmp == 1 && i < k) {
                cin >> tmp;
                ++i;
            }
            j = tmp == 2;
            while (i < k) {
                cin >> tmp;
                if (tmp == 1) ok = false;
                ++j;
                ++i;
            }
        }
        cin >> k;
        if (k) {
            cin >> tmp;
            i = 1;
            while (tmp == 2 && i < k) {
                cin >> tmp;
                ++i;
            }

            if (j && tmp == 1) ok = false;
            else if (tmp == 1) first = false;
            j += tmp == 1;

            while (i < k) {
                cin >> tmp;
                if (tmp == 2) ok = false;
                ++j;
                ++i;
            }
        }
        if (ok) {
            if (first)
            for (i = 0; i < j; ++i)
            cout << "1 2" << endl;
            else
            for (i = 0; i < j; ++i)
            cout << "2 1" << endl;
        }
        else cout << 0;
        return 0;
    }
    for (i = 1; i <= N; ++i) {
        cin >> k;
        if (k) {
            cin >> tmp;
            j = 1;
            while (tmp == i && j < k) {
                cin >> tmp;
                ++j;
            }
            if (tmp != i) cont[i].push (tmp);
            while (j < k) {
                cin >> tmp;
                cont[i].push (tmp);
                ++j;
            }
        }
    }
    for (i = 1; i < N; ++i) {
        while (!cont[i].empty ()) {
            while (!cont[i].empty () && cont[cont[i].back ()].empty ()) {
                cout << i << " " << cont[i].pop() << endl;
            }
            while (!cont[i].empty () && !cont[cont[i].back ()].empty ()) {
                cout << i << " " << N << endl;
                cont[N].push (cont[i].pop ());
            }
        }
        while (!cont[i].empty ()) {
            cout << i << " " << N << endl;
            cont[N].push (cont[i].pop ());
        }
    }
    while (!cont[N].empty ()) {
        tmp = cont[N].pop ();
        if (tmp == N) {
            cout << N << " " << save << endl;
            ++qsave;
        } else if (tmp == save) {
            save = 1 + save % 2;
            for (i = 0; i < qsave; ++i) {
                cout << tmp << " " << save << endl;
            }
            cout << N << " " << tmp << endl;
        } else {
            cout << N << " " << tmp << endl;
        }
    }
    for (i = 0; i < qsave; ++i) {
        cout << save << " " << N << endl;
    }
    return 0;
}