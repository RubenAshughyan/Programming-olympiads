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


int DEBUG = 1;

using namespace std;

const int N = 1000 * 1000 + 5;

int v[N];
int n,k;

int ans = 0;

void gen(set<int> &st){
    if(st.size() == k){
        vc<int> blockORS;

        for(int i: st){
            int OR = v[i];
            for(int j = (i+1)%n; !st.count(j); (j+=1)%= n){
                OR |= v[j];
            }
            blockORS.PB(OR);
        }

        int AND = blockORS[0];
        for(int e : blockORS) AND = AND&e;
        ans = max(ans,AND);

    } else {
        loop(i,n){
            if(st.empty() || i > *(--st.end())){
                st.insert(i);
                gen(st);
                st.erase(i);
            }
        }
    }
}

int main() {
    cin >> n >> k;

    loop(i,n){
        cin >> v[i];
    }

    set<int> st;
    gen(st);

    cout << ans << endl;

    return 0;
}


/*


 */



