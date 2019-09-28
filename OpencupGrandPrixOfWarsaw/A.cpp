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

const int MOD = 998244353;
const int N = 250 * 1000 + 5;
const int M = 250 * 1000 + 5;

struct data {
    dbl sum;
    dbl lazy;
};

data t[4 * N];

int n, m;
dbl a[N];

data make_data(dbl val) {
    data d;
    d.sum = val;
    d.lazy = -1;
    return d;
}

data combine(data d1, data d2){
//    assert(d1.lazy >= 0 && d2.lazy >= 0);

    data d3;
    d3.sum = d1.sum+d2.sum;
    d3.lazy = -1;
    return d3;
}

void push(int v,int l, int r){
    if(l != r){
        t[2*v+1].lazy = t[v].lazy;
        t[2*v+2].lazy = t[v].lazy;
    }
    t[v].sum = (r-l+1) * t[v].lazy;
    t[v].lazy = -1;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = make_data(a[l]);
    } else {
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid + 1, r);

        t[v] = combine(t[2 * v + 1], t[2 * v + 2]);
    }
}

data get(int v, int l, int r, int ql, int qr) {
    // if lazy
    if (t[v].lazy >= 0) {
        push(v, l, r);
    }

    // total overlap
    if (ql <= l && r <= qr) {
        return t[v];
    }

    // no overlap
    if (l > qr || ql > r) {
        return make_data(0);
    }

    int mid = (l + r) / 2;
    return combine(
            get(2 * v + 1, l, mid, ql, qr),
            get(2 * v + 2, mid + 1, r, ql, qr)
    );
}


void update(int v, int l, int r, int ql, int qr, dbl newVal) {
    if (t[v].lazy >= 0) {
        push(v, l, r);
    }

    // total overlap
    if (ql <= l && r <= qr) {
        t[v].lazy = newVal;
        push(v,l,r);
        return;
    }

    // no overlap
    if (l > qr || ql > r) {
        return;
    }

    int mid = (l+r)/2;
    update(2*v+1, l, mid, ql,qr, newVal);
    update(2*v+2, mid+1, r,  ql,qr, newVal);
    t[v] = combine(t[2 * v + 1], t[2 * v + 2]);

}

void printTree(){
    loop(i,n){
        cout << get(0,0,n-1, i,i).sum << ' ';
    }
    cout << endl;

}

int main() {
//    freopen("in.txt","r",stdin);




    cin >> n >> m;
    loop(i, n) {
        cin >> a[i];
    }

    build(0, 0, n - 1);

//    update(0,0,n-1, 0,2,25);
//    printTree();
//    exit(0);

    loop(i, m) {
        string s;
        cin >> s;
        if (s == "get") {
            int j;
            cin >> j;
            j--;
            dbl ans =  get(0, 0, n - 1, j, j).sum;
            printf("%.15lf\n", ans);
        } else {
            int l, r;
            cin >> l >> r;

            l--, r--;

            dbl sum = get(0, 0, n - 1, l, r).sum;
            dbl avg = sum / (r - l + 1);
            update(0, 0, n - 1, l, r, avg);
        }

//        printTree();
    }

    return 0;
}
/*
 *

3 6
1 2 3
get 1
get 3
shuffle 1 2
shuffle 2 3
get 1
get 3



*/