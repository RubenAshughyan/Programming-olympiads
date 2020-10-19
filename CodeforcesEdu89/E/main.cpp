#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;


int CHECK = 0;

int n;

void pr(int x) {
    bitset<11> b(x);
    cout << b << endl;
}

vc<int> p;

int ask(int i, int j){

    if(CHECK){
        return p[i]|p[j];
    }

    cout << "? " << i+1 << ' ' << j+1 << endl;
    fflush(stdout);

    int res;
    cin >> res;
    return res;
}

int main() {




    if(!CHECK){
        cin >> n;
    } else {
        n = 2048;
        loop(i, n) p.PB(i);

        srand(time(NULL));
        shuffle(p.begin(), p.end(), std::default_random_engine(rand()%1000));
    }



    db(n);
    dbCont(p);


    vc<int> ors;

    map<int,vc<int>> orToInd;
    loop(xxx, 173) {
        int i, j;
        do {
            i = rand() % n;
            j = rand() % n;
        } while (i == j);

        int OR = ask(i,j);
        ors.PB(OR);
        orToInd[OR].PB(i);
        orToInd[OR].PB(j);
    }



    int O1 = -1,O2;

    int mx = 0;
    for (int o1: ors) {
        for (int o2: ors) {
            set<int> zero;
            loop(i, 11) {
                if (((o1 >> i) & 1) == 0) {
                    zero.insert(i);
                }
                if (((o2 >> i) & 1) == 0) {
                    zero.insert(i);
                }
            }

            db(zero.size());
            mx = max(mx, sz(zero));
            if(zero.size() == 11){
                O1 = o1;
                O2 = o2;
                break;
            }
        }
    }
    db(mx);

    db(O1);
    db(O2);
//    if(O1 == -1) assert(false);


    // hertov harcnel
    vc<int> ans(n,-1);

    loop(i,n){
        int withO1 = ask(i, i != orToInd[O1].front() ? orToInd[O1].front() : orToInd[O1][1]);

        int curValue = 0;
        loop(j,11){
            if( ((O1>>j)&1) == 0){
                if( (withO1>>j) & 1)
                    curValue ^= (1 << j);
            }
        }


        int withO2 = ask(i, i != orToInd[O2].front() ? orToInd[O2].front() : orToInd[O2][1]);
        loop(j,11){
            if( ((O2>>j)&1) == 0 && ((O1>>j)&1) != 0){
                if( (withO2>>j) & 1)
                    curValue ^= (1 << j);
            }
        }

        ans[i] = curValue;
    }


    cout << "! ";
    for(int e : ans) cout << e << ' ';
    cout << endl;


//    dbCont(ans);
//    dbCont(p);
//    assert(ans == p);


    return 0;
}


/*



 */



