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

const int N = 1000*1000*1000+5;

ll PR = 31;
ll MOD = 1000*1000*1000+7;
ll pw[N];

int n;
vc<vc<int>> words;

int encode(char c){
    int d;
    if(islower(c)) d = c - 'a';
    if(isupper(c)) d = c - 'A' + 26;
    if(isdigit(c)) d = c - '0' + 26 + 26;
    return d;
}

char decode[100*1000];

vc<int> getW(){
    string s;
    cin >> s;

    vc<int> res(s.length());
    loop(i,s.length()){
        char c = s[i];
        int d = encode(c);
        res[i] = d;
    }
    return res;
}

vc<ll> getHash(vc<int> w){
    vc<ll> h;

    ll pp = PR;
    loop(i,w.size()){
        h.push_back(pw[i]*w[i];

    }
}

int main(){



    for(char c = 'a';  c <= 'z'; c++){
        decode[encode(c)] = c;
    }
    for(char c = 'A';  c <= 'Z'; c++){
        decode[encode(c)] = c;
    }
    for(char c = '0';  c <= '9'; c++){
        decode[encode(c)] = c;
    }


    cin >> n;
    loop(i,n){
        words.push_back(getW());
    }
}