#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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

const int DEBUG = 1;

int get_int() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    return a * 100 + b;
}

void print_int(int a) {
    string s = to_string(a % 100);
    if (s.size() == 1)
        s = "0" + s;
    cout << a / 100 << "." << s << endl;
}

int main() {
    multiset<int> st;
    for (int i = 0; i < 4; ++i) {
        st.insert(get_int());
    }
    int t = get_int();
    vector<int> v(all(st));
    if (v[1] + v[2] + v[3] <= t * 3){
        cout << "infinite" << endl;
        return 0;
    }
    if (v[0] + v[1] + v[2] > t * 3){
        cout << "impossible" << endl;
        return 0;
    }
    print_int(t * 3 - v[1] - v[2]);
    return 0;
}