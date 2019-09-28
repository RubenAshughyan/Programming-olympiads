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

const int N = 100 * 1005;

int n, m, k;


struct mard {
    int her;
    int mer;
    bool axjik;
    int dna;
    bool alive;

    mard() {
        dna = 0;
        her = mer = -1;
        alive = true;
    }
};

struct event {
    bool dead;
    bool female;
    int father;
    int mother;
    int body;
};

vector<event> events;

vc<mard> mardik;

vc<int> RANDS;

map<int, int> memo;

int getDna(int i) {
    if (memo.count(i)) return memo[i];

    if (mardik[i].dna != 0) {
        return mardik[i].dna;
    }


    if (mardik[i].her == -1) {
        return RANDS[i];
    }

    return memo[i] = getDna(mardik[i].mer);
}

int main() {
    loop(i, N) RANDS.push_back(-i - 1);

    freopen("eve.in", "r", stdin);
    freopen("eve.out", "w", stdout);
    cin >> n;
    mardik.resize(n);
    loop(i, n) {
        string g;
        cin >> g;
        mardik[i].axjik = g[0] == 'F';
    }

    // Events
    cin >> m;
    loop(i, m) {
        int mi;
        cin >> mi;

        // merav
        if (mi < 0) {
            mi = -mi;
            mi--;
            mardik[mi].alive = false;
        } else {
            int mj;
            string g;
            cin >> mj >> g;
            mi--;
            mj--;

            mard norMard;
            norMard.her = mi;
            norMard.mer = mj;
            norMard.axjik = g[0] == 'F';
            mardik.push_back(norMard);
        }
    }


    // read dnas
    cin >> k;
//    db(k);
    loop(i, k) {
        int mi, dnaVal;
        cin >> mi >> dnaVal;
        mi--;
        mardik[mi].dna = dnaVal;


        //set dna up
        if (mardik[mi].axjik || true) {
//            db(mi);
            int par = mardik[mi].mer;
            while (par != -1) {
                if (mardik[par].dna != 0) break;

//                db(par);

                mardik[par].dna = dnaVal;
                par = mardik[par].mer;
            }
        }
    }

    set<int> rest;
    set<int> normalTver;
    loop(i, mardik.size()) {
        if (mardik[i].alive) {
            if (getDna(i) > 0) {
                normalTver.insert(getDna(i));
            } else {
                rest.insert(getDna(i));
            }
        }
    }
//    cout << endl;
//
//    dbCont(normalTver);
//    dbCont(rest);

    if (normalTver.size() > 1) {
        cout << "NO" << endl;
        exit(0);
    }

    if (normalTver.size() == 1) {
        if (rest.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "POSSIBLY" << endl;
        }
        exit(0);
    }

    // normal.empty()

    if(rest.size() > 1){
        cout << "POSSIBLY" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}

/*
5
1 2
2 3
3 4
3 5

 */