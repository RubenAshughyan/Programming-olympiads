#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int DEBUG = 1;

int n;
vector<pair<pii, int> > canvas;
int p;
vector<int> pegs;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        canvas.emplace_back(MP(l, r), 2);
    }
    cin >> p;
    for (int j = 0; j < p; ++j) {
        int pg;
        scanf("%d", &pg);
        pegs.emplace_back(pg);
    }
    for (int pi = 0, ci = 0; pi < p && ci < n;) {
        if (canvas[ci].first.first > pegs[pi]) {
            pi++;
            continue;
        }
        if (canvas[ci].first.second < pegs[pi]) {
            ci++;
            continue;
        }
        if (canvas[ci].second == 0) {
            cout << "impossible" << endl;
            return 0;
        }
        canvas[ci].second--;
        if (canvas[ci].first.second == pegs[pi])
            ci++;
        else
            pi++;
    }

    for (int i = 0; i < n; ++i) {
        if (canvas[i].second == 0) {
            if (i)
                canvas[i - 1].first.second--;
            if (i + 1 != n)
                canvas[i + 1].first.first++;
        }
    }

    set<int> pps(all(pegs));
    vector<int> pgs;
    for (int i = 0; i < n; ++i) {
        if (canvas[i].second == 0)
            continue;
        if (canvas[i].second == 2) {
            pgs.push_back(canvas[i].first.first);
        }
        while (pps.find(canvas[i].first.second) != pps.end())
            canvas[i].first.second--;
        pgs.push_back(canvas[i].first.second);
        if (i + 1 != n && canvas[i + 1].first.first == canvas[i].first.second){
            canvas[i + 1].second--;
        }
    }
    cout << pgs.size() << endl;
    for (int i = 0; i < pgs.size(); ++i) {
        cout << pgs[i] << " ";
    }
    return 0;
}

/*
1
0 15
0

2
0 15
15 26
1
15

2
0 15
15 26
1
26


3
0 15
15 26
26 36
3
5 10 28

1
1 11
12
3 15 17 19 22 25 27 29 31 32 41 45


 7
1 10
10 20
 20 30
 31 40
 40 50
 50 60
 60 70
0
1 70
 */