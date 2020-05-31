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


string f(string s){
    string res = "";




    s += "#";

    int len = s.length();

    int cnt = 0;
    for(int i = 0; i < len; i++){
        cnt++;

        if(i > 0 && s[i] != s[i-1]){
            res += to_string(cnt-1);
            res += s[i-1];
            cnt=1;
        }
    }

    return res;

}


int main() {

    int n,k;
    cin >> n>> k;

    vc<int> v(n);


    multiset<int> ms;

    loop(i,n){
        cin >> v[i];
    }

    loop(i,n){
        ms.insert(v[i]);


        cout << *--ms.end() << ' ';

        if(i-k+1>=0){
            ms.erase(ms.find(v[i-k+1]));
        }
    }
    cout << endl;

    return 0;
}


/*





 */



