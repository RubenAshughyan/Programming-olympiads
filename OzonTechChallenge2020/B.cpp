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

int n;
int b[N];

int d[N];


int main() {
    string s;
    cin >> s;
    vector<vector<int>> pref(s.size());
    vector<vector<int>> suf(s.size());
    for(int i = 0; i < s.size(); ++i)
    {
        if(i != 0)
            pref[i] = pref[i - 1];
        if(s[i] == '(')
            pref[i].push_back(i + 1);
    }
    for(int i = s.size() - 1; i >= 0; --i)
    {
        if(i != s.size() - 1)
            suf[i] = suf[i + 1];
        if(s[i] == ')')
            suf[i].push_back(i + 1);
    }
    int ind = -1;
    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(pref[i].size() == suf[i + 1].size()) {
            ind = i;
            break;
        }
    }

    if(ind == -1 || pref[ind].size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    cout << pref[ind].size() * 2 << endl;
    for(int i = 0 ; i < pref[ind].size(); ++i)
        cout << pref[ind][i] << " ";
    for(int i = suf[ind + 1].size() - 1; i >= 0; --i)
        cout << suf[ind + 1][i] << " ";
    cout << endl;
    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

 5
1 1 1 1 1
1 1 1 1 1



 */



