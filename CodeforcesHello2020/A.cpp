#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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


int DEBUG = 0;

using namespace std;


int solve(vc<int> a) {
    int n = a.size();

    vc<int> cnt = {0, 0};

    for (int i = 1; i <= n; i++) cnt[i % 2]++;
    loop(i, n) {
        if (a[i] != 0) {
            cnt[a[i] % 2]--;
        }
    }

    vc<int> v[2];
    v[0].resize(n, 0);
    v[1].resize(n, 0);

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != 0 && a[i + 1] != 0 && a[i] % 2 != a[i + 1] % 2)ans++;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            int j = i;
            while (j + 1 < n && a[j + 1] == 0) j++;

            if (a[i - 1] % 2 == a[j + 1] % 2) {
                v[a[i - 1] % 2][j - i + 1]++;
                ans += 2;
            } else {
                ans++;
            }

            i = j;
        }
    }

    loop(i, 2) {
        for(int j = 0; j < n; j++){
            while(v[i][j] && j <= cnt[i]){
                ans-=2;
                v[i][j]--;
                cnt[i] -= j;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vc<int> a(n);
    vc<int> cnt = {0, 0};
    for (int i = 1; i <= n; i++) cnt[i % 2]++;
    loop(i, n) {
        cin >> a[i];
        if (a[i] != 0) {
            cnt[a[i] % 2]--;
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1e9;
    loop(f, 2) {
        loop(l, 2) {
            auto na = a;
            auto c = cnt;
            if (na[0] == 0 && c[f]) {
                na[0] = f + 2;
                c[f]--;
            }
            if (na[n - 1] == 0 && c[l]) {
                na[n - 1] = l + 2;
                c[l]--;
            }

            int curAns = solve(na);
            ans = min(ans, curAns);
        }
    }

    cout << ans << endl;
    return 0;
}

/*

7
1 0 0 5 0 0 2

 */