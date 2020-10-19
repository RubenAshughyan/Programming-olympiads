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
#define ind first
#define area second
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

int solution(string &S) {
    int n = S.length();
    int sum = 0;
    for(char c : S) {
        if (c == 'a') {
            sum++;
        }
    }

    if (sum % 3 != 0){
        return 0;
    }

    if (sum == 0) {
        return (n-1)*(n-2)/2;
    }

    int prefixSum = 0;
    int prefixCount = 0;
    for(int i = 0; i < n; i++){
        prefixSum += S[i] == 'a';
        if (prefixSum == sum / 3) {
            prefixCount++;
        }
    }

    int suffixSum = 0;
    int suffixCount = 0;
    for(int i = n-1; i >= 0; i--){
        suffixSum += S[i] == 'a';
        if (suffixSum == sum / 3) {
            suffixCount++;
        }
    }
    // cout << prefixCount << ' ' << suffixCount';
    return 1ll*prefixCount* suffixCount;
}
int main() {

    string S = "abbaa";
    cout << solution(S);
    return 0;
}


/*




 */



