#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>


#define ll  long long
#define vc  vector
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)

using namespace std;


using namespace std;

ll w,n;
vc<ll> v;

ll dist(ll a, ll b){
    if(a > b) swap(a,b);

    // a <= b
    ll d = b-a;
    return min(d,n-d);
}

ll f(ll target){
    ll sum = 0;
    for(ll e : v){
        sum += dist(e,target);
    }
    return sum;
}

void test(int testIndex){
    cin >> w >> n;
    v = vc<ll>(w);

    loop(i,w){
        cin >> v[i];

        v[i]%=n;
    }
    ll ans = 0;
    loop(XXX,2) {
        ll rnd = abs(1ll * rand()*rand());

        ans += rnd;
        ans %= n;
        loop(i,w){
            v[i]+=rnd;
            v[i] %= n;
        }


        ll l = 0, r = n - 1;

        while (l + 5 < r) {
            ll A1 = l + (r - l) / 3;
            ll A2 = r - (r - l) / 3;

            if (f(A1) < f(A2)) {
                r = A2;
            } else {
                l = A1;
            }
        }

        for (ll i = l; i <= r; i++) {
            if (f(ans) > f(i)) {
                ans = i;
            }
        }
    }

    printf("Case #%d: %lld\n", testIndex, f(ans));
}

int main() {
    int t;
    cin >> t;
    loop(I,t)  test(I+1);
    return 0;
}




