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


const int N = 400 * 1000 + 5;
const int INF = 1e9;

int DEBUG = 0;

using namespace std;

/////////////////////////////

int n, k;
vc<int> a, c;

int t[4 * N];
int lazy[4 * N];

void push(int v, int l, int r) {
    if (l != r) {
        lazy[2 * v + 1] += lazy[v];
        lazy[2 * v + 2] += lazy[v];
    }
    t[v] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        lazy[v] = 0;
        t[v] = c[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid + 1, r);

        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

int get_min(int v, int l, int r, int ql, int qr) {
    if (lazy[v] > 0) {
        push(v, l, r);
    }

    // total
    if (ql <= l && r <= qr) {
        return t[v];
    }

    // no overlap
    if (ql > r || l > qr) {
        return +INF;
    }

    int mid = (l + r) / 2;
    return min(
            get_min(2 * v + 1, l, mid, ql, qr),
            get_min(2 * v + 2, mid + 1, r, ql, qr)
    );
}

void update(int v, int l, int r, int ql, int qr, int add) {
    if (lazy[v] > 0) {
        push(v, l, r);
    }

    // total overlap
    if (ql <= l && r <= qr) {
        lazy[v] += add;
        push(v, l, r);
        return;
    }

    // no overlap
    if (ql > r || l > qr) {
        return;
    }


    int mid = (l + r) / 2;
    update(2 * v + 1, l, mid, ql, qr, add);
    update(2 * v + 2, mid + 1, r, ql, qr, add);

    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

/////////////////////////////



vc<int> ans[N];

stack<pii> st;
void rollback(){
    while(!st.empty()){
        int l = st.top().first;
        int r = st.top().second;

        update(0,0,k-1, l,r, +1);
        st.pop();
    }
}

void pt(){
    loop(i,k){
        cout << get_min(0,0,k-1, i,i) << ' ';
    }
    cout << endl;
}

int main() {

    scanf("%d%d", &n, &k);
    a.resize(n);
    c.resize(k);
    loop(i, n) scanf("%d", &a[i]);
    loop(i, k) scanf("%d", &c[i]);

    sort(all(a));
//    reverse(all(a));

    build(0, 0, k - 1);


    int GI = 0;

    int i = 0;
    while(i < n){
        db("");
        db(i);

        int cur = a[i];

        // porci
        st.push({0,cur-1});
        update(0,0,k-1, 0, cur-1, -1);

        // stugi
//        pt();
        int mn = get_min(0,0,k-1, 0,k-1);
        db(mn);
        if(mn < 0){
            // lav chi

            rollback();
            GI++;
        } else {
            ans[GI].PB(cur);
            i++;
        }
    }

    db(GI);

    cout << GI+1 << endl;
    loop(i,GI+1){
        printf("%d ", (int)ans[i].size());
        for(int e: ans[i] ) printf("%d ",e);
        printf("\n");
    }


    return 0;
}


/*


 6 10
5 8 1 10 8 7
6 6 6 6 6 6 6 6 6 6

 */



