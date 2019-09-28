#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
#include <lastlog.h>

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


vc<int> p;
string s = "";
map<char,int> cnt;
const int n = 300 * 1000 + 5;

int m;

int trees[26][4 * n + 1];

int get(int t[], int v, int l, int r, int ql, int qr) {
//    db(v);
    // total overlap
    if (ql <= l && r <= qr) {
        return t[v];
    }

    // no overlap
    if (l > qr || ql > r) {
        return 0;
    }

    int mid = (l + r) / 2;
    return
            get(t,2 * v + 1, l, mid, ql, qr) +
            get(t,2 * v + 2, mid + 1, r, ql, qr);

}


void add1(int t[], int v, int l, int r, int pos) {
    if (l == r) {
        t[v]++;
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) add1(t,2 * v + 1, l, mid, pos);
        else add1(t,2 * v + 2, mid+1, r, pos);

        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}


void update(char c) {
//    db(c);

    s.push_back(c);
    cnt[c]++;
    if (s.length() == 1) {
        p.push_back(0);
    } else { ;
        int i = s.length() - 1;
        int pos = p[i - 1];
        while (pos > 0 && s[pos] != s[i]) pos = p[pos - 1];
        if (s[pos] == s[i]) pos++;
        p.push_back(pos);

    }


//    db(s.back());
    add1(trees[s.back()-'a'] ,0, 0, n - 1, p.back());
}

vector<int> prefix_function () {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int getBrute(int k){
    if(k == 1){
        int ans = 0;
        for(char c : s) ans += c==s[0];
        return ans;
    }

    vc<int> P = prefix_function();

    int ans = 0;

    loop(i, s.length()){
        if(s[i] == s[k-1]){
            ans += P[i] >= k;
        }
    }


    return ans+1;
}

int main() {


//    string t = "abca";
//    for(char c : t){
//        update(c);
//    }
//    dbCont(p);
//    exit(0);

    cin >> m;
//    m = 1000;

    int last = 0;
    loop(qqq, m) {
        string op;
        cin >> op;
        if (op == "add") {
            char c;
            cin >> c;

//            int asc = c-'a';
//            asc += last;
//            asc %= 26;
//            c = asc+'a';

//            cout << endl;
//            db(c);
            update(c);
//            db(s);
//            dbCont(p);
        } else {
            int k;
            cin >> k;

//            k = (k-1+last) % s.length() + 1;
//            cout << endl;
//            db(k);

//            if(k == 1){
//                last = cnt[s[0]];
//            } else {
//                last = 1+get(trees[s[k-1]-'a'], 0, 0, n - 1, k, n-1);
//            }

            last = getBrute(k);

            cout << last << endl;
        }
    }

    return 0;
}
/*
 *
16
add a
add b
add c
add a
get 1
add z
get 1
get 1
add y
add z
add a
add y
get 8
get 7
get 9
get 2



*/