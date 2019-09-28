//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"


#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
#define dbl  long double
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

using namespace __gnu_pbds;

using OrderedTree = tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

const int N = 200 * 1000 + 5;

typedef bitset<N> B;

int n;
vc<int> a, b, c;

map<int, int> remap;
map<int, int> indexOf;


vc<int> getArray() {
    vc<int> x;
    loop(i, n) {
        int e;
        cin >> e;
        e--;
        x.push_back(e);
    }
    return x;
}

B bt;

int main() {
    // .order_of_key(int key)       -> returns order of key
    // .find_by_order(int index)    -> returns key for specified index
//    OrderedTree od;
//    od.insert(0);
//    od.insert(4);
//    od.insert(2);
//    od.insert(1);
//    od.insert(3);
//
//
//    cout << od.order_of_key(0) << endl;
//    cout << od.order_of_key(1) << endl;
//    cout << od.order_of_key(2) << endl;
//    cout << od.order_of_key(3) << endl;
//    cout << od.order_of_key(4) << endl;

    cin >> n;
    a = getArray();
    b = getArray();
    c = getArray();


    loop(i, n) {
        remap[a[i]] = i;
    }

    for (int &e : c) e = remap[e];
    for (int &e : b) e = remap[e];

    loop(i, n) indexOf[c[i]] = i;

    for(int e : c) bt[e] = 1;

    ll answer = 0;

    loop(i, n) {
        int ql = b[i];

        int greaters = (bt << (ql+1)).count();

        answer += greaters;

        bt[b[i]] = 0;
    }
    cout << answer << endl;

    return 0;
}
/*
3
3 2 1
1 2 3
1 2 3


 4
2 3 1 4
2 1 4 3
2 4 3 1

 4
 1 2 3 4
 1 2 3 4
 1 2 3 4

*/