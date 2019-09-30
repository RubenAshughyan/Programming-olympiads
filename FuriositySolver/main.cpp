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


const int N = 6;
const int INF = 1e9;

// Change this kernel
int center_i = 2;
int center_j = 2;
const int kern[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
};

bool ins(int i, int j) {
    return
            0 <= i && i < N &&
            0 <= j && j < N;
}


int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (a[sel][col] == 0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j) {
                    a[i][j] -= a[row][j] * c;
                    (a[i][j] += 1000) %= 2;
                }
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (sum != a[i][m])
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main() {
    vc<vc<int>> m = vc<vc<int>>(N*N, vc<int>(N*N));

    // make matrix
    loop(i, N) {
        loop(j, N) {

            loop(ki, N) {
                loop(kj, N) {
                    if (kern[ki][kj]) {
                        int ti = i + ki - center_i;
                        int tj = j + kj - center_j;
                        if (!ins(ti, tj)) continue;

                        m[i*6+j][ti*6+tj] = 1;
                    }
                }
            }
        }
    }
    loop(i,N*N){
        m[i].push_back(1);
    }


    // solve
    puts("solving");
    vc<int> ans(N*N,0);
    cout << gauss(m, ans) << endl;

    loop(i,N*N){
        if(i%N==0)cout << endl;
        cout << ans[i];
    }





    return 0;
}