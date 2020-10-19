#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}

using namespace std;


const int N = 1e7 + 10;

int DEBUG = 1;
int lp[N + 1];

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}


vc<int> ans1, ans2;

pii brute(int n) {
    set<int> divs;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divs.insert(i);
//            divs.insert(n / i);
        }
    }

    for (int d1: divs) {
        for (int d2: divs) {
            if (d1 != d2 && gcd(d1 + d2, n) == 1) {
                return MP(d1, d2);
            }
        }
    }
    return MP(-1, -1);
}


map<int,pii> memo;

pii test(int n) {
    if(memo.count(n)) return memo[n];

    const int cn = n;

    vc<pii> cands = {{2,9}, {2,15}, {2,21}, {2,35} ,{3,10}};

    for(pii cand: cands){
        if(n%cand.first == 0 && n%cand.second == 0 &&  gcd(cand.first+cand.second, n ) == 1)
            return memo[cn] = cand;
    }
//
//
    set<int> primes;
    while (n != 1) {
        primes.insert(lp[n]);
        n /= lp[n];
    }
//
    vc<int> news;
    for (int e : primes) news.PB(n / e);
    for (int e : news) primes.insert(e);
//
//    dbCont(primes);
//


    for (int d1: primes) {
        for (int d2: primes) {
            if (d1 != d2 && gcd(d1 + d2, cn) == 1) {
                return memo[cn] = MP(d1,d2);
            }
        }
    }



    return memo[cn] = MP(-1,-1);
}


int main() {
    // precalc
    vector<int> pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
///////////////////////////////////////////////

//    set<pii> banses;
//    for (int i = 2; i <= 1000 * 10000; i++) {
//
//
//        pii bAns = brute(i);
//        pii sAns = test(i);
//
//
//
//
//        if(sAns.first == -1 && bAns.first != -1){
//            cout << i << endl;
//            db(bAns);
//            db(sAns);
//            banses.insert(bAns);
//            cout << "HOOP" << endl;
////            exit(0);
//        }
//
//    }
//    dbCont(banses);




    int t;
    scanf("%d", &t);
    loop(i, t){
        int n;
        scanf("%d",&n);

        pii x = test(n);
        ans1.PB(x.first);
        ans2.PB(x.second);
    }


    for (int e : ans1) printf("%d ", e);
    printf("\n");

    for (int e : ans2) printf("%d ", e);
    printf("\n");
    return 0;
}


/*


5
41234 2341451 3815735 843527 23452319
 */



