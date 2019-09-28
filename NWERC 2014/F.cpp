
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
int perc;


vc<pll> v;

ll det(pll a, pll b, pll c){
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

int ITER = 300;

int main(){
    cin >> n >> perc;
    loop(i,n){
        pll p;
        scanf("%lld %lld", &p.first, &p.second);
        v.push_back(p);
    }

    if(n <= 2){
        cout << "possible" << endl;
        return 0;
    }

    int k = n*perc;
    if(k % 100 == 0) k /= 100;
    else k = k/100 + 1;

    loop(xxx,ITER){
        random_shuffle(all(v));

        int same = 2;
        for(int i = 2; i < v.size(); i++){
            same += det(v[0], v[1], v[i]) == 0;
        }


        if(same >= k) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}

/*

5
55
0 0
10 10
10 0
0 10
3 3

 5
45
0 0
10 10
10 0
0 10
3 4


 3 60
 0 0
 1 1
 2 3

*/