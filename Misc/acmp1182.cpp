#include<bits/stdc++.h>

using namespace std;

const int N = 10 * 1000 + 5;
int x[N], n, m, k, l, r;

int main() {
    cin >> n >> k >> m;
    for (int e = 0; e < m; e++) {
        cin >> l >> r;
        int mx = *max_element(x + l, x + r);
        if (mx < k) {
            for (int i = l; i <= r; i++) x[i]++;
            cout << "Yes" << endl;
        } else
            cout << "No" << endl;
    }
    return 0;
}