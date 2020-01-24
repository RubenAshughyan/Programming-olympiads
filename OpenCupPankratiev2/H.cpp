#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;

int findHead(vc<int> &v) {
    loop(i, 16) {
        if (v[i] && !(v[(i - 1 + 16) % 16])) {
            return i;
        }
    }
    return 0;
}

int findTail(vc<int> &v) {
    loop(i, 16) {
        if (v[i] && !(v[(i + 1) % 16])) {
            return (i+1)%16;
        }
    }
    return 0;
}


vc<string> ans;

string S = ".*";

string firstRow(vc<int> &v) {
    string s = "";
    for (int i = 0; i < 8; i++) {
        s.push_back(S[v[i]]);
        if (s.size() == 4) s += '|';
    }
    return s;
}

string secondRow(vc<int> &v) {
    string s = "";
    for (int i = 8; i < 16; i++) {
        s.push_back(S[v[i]]);
        if (s.size() == 4) s += '|';
    }
    return s;
}


void process(vc<int> v) {
//    dbCont(v);

    int count = 0;
    for (int e: v) count += e;


    // eat
    vc<int> eat = v;
    if (count >= 1) {

        eat[findHead(eat)] = 0;
        ans.push_back(firstRow(v)  + " eat " + firstRow(eat));
        ans.push_back(secondRow(v) + "     " + secondRow(eat));
        ans.push_back("---");
    }

    // buy
    vc<int> buy = v;
    if (count <= 5) {
        loop(iter, 10) {
            buy[findTail(buy)] = 1;
        }
        ans.push_back(firstRow(v)  + " buy " + firstRow(buy));
        ans.push_back(secondRow(v) + "     " + secondRow(buy));
        ans.push_back("---");
    }

}

void solve() {

    int total = (1 << 16);
    loop(msk, total - 1) {
        vc<int> v;
        loop(i, 16) {
            v.push_back((msk >> i) & 1);
        }

        process(v);
    }
}


int main() {
    string s;
    cin >> s;

//    freopen("out.txt", "w", stdout);


    solve();

    for(string s: ans){
        cout<<s<< endl;
    }

    return 0;
}
