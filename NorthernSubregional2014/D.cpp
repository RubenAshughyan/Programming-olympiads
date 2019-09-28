#include<bits/stdc++.h>

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

int n;

int used[] = {6,2,5,5,4,5,6,3,7,6};

int sumOfDigits(int n){
    int s=0;
    for (int i = 0; i < 7; ++i) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    map<int, ll> mp;
    map<int, int> cmp;
    for (int i = 1; i < 500000; ++i) {
        int s = sumOfDigits(i);
        cmp[s]++;
        if (cmp[s] <= n)
            mp[s] += i;
    }
    ll mi = 100000000 * 5000;
    for (int j = 0; j < 100; ++j) {
        if (n > cmp[j])
            continue;
        mi = min(mp[j], mi);
    }
    cout << mi;
    return 0;
}