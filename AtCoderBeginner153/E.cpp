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
#define x first
#define y second
//
//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pdd pair<dbl,dbl>
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


int DEBUG = 1;

using namespace std;

const ll MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 7;


const int H = 10000 + 5;
vc<int> w,v;

int dp[H*2+123];

int main() {

    int h, n;
    cin >> h >> n;
    loop(i, n) {
        int weight, value;
        cin >> weight >> value;

        while(weight < 2*H){
            w.push_back(weight);
            v.push_back(value);

            weight *= 2;
            value *= 2;
        }
    }

    n = w.size();
//    db(n);

    loop(i,2*H) dp[i] = INF;
    dp[0] = 0;


    for(int i = 0; i < n; i++){
        for(int j = 2*H-1; j >= 0; j--){
            if(dp[j] != INF){
                if(j+w[i] < 2*H) {
                    dp[j+w[i]] = min(dp[j+w[i]], dp[j]+ v[i]);
                }
            }
        }
    }

    int ans = INF;
    for(int i = h; i < 2*H; i++){
        ans = min(ans, dp[i]);
    }


    cout << ans << endl;

    return 0;
}
