//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second

//#define ld long double
#define dbl long double
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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int N = 1000005;
const int DEBUG = 1;

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i  <n; i++) {
        scanf("%d", &a[i]);
    }
    int i = 1;
    while(i < n && a[i] >= a[i - 1]) { i++; }
    if (i == n) {
        puts("1 1");
        return 0;
    }
    int j = i;
    i--;
    while(i > 0 && a[i - 1] == a[i]) i--;

    while(j < n && a[j] <= a[j - 1]) {
        j++;
    }
    if (j == n) {
        cout << i + 1 << " " << n << endl;
        return 0;
    }
    else {
        int k = j;
        while(k < n && a[k] >= a[k - 1]) { k++; }
        if (k == n && (i == 0 || a[i - 1] <= a[j - 1]) && a[i] <= a[j]) { cout << i + 1 << " " << j << endl;}
        else { puts("impossible"); }
    }

    return 0;
}/*
7
10 13 19 19 15 14 20

10
1 3 10 10 9 8 5 5 5 11

10
1 3 10 10 9 8 5 5 5 10

10
1 3 10 10 9 8 5 5 5 9
 */