#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

enum DIR {U, D, L, R};
int dx[] = {0, 0, -1, 1},
    dy[] = {1, -1, 0, 0};
int x, y;

int h, w;

void move(DIR d) {
    cout << y << " " << x << endl;
    y += dy[d];
    x += dx[d];
    if (x < 1 || y < 1 || x == w || y == h) {
        exit(0);
    }
}


int main() {
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 0 << endl;
        return 0;
    }
    x = y = 1;
    cout << (h * w - 2) / 2 << endl;
    if (h % 2 == 0) {
        while (true) {
            for (int i = 0; i < w - 2; i++) {
                move(R);
            }
            move(U);
            move(U);
            for (int i = 0; i < w - 2; i++) {
                move(L);
            }
            move(U);
            move(U);
        }
    }
    else {
        DIR d = R;
        while(y != h - 2) {
            for(int i = 0; i < w - 2; i++) {
                move(d);
            }
            move(U);
            move(U);
            d = (d == L ? R : L);
        }
        DIR pp = U;
        while(true) {
            move(pp);
            move(d);
            move(d);
            pp = (pp == U ? D : U);
        }
    }
    return 0;
}
/*
3
2
1<3
1>2

*/