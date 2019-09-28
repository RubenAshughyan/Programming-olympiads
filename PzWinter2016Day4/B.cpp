#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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


const int N = 2000 + 5;
vc<int> g[N];
int n;
char s[N];

const int INF = 1e8;

ll answer = 0;

int q[N];
int dist[N][N];
bool calced[N][N];

void bfs(int start) {
    loop(i,N) dist[start][i] = n;

    int qh = 0;
    int qt = 0;
    q[qt++] = start;

    dist[start][start] = 0;
    int from;
    while (qh < qt) {
        from = q[qh++];
        for (int to : g[from]) {
            if (dist[start][to] == n) {
                dist[start][to] = dist[start][from] + 1;
                q[qt++]=to;
            }
        }
    }

//    db(start);
//    dbCont(dist);
}

int main() {
    scanf("%d", &n);
    loop(i, n) {
        scanf("%s", s);
        loop(j, n) {
            if (s[j] == '1') {
                g[i].push_back(j);
            }
        }
    }


    loop(i, n) {
        bfs(i);
    }
    loop(i, n)
        loop(j, n)
            answer += dist[i][j];
    printf("%lld\n", answer);

    return 0;
}

/*
3
010
001
100


 2
10
01


 */