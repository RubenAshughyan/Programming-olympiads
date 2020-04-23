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

int n,k;
int a[N];
int ps[N];

int isPeak(int i){
    if(i == 1 && i == n) return 0;

    return a[i] > max(a[i-1], a[i+1]);
}

void test(){
    scanf("%d",&n);
    vc<int> p(n);
    vc<int> pos(n);
    loop(i,n){
        scanf("%d",&p[i]);
        p[i]--;

        pos[p[i]] = i;
    }

    bool ok = true;
    vc<int> used(n,0);

    int r = n-1;
    for(int i = 0; i < n; i++){
        int j = pos[i];

        if(used[j]) continue;


        while(j+1 <= r && p[j+1] == p[j]+1) {
            j++;
            used[j] = 1;
        }

        if(j == r) {
            // lava
            r = pos[i]-1;
        } else {
            ok = false;
            break;
        }
    }

    string ans = ok ? "Yes" : "No";
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*

 */



