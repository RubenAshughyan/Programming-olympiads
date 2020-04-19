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

int DEBUG = 1;

using namespace std;

string SS = "NESW";


int MOD = 1000*1000*1000;

int indexOf(char c){
    loop(i,4) if(SS[i] == c) return i;
    assert(false);
}

int di[4] = {-1,0,1,0};
int dj[4] = {-0,1,0,-1};
string s;
pll get(int l, int r){
    if(l > r) return MP(0,0);

    if(isalpha(s[l])){
        int d = indexOf(s[l]);

        pll rest = get(l+1,r);
        (rest.first  += (di[d] + MOD))%=MOD;
        (rest.second += (dj[d] + MOD))%=MOD;
        return rest;
    }

    // 3
    if(isdigit(s[l])){
        int dig = s[l]-'0';

        int j = l+1; // (
        int bal = 1;
        while (1){
            j++;
            if(s[j] == '(') bal++;
            if(s[j] == ')') bal--;
            if(bal == 0) break;
        }


        pll rest = get(l+2, j-1);
        (rest.first *= dig) %= MOD;
        (rest.second *= dig) %= MOD;

        pll rest2 = get(j+1,r);
        (rest.first += rest2.first) %= MOD;
        (rest.second += rest2.second) %= MOD;

        return rest;
    }

    assert(false);
}

void test(int testIndex){
    cin >> s;

    pll p = get(0, s.length()-1);

    printf("Case #%d: %lld %lld\n", testIndex, p.second+1, p.first+1);
}

int main() {
    int t;
    cin >> t;
    loop(I,t)  test(I+1);
    return 0;
}


/*

4
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))



 */



