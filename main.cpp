#include <bits/stdc++.h>

using namespace std;

int x[9][9];

bool r[9][10], c[9][10], s[3][3][10];

void put(int i, int j, int d) {
    r[i][x[i][j]] = c[j][x[i][j]] = s[i/3][j/3][x[i][j]] = false;
    x[i][j] = d;
    r[i][d] = c[j][d] = s[i/3][j/3][d] = true;
}

bool solve(int i, int j) {
    while (i < 9 ) {
        if (x[i][j] == 0) {
            for (int d = 1; d <= 9; d++) {
                if (!r[i][d] && !c[j][d] && !s[i/3][j/3][d]) {
                    put(i, j, d);
                    if (solve(i, j)) {
                        for (i = 0; i < 9; i++) {
                            for (j = 0; j < 9; ++j)
                                cout << x[i][j] << ' ';
                            cout << endl;
                        }
                        exit(0);
                    } else
                        put(i, j, 0);
                }
            }
            return false;
        }
        j++;
        if (j == 9)
            j = 0, i++;
    }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> x[i][j];
            put(i, j, x[i][j]);
        }
    solve(0, 0);
}