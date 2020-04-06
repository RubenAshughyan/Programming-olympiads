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

int DEBUG = 1;

using namespace std;
void do_move(char m);
int indexOf(int a[], int element);
int lcm(int a, int b);
int gcd(int a, int b);
int st[54];
vector<vector<int>> cycle_u = {
        {36,38,44,42},
        {37,41,43,39},
        {0, 27,18, 9},
        {1, 28,19,10},
        {2, 29,20,11}
};
vector<vector<int>> cycle_r = {
        {2, 38,24,47},
        {5, 41,21,50},
        {8, 44,18,53},
        {9, 11,17,15},
        {10,14,16,12}
};
vector<vector<int>> cycle_b = {
        {18,20,26,24},
        {19,23,25,21},
        {36,33,53,11},
        {37,30,52,14},
        {38,27,51,17}
};
vector<vector<int>> cycle_l = {
        {0, 45,26,36},
        {3, 48,23,39},
        {6, 51,20,42},
        {27,29,35,33},
        {28,32,34,30}

};
vector<vector<int>> cycle_f = {
        {0, 2, 8, 6 },
        {1, 5, 7, 3 },
        {42,9, 47,35},
        {43,12,46,32},
        {44,15,45,29}
};
vector<vector<int>> cycle_d = {
        {53,51,45,47},
        {50,52,48,46},
        {6, 15,24,33},
        {7, 16,25,34},
        {8, 17,26,35}
};
int solve(string alg){
    for(int i = 0; i < 54; i++)
        st[i] = i;
    int l = alg.length();
    for(int a = 0; a < l; ++a){
        do_move(alg[a]);
    }
    int isUsed[54],next=-1,length_of_cycle=1,counter=1;
    for(int i = 0; i < 54; i++)
        isUsed[i] = 0;
    for(int n = 0; n < 54; ++n){
        if(isUsed[n] == 0){
            for(length_of_cycle = 0; next != n; length_of_cycle++){
                if(length_of_cycle == 0) next = n;
                next = indexOf(st, next);
                isUsed[next] = 1;
            }
            counter = lcm(length_of_cycle,counter);
        }
    }
    cout << counter << endl;
    return 0;
}
void do_move(char m){
    int dir = 1;
    vector<vector<int>> cycles ;
    switch(m){
        case 'U':
            cycles = cycle_u;
            break;
        case 'R':
            cycles = cycle_r;
            break;
        case 'L':
            cycles = cycle_l;
            break;
        case 'F':
            cycles = cycle_f;
            break;
        case 'B':
            cycles = cycle_b;
            break;
        case 'D':
            cycles = cycle_d;
            break;

        case 'u':
            dir = 0;
            cycles = cycle_u;
            break;
        case 'r':
            dir = 0;
            cycles = cycle_r;
            break;
        case 'l':
            dir = 0;
            cycles = cycle_l;
            break;
        case 'f':
            dir = 0;
            cycles = cycle_f;
            break;
        case 'b':
            dir = 0;
            cycles = cycle_b;
            break;
        case 'd':
            dir = 0;
            cycles = cycle_d;
            break;
    }

    if(dir == 1)
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 3; j++)
                swap(st[cycles[i][j]], st[cycles[i][j + 1]]);
    else
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 3; j++)
                swap(st[cycles[i][3 - j]], st[cycles[i][3 - j - 1]]);
}
int indexOf(int *set, int element){
    for(int i = 0; i < 54; ++i){
        if(set[i] == element)
            return i;
    }
    return -1;
}
int lcm(int a, int b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
int gcd(int a, int b){
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int main() {
    int t;
    cin >> t;
    loop(i,t){
        string s;
        cin >> s;

        string alg = "";
        loop(j,s.length()){
            char c = s[j];
            if(!isalpha(c)) continue;

            if(j+1 < s.length()) {
                if(s[j+1]=='2'){
                    alg.PB(c);
                    alg.PB(c);
                    continue;
                } else if (s[j+1] == '\''){
                    alg.PB(tolower(c));
                    continue;
                }
            }

            alg.PB(c);


        }
//        db(alg);

        solve(alg);
    }
}