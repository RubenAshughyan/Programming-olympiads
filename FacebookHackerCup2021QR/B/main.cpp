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

int DEBUG = 1;
const int N = 1000 * 1000 + 5;
const int INF = 1e9;


using namespace std;

int n;
vc<string> v;

set<pii> st;

pii solve(bool flipped){

    map<int,int> mp;
    loop(i,n){
        int Xcnt = 0;
        int Ocnt = 0;

        int emptyPos = -1;
        loop(j,n){
            if(v[i][j] == 'X') Xcnt++;
            if(v[i][j] == 'O') Ocnt++;
            if(v[i][j] == '.') emptyPos=j;
        }
        if(Ocnt > 0) continue;


        if(Xcnt+1==n){
            if(!flipped){
                st.insert(MP(i,emptyPos));
            } else {
                st.insert(MP(emptyPos, i));

            }
        }


        mp[n-Xcnt]++;
    }

    if(mp.size() == 0) return MP(INF, 1234);

    return *mp.begin();
}

void test(int testIndex) {
    cin >> n;
    st.clear();
    v.resize(n);
    loop(i,n) cin >> v[i];

    pii p1 = solve(false);

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(v[i][j] ,v[j][i]);
        }
    }

    pii p2 = solve(true);

//    db(p1);
//    db(p2);

    int min_cnt;
    int ways;
    if(p1.first < p2.first){
        min_cnt = p1.first;
        ways = p1.second;
    } else if(p1.first > p2.first){
        min_cnt = p2.first;
        ways = p2.second;
    } else {
        min_cnt = p1.first;
        ways = p1.second + p2.second;
    }

    if(p1.first == 1 && p2.first == 1) ways = st.size();

    printf("Case #%d: ", testIndex);

    if(min_cnt < INF) {
        cout << min_cnt << ' ' << ways << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {

    int t;
    cin >> t;
    loop(i, t) test(i + 1);
    return 0;
}


/*




 */



