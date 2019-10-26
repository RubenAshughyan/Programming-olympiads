#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define msk first
#define cnt second

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

#define printf(...) (0)
#define db(x) if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;
int DEBUG = 0;
const int N = 100 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
ll dpA[N][N][N];
ll dpB[N][N][N];

ll n;
string a, b;
ll ka, kb;


int get_new_suff(int sl, char ch, bool &new_oc, int who) {
    string &A = who == 0 ? a : b;

    new_oc = false;

    string new_suff = A.substr(0, sl);
    new_suff.push_back(ch);

    int best_l = 0;
    for (int n_sl = 1; n_sl <= new_suff.length(); n_sl++) {
        if (new_suff.substr(new_suff.length() - n_sl) == A.substr(0, n_sl)) {

            if (n_sl == A.length()) {
                new_oc = true;
            } else {
                best_l = n_sl;
            }
        }
    }

    return best_l;
}


int main() {
//    freopen("in.txt", "r", stdin);

    cin >> n;
    cin >> a >> ka;
    cin >> b >> kb;


    db(a);
//
    // fill -1
    loop(i, N) loop(j, N) loop(l, N) dpA[i][j][l] = 0;


    dpA[0][0][0] = 1;
    // push forward states
    for (int len = 0; len < n; len++) {
        for (int sl = 0; sl < a.length(); sl++) {
            for (int k = 0; k <= n - 1; k++) {
                ll cur_dp = dpA[len][sl][k];

                // add one letter
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    bool new_occurence;
                    int new_sl = get_new_suff(sl, ch, new_occurence, 0);

                    ll &new_dp = dpA[len + 1][new_sl][k + new_occurence];

                    if(cur_dp){
                        db(ch);
                        printf("from (%d %d %d) -> (%d %d %d) [%lld]\n", len, sl, k, len+1, new_sl, k+new_occurence, cur_dp);
                    }

                    (new_dp += cur_dp) %= MOD;
                }
            }
        }
    }

    for (int len = 0; len <= n; len++) {
        for (int sl = 0; sl < a.length(); sl++) {
            for (int k = 0; k <= n; k++) {
                printf("dpA[%d][%d][%d] ->\t %lld\n", len, sl, k, dpA[len][sl][k]);
            }
        }
    }



    //////////////////////////////////////
    // fill -1
    loop(i, N) loop(j, N) loop(l, N) dpB[i][j][l] = 0;


    dpB[0][0][0] = 1;
    // push forward states
    for (int len = 0; len < n; len++) {
        for (int sl = 0; sl < b.length(); sl++) {
            for (int k = 0; k <= n - 1; k++) {
                int cur_dp = dpB[len][sl][k];

                // add one letter
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    bool new_occurence;
                    int new_sl = get_new_suff(sl, ch, new_occurence, 1);

                    ll &new_dp = dpB[len + 1][new_sl][k + new_occurence];

                    // maybe init

                    (new_dp += cur_dp) %= MOD;
                }
            }
        }
    }

//    cout << endl;
    for (int len = 0; len <= n; len++) {
        for (int sl = 0; sl < b.length(); sl++) {
            for (int k = 0; k <= n; k++) {
                printf("dpB[%d][%d][%d] ->\t %lld\n", len, sl, k, dpB[len][sl][k]);
            }
        }
    }

//    exit(0);

    /////////////////////////////////////
    ll res = 0;
    for (int l_len = 0; l_len <= n; l_len++) {
        int r_len = n - l_len;
//        cout << endl;
        db(l_len);
        db(r_len);

        for (int lk = 0; lk <= ka; lk++) {
            for (int rk = 0; rk <= kb; rk++) {
                ll total_left = 0;
                loop(sl, a.length())  total_left += dpA[l_len][sl][lk];

                ll total_right = 0;
                loop(sl, b.length()) total_right += dpB[r_len][sl][rk];

                total_left %= MOD;
                total_right %= MOD;
                ll add =  total_left * total_right;

                db(total_left);
                db(total_right);
                db(add);


                (res += total_left * total_right) %= MOD;
            }
        }
    }

    cout << res << endl;
    return 0;
}