#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

#define PB push_back
#define ll long long

const int DEBUG = 1;

using namespace std;

bool prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    cin >> n;


    int res = 0;
    for(int i = 2; i <= n; i++){
        if(n % i == 0 && prime(i)){
            res++;
        }
    }
    if(res == 3){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


//    main();
    return 0;
}