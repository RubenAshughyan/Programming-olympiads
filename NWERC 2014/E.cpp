
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

#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

int n;
ld p;
ld s;
ld v;

ld A, B, C;

ld f(ld x){
    return A / x + B * pow(C, sqrt(2) * x);
}
ld calc_ans(ld A, ld B, ld C, ld x){
    return A + A / x + B * pow(C, x * sqrt(2));
}

ld tern(){
    ld l = 1e-8, r = 100, mid;

    loop(IER,10000){
        ld a = l + (r-l)/3.0;
        ld b = r - (r-l)/3.0;
        if(f(a) < f(b)){
            r = b;
        } else {
            l = a;
        }
    }
    return l;
}

int main() {
    cin >> n >> p >> s >> v;
    A = s;
    A /= v;

    B = n;
    (B /= p) /= 1e9;
    C = log(n) / log(2);
    ld x = tern();

    printf("%.10Lf %.10Lf\n", calc_ans(A, B, C, x), x);

    return 0;
}
/*
10 8.9 40075000 272.1

 47 4.2 1337102.4 256
 */