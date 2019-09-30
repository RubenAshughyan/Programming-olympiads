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

int n, k;

int main() {
    cin >> n >> k;
    if ((n - 1) % k != 0) {
        cout << "No" << endl;
    }
    else {
        vector<string> numbers;
        for(int i = 1; i <= n; i++) {
            numbers.PB(to_string(i));
        }
        sort(all(numbers));
        queue<int> q;
        q.push(1);
        int next = 2;
        cout << "Yes" << endl;
        while(next <= n) {
            int cur = q.front();
            q.pop();

            for(int i = 0; i < k; i++) {
                q.push(next);
                cout << numbers[cur - 1] << " " << numbers[next - 1] << " ";
                next++;
            }
        }
        cout << endl;
    }
    return 0;
}