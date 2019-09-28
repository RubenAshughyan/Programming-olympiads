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
const int DEBUG = 0;
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG){cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;


const int N = 200* 1000 + 5;

set<int> g[N];
int n;
int par[N];
int sz[N];
set<int> candidates;
void dfsSizes(int v, int p){
    candidates.insert(v);
    par[v] = p;
    sz[v] = 1;
    for(int to  : g[v]){
        if(to != par[v]){
            dfsSizes(to, v);
            sz[v] += sz[to];
        }
    }
}

int ASK = 0;
bool ask(vc<int> vs, int x) {
    ASK++;
//    if (ASK > 4 * ceil(log2(n))) {
//        assert(false);
//    }

    cout << "? " << vs.size() << " " << x+1;
    for (int e: vs) cout << " " << e+1;
    cout << endl;
    fflush(stdout);

    int res;
    cin >> res;
    return res == 1;
}

int findX(int root){
    vc<pii> diffAndVertex;
    for(int v : candidates){
        int diff = abs(sz[v] * 2 - (int)candidates.size());
        diffAndVertex.push_back({diff, v});
    }
    return min_element(all(diffAndVertex))->second;
}

void say(int a){
    cout << "! " << a+1 << endl;
    fflush(stdout);
    exit(0);
}

vc<int> subVector(vc<int> &v, int l, int r) {
    vc<int> res;
    for (int i = l; i <= r; i++) {
        res.push_back(v[i]);
    }
    return res;
}

int main(){
    cin >> n;
    loop(i,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    int root = 0;
    dfsSizes(root,-1);

    while(candidates.size() > 2){
        db(root+1);
        int x = findX(root);

        // kaxeci
        root = x;
        dfsSizes(root, -1);

        vc<int> children(all(g[x]));

        auto it = find(all(children), par[root]);
        if (it != children.end()) children.erase(it);


        bool isXCloser = ask(children, x);
        if (isXCloser){
            say(x);
        }

        int l = 0, r = children.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            vc<int> left_part = subVector(children, l, mid);
            vc<int> right_part = subVector(children, mid + 1, r);
            if (ask(left_part, x)) {
//                for (int i = 0; i < left_part.size(); ++i) {
//                    g[x].erase(left_part[i]);
//                }
                l = mid + 1;
            } else {
//                for (int i = 0; i < right_part.size(); ++i) {
//                    g[x].erase(right_part[i]);
//                }
                r = mid;
            }
        }
        assert(l == r);
        int child_containing = children[l];


        candidates.clear();
        g[child_containing].erase(x);

        root = child_containing;
        dfsSizes(root, -1);
    }


    if (candidates.size() == 1) {
        say(*candidates.begin());
    } else {
        vc<int> vectorCandidates(all(candidates));
        if (ask(subVector(vectorCandidates, 0, 0), vectorCandidates[1])) {
            say (vectorCandidates[1]);
        } else {
            say(vectorCandidates[0]);
        }
    }

    return 0;
}

/*
5
1 2
1 3
1 4
1 5

 7
1 2
2 3
3 4
4 5
3 6
6 7

*/