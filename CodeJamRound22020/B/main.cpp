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


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n,m;


void solve(){
    const int INF = 1000*1000*1000;
    int n, m;
    vector<int> p (n);

    bool ok = true;
    vector<int> cost (m), cost_ch (m), decrease (n, INF), decrease_id (n, -1);
    decrease[0] = 0;
    for (int i=0; i<m; ++i) {
        int a, b, c; // текущее ребро (a,b) с ценой c
        cost[i] = c;

        for (int j=0; j<=1; ++j) {
            int diff = p[b] - p[a] - c;
            if (diff > 0) {
                ok &= cost_ch[i] == 0 || cost_ch[i] == diff;
                cost_ch[i] = diff;
                decrease[b] = 0;
            }
            else
            if (-diff <= c && -diff < decrease[b]) {
                decrease[b] = -diff;
                decrease_id[b] = i;
            }
            swap (a, b);
        }
    }

    for (int i=0; i<n; ++i) {
        ok &= decrease[i] != INF;
        int r_id = decrease_id[i];
        if (r_id != -1) {
            ok &= cost_ch[r_id] == 0 || cost_ch[r_id] == -decrease[i];
            cost_ch[r_id] = -decrease[i];
        }
    }

    if (!ok)
        cout << "No solution";
    else {
        long long sum = 0;
        for (int i=0; i<m; ++i)  sum += abs (cost_ch[i]);
        cout << sum << '\n';
        for (int i=0; i<m; ++i)
            printf ("%d ", cost[i] + cost_ch[i]);
    }
}

void test(int testIndex){



    printf("Case #%d: %s\n", testIndex, res.c_str());
}

int main() {
    int t;
    cin >> t;
    loop(I,t) test(I+1);
    return 0;
}


/*


 4
2 3
-2 -3
3 0
-1 1



 */



