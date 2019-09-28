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

const int N = 1e9 + 1234;

int l, r;


int good(int x) {
    int c[] = {0, 0};
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            c[i % 2]++;
        }
    }
    return abs(c[0] - c[1]) <= 2;
}

int goodUpto(int x) {
    int res = 0;
    for (int i = 1; i <= x; i++) {
        res += good(i);
    }
    return res;
}

vc<int> sp;


int getPrimes(int L, int R) {
    vc<int> v(R - L + 1, 1);

    for (int smallP : sp) {
//        db(smallP);
        int start;
        if (L % smallP == 0) start = L;
        else start =  L - (L % smallP) + smallP;

        if (start == smallP) {
            start += smallP;
        }

        for (int i = start; i <= R; i += smallP) {
            v[i - L] = 0;
        }

    }
//
//    for(auto e : v){
//        cout << e << ' ';
//    }
//    cout << endl;
    return accumulate(all(v), 0ll);
}

void test(int tt) {
    cin >> l >> r;

    int ans = 0;

    ans += getPrimes(l, r);
//    db(getPrimes(l, r));

    if (l - 1 != 0)
        ans += ((r / 2 + 1) / 2 - 1) -
               (((l - 1) / 2 + 1) / 2 - 1);
    else {
        if (r != 1)
            ans += ((r / 2 + 1) / 2 - 1);
    }


    ans += getPrimes((l+3) / 4, r / 4);
//    db(getPrimes((l+3)/4, r/4));



    cout << "Case #" << tt << ": " << ans << endl;


}


//void stress() {
//
//    for (int i = 1; i <= 10000; i++) {
//        if (f(i) != goodUpto(i)) {
//            db(i);
//            db(f(i));
//            db(goodUpto(i));
//            exit(0);
//        } else {
//            cout << i << "ok------------" << endl;
//        }
//    }
//
//    exit(0);
//}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    for (int i = 2; i * i <= 1e9 + 123; i++) {
        if (isPrime(i)) {
            sp.push_back(i);
        }
    }

    int t;
    cin >> t;


    loop(i, t) {
        test(i + 1);
    }

    return 0;
}
