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


const int N = 1000*1000+7;
const int MOD = 1000*1000*1000 + 7;

int n;
int p[N];

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&p[i]);
    }

    dbl startTime = clock();


    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {

            for(int c=1; c <=n ; c++){


                dbl passed = (clock()-startTime)/CLOCKS_PER_SEC;
                if(passed >= 1.8) {
                    cout<< "Nein" << endl;
                    return 0;
                }

                int d = (a+b-c + 5*n) % n;
                if(d == 0) d = n;

                if( (a == c && b == d) || (a == d && b == c)){
                    continue;
                }

                if( (p[a] + p[b])%n == (p[c] + p[d])%n ){
                    cout << "Ja" << endl;
                    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
                    return 0;
                }
            }

        }
    }
    cout<< "Nein" << endl;


    return 0;
}
