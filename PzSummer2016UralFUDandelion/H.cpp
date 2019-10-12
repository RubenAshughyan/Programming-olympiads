//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

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
#define dbl long double
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

const int MAXN = 1000+5;
const int MOD = 1e9 + 7;
const int N = 1005;
const int sz = 5000000;
int myQCont[sz];

struct Queue {
    int l, r;

    Queue() : l(0), r(0) {}

    inline void push(int val) {
        myQCont[r++] = val;
        r %= sz;
    }

    inline void pop() {
        l = (l + 1);
        if(l >= sz) l = 0;
    }

    inline int front() {
        return myQCont[l];
    }

    inline bool empty() {
        return l == r;
    }
};


char grid[N][N];
char avail[N][N];
int n, m;

bool valid(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void bfsMarkUnavailable(int x, int y) {
    Queue q;
    q.push(x);
    q.push(y);
    int cur_x, cur_y, dx,dy,xx,yy;

    while(!q.empty()) {
        cur_x = q.front(); q.pop();
        cur_y = q.front(); q.pop();

        for(dx = -1; dx <= 1; dx++) {
            for(dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                xx = cur_x + dx, yy = cur_y + dy;
                if (valid(xx, yy) && avail[xx][yy]) {
                    avail[xx][yy] = false;
                    if (grid[xx][yy] == '*') {
                        q.push(xx);
                        q.push(yy);
                    }
                }
            }
        }
    }
}

int houses[N][N], color = 1;
int dx[] = {-1, 0, 1, 0},
        dy[] = {0, -1, 0, 1};

void bfsMarkHouses(int x, int y) {
    Queue q;
    q.push(x);
    q.push(y);
    houses[x][y] = color;
    int cur_x, cur_y,d,xx,yy;

    while(!q.empty()) {
        cur_x = q.front(); q.pop();
        cur_y = q.front(); q.pop();
        houses[cur_x][cur_y] = color;

        for(d = 0; d < 4; d++) {
            xx = cur_x + dx[d], yy = cur_y + dy[d];
            if (valid(xx, yy) && grid[xx][yy] == '*' && houses[xx][yy] == 0) {
                houses[cur_x][cur_y] = color;
                q.push(xx);
                q.push(yy);
            }
        }
    }
}

bool used[1000005];
int cur_ans = 0;

void findAllHouses(int x, int y) {
    Queue q;
    q.push(x);
    q.push(y);
    avail[x][y] = false;
    while(!q.empty()) {
        int cur_x = q.front(); q.pop();
        int cur_y = q.front(); q.pop();

        if (houses[cur_x][cur_y] && !used[houses[cur_x][cur_y]]) {
            used[houses[cur_x][cur_y]] = true;
            cur_ans++;
        }

        for(int d = 0; d < 4; d++) {
            int xx = cur_x + dx[d], yy = cur_y + dy[d];
            if (valid(xx, yy) && avail[xx][yy]) {
                avail[xx][yy] = false;
                q.push(xx);
                q.push(yy);
            }
        }
    }
}

void printHouses() {
    cout << "_----------------------------------_" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (houses[i][j]);
        }
        cout << endl;
    }
    cout << "_----------------------------------_" << endl;
}

void test() {
    scanf("%d%d", &n, &m);
    memset(avail, true, sizeof(avail));
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (avail[i][j] && grid[i][j] == '*' && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                bfsMarkUnavailable(i, j);
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << (avail[i][j] ? grid[i][j] : '#');
//        }
//        cout << endl;
//    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (avail[i][j] && grid[i][j] == '*' && houses[i][j] == 0) {
                bfsMarkHouses(i, j);
                color++;
                //printHouses();
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (avail[i][j]) {
                cur_ans = 0;
                findAllHouses(i, j);
                ans = max(ans, cur_ans);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    loop(i,t) {
        test();
    }
    return 0;
}
/*
8 8
..*.....
...*....
........
........
......*.
.......*
........
........


*/