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
//#define i first
//#define j second

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


const int N = 1000 * 1000 + 7;
const ll MOD = (1ll << 32);


ll p233[N];

int n;
char g[18][18];

ll answer;

int color[18];
int mask;
int k;

bool backtrack(int i) {
//    printf("back track %d\n", i);

    if (i == n) return true;
    if (((mask >> i) & 1) == 0) return backtrack(i + 1);


    int mx = 0;
    for (int j = 0; j < i; j++) {
        mx = max(mx, color[j]);
    }

    int upto = min(mx + 2, k);
    loop(c, upto) {
//    loop(c,k){
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (((mask >> j) & 1) && (g[i][j])) {
                ok &= color[j] != c;
                if (!ok) break;
            }
        }

        if (!ok) continue;

        color[i] = c;
        if (backtrack(i + 1)) return true;
    }


    return false;
}

bool can(int msk, int curK) {
    if (curK == 0) return false;

//    printf("can: %d %d\n", msk, curK);

    mask = msk;
    k = curK;
    loop(i, n) color[i] = -1;

    int ones = 0;
    loop(i, n) ones += ((msk >> i) & 1);
    if (ones == 1) return true;

    int i = 0;
    int GI = 0;
    while (true) {
        if ((msk >> i) & 1) {
            color[i] = GI++;
            if (GI == 2) break;
        }
        i++;
    }

    return backtrack(i);
}

int ans[N];

void test() {
    cin >> n;
    loop(i, n) {
        string s;
        cin >> s;
        loop(j, n) {
            g[i][j] = s[j] == '1';
        }
    }


    int total = (1 << n);

    answer = 0;

//    db(total);
    loop(msk, total) {
        if (msk == 0) continue;

        int ones = 0;
        loop(i, n) ones += ((msk >> i) & 1);

//        if (ones >= 12) {

//            cout << endl;
//            cout << "msk: ";
//            loop(i, n) {
//                if ((msk >> i) & 1) cout << i << ' ';
//            }
//            cout << endl;

        int curK;

        if (ones == 1) {
            curK = 1;
        } else {


            bool ok = false;
            curK = -1;

            loop(i, n) {
                if ((msk >> i) & 1) {
                    int childMsk = msk ^(1 << i);
                    if (curK == -1) {
                        curK = ans[childMsk];
                    } else if (curK != ans[childMsk]) {
                        curK = max(curK, ans[childMsk]);
                        ok = true;
                    }
                }
            }

            if (ok) {
                curK;
            } else if (can(msk, curK)) {
                curK;
            } else {
                curK ++;
            }
        }
        ans[msk] = curK;



        answer += p233[msk] * (ans[msk]);
        answer %= MOD;
    }

    cout << answer << endl;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    // precalc
    p233[0] = 1;
    for (int i = 1; i < N; i++) {
        (p233[i] = p233[i - 1] * 233) %= MOD;
    }

    int T;
    cin >> T;
    loop(t, T) test();

    return 0;
}
