#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

#define PB push_back
#define ll long long

const int DEBUG = 1;

using namespace std;


int main() {
    ll n,k;
    cin >> n >> k;

    cout << max(2ll, (ll)ceil(n*2.0/k)) << endl;
//    main();
    return 0;
}