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

string f(int x){
    string s = to_string(x);
    if(s.length() == 1) s = "0"+s;
    return s;
}

int main(){
    cin >> n;

    for(int h = 0; h < 24; h++){
        for(int m = 0; m < 60; m++){
            string H = f(h);
            string M = f(m);
            int sum = 0;

            for(char c : H+M){
                sum += used[c-'0'];
            }

            if(sum == n){
                cout << H << ":" << M << endl;
                return 0;
            }

        }
    }
    cout << "Impossible" << endl;

    return 0;
}