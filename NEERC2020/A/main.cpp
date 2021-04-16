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


const int N = 1000 * 1000 + 5;

int DEBUG = 0;

using namespace std;


int A,B;


vc<int> val(N,-1);
vc<int> l(N,0);
vc<int> r(N,0);

int GI = 1;

void vata(){
    cout << -1 << endl;
    exit(0);
}

int f(int a, int b){

    // No child if sum is 0
    if(a == 0 && b == 0) return 0;

    int v = GI++;

    //try put 2
    if(b%2==1){
        val[v] = 2;
        b--;
    } else if(a>0){
        val[v] = 1;
        a--;
    } else {
        val[v] = 2;
        b--;
    }


    if(a == 0 && b > 0 && b % 2 == 1) vata();

    l[v] = f(a-a/2, b/2);
    r[v] = f(a/2, b-b/2);
    return v;
}

int main() {
    cin >> A >> B;

    f(A,B);

    for(int i = 1; i < GI; i++){
        cout << val[i] << ' ' << l[i] << ' ' << r[i] << endl;
    }

    return 0;
}


/*


    // if only ones 1,1,1
    if(b == 0){

        l[v] = f(a/2,0);
        r[v] = f(a-a/2,0);
        return v;
    }

    // if only twos 2,2,2
    if(a == 0){
        if(b%2 == 0){
            vata();
        }

        l[v] = f(0,b/2);
        r[v] = f(0,b/2);
        return v;
    }


    int left2 = b/2;
    int right2 = b-b/2;

    int left1 = a/2;
    int right1 = a-a/2;
    // lava
    if(b%2 == 0){
        l[v] = f(left1,left2);
        r[v] = f(left2, right2);
        return v;
    }


 */



