#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int N = 100 * 1000 + 5;
int n, k, m;

int st[4 * N];
int lazy[4 * N];

void push(int v, int l, int r) {
    if (lazy[v] != 0) {
        st[v] += lazy[v];
        if (r != l) {
            lazy[2 * v + 1] += lazy[v];
            lazy[2 * v + 2] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void update(int v, int l, int r, int ql, int qr) {
    push(v, l, r);

    if (qr < l || r < ql) {
        return;
    }

    if (ql <= l && r <= qr) {
        lazy[v] = +1;
        push(v, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(2 * v + 1, l, mid, ql, qr);
    update(2 * v + 2, mid + 1, r, ql, qr);
    st[v] = max(st[2 * v + 1], st[2 * v + 2]);
}

int get(int v, int l, int r, int ql, int qr) {
    push(v, l, r);

    if (qr < l || r < ql) {
        return -1e9;
    }

    if (ql <= l && r <= qr) {
        return st[v];
    }

    int mid = (l + r) / 2;
    return max(
            get(2 * v + 1, l, mid, ql, qr),
            get(2 * v + 2, mid + 1, r, ql, qr)
    );
}

int main() {
    cin >> n >> k >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        y--;

        bool is_pos = get(0, 0, n - 1, x, y) < k;

        if (is_pos) {
            cout << "Yes" << endl;
            update(0, 0, n - 1, x, y);
        } else {
            cout << "No" << endl;
        }
    }

}
