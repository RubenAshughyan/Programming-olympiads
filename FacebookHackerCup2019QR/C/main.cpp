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
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;


using namespace std;

const int N = 1000 + 5;
const int K = 1000 + 5;


int x;
string s;

bool is_action(int c){
    return
        c == '|' ||
        c == '^' ||
        c == '&';
}

int do_action(char act, int a, int b){
    if(act == '|') return a|b;
    if(act == '&') return a&b;
    if(act == '^') return a^b;
    assert(false);
}

int eval(int l, int r){
    if(l == r){
        if(s[l] == '1') return 1;
        if(s[l] == '0') return 0;
        if(s[l] == 'x') return x;
        if(s[l] == 'X') return !x;
        assert(false);
    }

    int bal = 0;
    int i=l+1;
    for(; i <= r; i++){
        if(s[i] == '(') bal++;
        else if(s[i] == ')') bal--;

        if(bal == 0 && is_action(s[i])) break;
    }

    return do_action(
            s[i],
            eval(l+1,i-1),
            eval(i+1,r-1)
            );
}

void test(int tt){
    cin >> s;

    int n = s.length();
    stack<int> st;


    x = 0;
    int a = eval(0,n-1);

    x = 1;
    int b = eval(0,n-1);

    int ans = a == b ? 0 : 1;
    printf("Case #%d: %d\n",tt,ans);
}

int main() {
    freopen("/home/ruben/Downloads/mr_x.txt","r",stdin);
    freopen("answers.txt","w",stdout);


    int t;
    cin >> t;
    loop(tt,t){
        test(tt+1);
    }

    return 0;
}
