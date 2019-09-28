
#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

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

const int N = 5000;

int n;
dbl r[N];

map<int, dbl> merge(map<int, dbl> a, map<int, dbl> b) {
    map<int, dbl> c;
    for (auto pa : a) {
        for (auto pb: b) {
            c[pa.first] += pa.second * pb.second * (r[pa.first] / (r[pa.first] + r[pb.first]));
            c[pb.first] += pa.second * pb.second * (r[pb.first] / (r[pa.first] + r[pb.first]));
        }
    }
    return c;
}

dbl solve() {
    vc<map<int, dbl>> v;
    vc<map<int, dbl>> nv;

    loop(i, n) {
        map<int, dbl> mp;
        mp[i] = 1.0;
        v.push_back(mp);
    }

    int p2 = 1;
    while (p2 * 2 <= n) {
        p2 *= 2;
    }


    loop(i, 2 * p2 - n) {
        nv.push_back(v[i]);
    }
    for (int i = nv.size(); i < v.size(); i += 2) {
        nv.push_back(merge(v[i], v[i + 1]));
    }

    while (nv.size() != 1) {
        vc<map<int, dbl>> NV;
        for (int i = 0; i < nv.size(); i += 2) {
            NV.push_back(merge(nv[i], nv[i + 1]));
        }
        nv = NV;
    }
    return nv[0][0];
}

int main() {
    cin >> n;
    loop(i, n) {
        cin >> r[i];
    }
    sort(r + 1, r + n);

//    while (1) {
//        random_shuffle(r + 1, r + n);

        dbl ans = solve();
        printf("%.10Lf\n", ans);

//        if (abs(ans - 0.364285714) < 0.001) {
//            loop(i, n) cout << r[i] << ' ';
//            cout << endl;
//            exit(0);
//        }
//    }

//  printf("%.10lf\n", nv[0][0]);
}lllll
/*

 4
3
1
2
4


 5
1
1
3
3
3

*/