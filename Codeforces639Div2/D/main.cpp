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


const int N = 1000 + 5;

int DEBUG = 0;

using namespace std;

int n, m;
char x[N][N];
int used[N][N];


int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

bool ins(int i, int j) {
    return
            0 <= i && i < n &&
            0 <= j && j < m;
}

void dfs(int i, int j){

    used[i][j] = 1;
    loop(d,4){
        int ni = i+di[d];
        int nj = j+dj[d];
        if(ins(ni,nj) && !used[ni][nj] && x[ni][nj] == '#'){
            dfs(ni,nj);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    loop(i, n) {
        scanf("%s", x[i]);
    }

    int cHash = 0;
    loop(i,n) loop(j,m) cHash+= x[i][j] == '#';
    if(cHash == 0){
        cout << 0 << endl;
        return 0;
    }

    loop(i, n) {
        vc<int> pos;
        loop(j, m) {
            if (x[i][j] == '#') pos.PB(i);
        }

        if(pos.empty()){
            cout << -1 << endl;
            return 0;
        }
        for (int k = 0; k + 1 < pos.size(); k++) {
            if (pos[k + 1] - pos[k] > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    loop(j, m) {
        vc<int> pos;
        loop(i, n) {
            if (x[i][j] == '#') pos.PB(i);
        }

        if(pos.empty()){
            cout << -1 << endl;
            return 0;
        }
        for (int k = 0; k + 1 < pos.size(); k++) {
            if (pos[k + 1] - pos[k] > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int ans = 0;
    loop(i,n){
        loop(j,m){
            if(x[i][j] == '#' && !used[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }

    cout << ans << endl;


    return 0;
}


/*

 */



