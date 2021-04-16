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


bool can(int val){
    db(val);

    vc<int> ok(n,0);
    vc<int> poses;
    loop(i,n){
        if(a[i] <= val){
            ok[i] = 1;
            poses.PB(i);
        }
    }

    if(poses.empty()) return false;

    dbCont(ok);
    dbCont(poses);
    db("start from poses[0]");
    int cnt = 0;
    int other = poses.front() == 0 ? 0 : 1;
    vc<int> used(n,0);
    for(int i = 0; i < poses.size(); i++){

        if(DEBUG) cout << "--------\n";
        db(i);

        int p = poses[i];
        // cant
        if(p - 1 >= 0  && used[p-1]){
            // chenq kara
            continue;
        }

        if(p != n-1) other++;
        used[p] = 1;
        cnt++;

        db(cnt);
        db(other);
        if(cnt >= k/2 && other >= k-k/2) return true;
        if(cnt >= k-k/2 && other >= k/2) return true;
    }




    if(poses.size() >= 2) {
        db("start from poses[1]");
        cnt = 0;
        other = 1;
        loop(i,n) used[i] = 0;
        for (int i = 1; i < poses.size(); i++) {
            int p = poses[i];
            // cant
            if (i - 1 >= 0 && used[p - 1]) {
                // chenq kara
                continue;
            }

            if (p != n - 1) other++;
            used[p] = 1;
            cnt++;

            if (cnt >= k / 2 && other >= k - k / 2) return true;
            if (cnt >= k - k / 2  && other >= k / 2) return true;
        }
    }

    return false;
}

int main() {
    scanf("%d%d",&n,&k);
    loop(i,n){
        scanf("%d",&a[i]);
    }


//    for(int c = 0; ; c++){
//        if(can(c)){
//            cout << c << endl;
//            return 0;
//        }
//    }
//    exit(0);

    int l = 0; int r = 1e9+6;
    while(l < r){
        int mid = (l+r)/2;
        if(can(mid)){
            r = mid;
        } else {
            l = mid+1;
        }
    }

    cout << l << endl;
    return 0;
}


/*




 */



