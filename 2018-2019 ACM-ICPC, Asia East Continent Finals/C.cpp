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


const int N = 100 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<ll> primePowers;

bool isprime(int number) {
    for(int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

void precalc() {
    for(int i = 2; i <= sqrtl(1e9); i++)
        if (isprime(i))
            primePowers.emplace_back(i * i);
}

pll gcdEuclid(ll a, ll b) {
    if (a == 0) return {0, 1};
    pll tmp = gcdEuclid(b % a, a);
    return {tmp.second - (b / a) * tmp.first, tmp.first};
}

ll inverse(ll num, ll mod) {
    return gcdEuclid(num, mod).first;
}

pll chineseRemForTwo(pll a, pll b) {
    // x = a.first mod a.second
    // x = b.first mod b.second
    pll tmp = gcdEuclid(a.second, b.second);
    ll mod = a.second * b.second;
    return {((a.first * tmp.second * b.second + b.first * tmp.first * a.second) % mod + mod) % mod, mod};

}

pll chineseRem(vector<pll> data) {
    pll res = chineseRemForTwo(data[0], data[1]);
    for(int i = 2; i < data.size(); i++) {
        res = chineseRemForTwo(res, data[i]);
    }
    return res;
}

void solve(string s) {
//    string s = "";
//    loop(i, 10) {
//        string tmp;
//        cin >> tmp;
//        s += tmp;
//    }

    vector<int> primes = {2, 3, 5, 7};
    vector<pll> data;
    for(int p : primes) {
        int sum = 0;
        loop(start, p * p){
            bool ok = true;
            for(int i = start; i < s.length(); i += p * p) {
                ok &= s[i] == '0';
            }
            sum += ok;
            if (ok) {
                data.PB({p * p - start - 1, p * p});
            }
        }
        if (sum != 1) {
            cout << "aa" << endl;
            cout << "-1\n";
            return;
        }
    }
    pll result = chineseRem(data);
    // cout << result.first << " " << result.second << endl;

    int start = result.first, step = result.second;
    int lim = (1e9);
    while(start < lim) {
        cout << "Here " << start << endl;
        int lower = start, upper = start + 200;
        bool ok = true;
        for(int i = 4; i < primePowers.size(); i++) {
            int pp = primePowers[i];
            for(int num = (lower - 1) / pp * pp + pp; num < upper; num += pp)
                if (s[num - lower] == '1') {
                    ok = false;
                    break;
                }
            if (!ok)
                break;
        }
        if (ok) {
            cout << lower << endl;
            return;
        }
        start += step;
    }
    cout << -1 << endl;
}

bool check(int n) {
    for(int i = 2; i * i <= n; i++)
        if (n % (i * i) == 0)
            return true;
    return false;
}

void bruteforce() {
    string stt = "";
    for(int i = 0; i < 300000; i++) {
        stt += (check(i) ? '0' : '1');
    }
    srand(time(0));
    for(int i = 0; i < 1; i++) {
        int index = 207592;//rand() % 300000;
        cout << index << " ";
        solve(stt.substr(index + 1, 200));
    }
}

int main() {
    bruteforce();
    int t = 1;
//    cin >> t;
    while(t--) {
//        solve();
    }
    return 0;
}

/*
11101110011011101010
11100100111011101110
11100110001010101110
11001110111011001110
01101110101011101000
11101110111011100110
01100010111011001110
11101100101001101110
10101110010011001110
11101110011011101010


01010101010101010101
10101010101010101010
01010101010101010101
10101010101010101010
01010101010101010101
10101010101010101010
01010101010101010101
10101010101010101010
01010101010101010101
10101010101010101010

 */