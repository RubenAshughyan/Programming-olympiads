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


const int N = 5000 + 5;

int DEBUG = 0;

using namespace std;

int n,k;

vc<string> LAYOUTS = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

vc<int> g[N];
vc<string> layout;
vc<int> ans(N,-8);

int f(string a, string b){
    int ans = 0;
    loop(i,7){
        if(b[i] == '1'){
            if(a[i] == '0') ans++;
        } else {
            if(a[i] == '1') return -1;
        }
    }
    return ans;
}


vc<vc<int>> memo(N,vc<int> (N,-1));
bool can(int start_form, int value){
    if(value < 0) return false;
    if(start_form == n) return value == 0;

    if(memo[start_form][value] != -1){
        return memo[start_form][value];
    }


    bool ok = false;
    for(int cp = 0; cp <= 9; cp++){
        int add = g[start_form][cp];
        if(add != -1 && value - add >= 0){
            if(can(start_form+1,  value-add)){
                ok = true;
                break;
            }
        }
    }

    return memo[start_form][value] = ok;
}

int main() {
    cin >> n >> k;
    loop(i,n){
        string s;
        cin >> s;
        layout.PB(s);
    }

    // calc g
    for(int i = 0; i < n; i++){
        for(int wantd = 0; wantd <= 9; wantd++){
            int add = f(layout[i], LAYOUTS[wantd]);
            g[i].PB(add);
        }
    }



    // make
    bool ok = true;
    for(int i = 0; i < n; i++){
        bool done_smth = false;

        for(int wantd = 9; wantd >= 0; wantd--){
            int add = g[i][wantd];
            if(add == -1) continue;

            if (can(i+1, k-add)){
                k-=add;
                done_smth = true;
                ans[i] = wantd;
                break;
            }
        }

        if(!done_smth) {
            ok = false;
        }
    }

    if(!ok){
        cout << -1 << endl;
    } else {

        loop(i, n) {
            assert(0 <= ans[i] && ans[i] <= 9);
            cout << ans[i];
        }
        cout << endl;
    }




    return 0;
}


/*

2 5
0010010
0010010


3 8
0100001
1001001
1010011




 2 5
0010010
0010010


 */



