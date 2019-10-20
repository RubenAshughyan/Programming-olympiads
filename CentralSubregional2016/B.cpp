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

stack<int> h[3];
int n = 6;

int moves = 0;
bool solve(int from, int to, int cnt){
    if(h[0].size() == h[1].size() && h[1].size() == h[2].size()){
        bitset<32> b(moves);
        cout << b << endl;
//        cout << moves << endl;
        return true;
    }

    if(cnt > 0){
        int other = 3-from-to;

        if(solve(from, other, cnt-1)) return true;

//        printf("(move %d) %d -> %d\n", moves , from, to);
        moves++;

        h[to].push(h[from].top());
        h[from].pop();

        return solve(other, to, cnt-1);
    }
}



int main() {
    for(n = 3; ; n += 3){

        loop(i,3) while(h[i].size()) h[i].pop();

        loop(i, n) h[0].push(n - i - 1);

        moves = 0;
        solve(0, 2, n);
    }
    return 0;
}
/*
3
2
1<3
1>2

*/