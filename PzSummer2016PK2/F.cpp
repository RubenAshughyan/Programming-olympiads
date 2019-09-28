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


const int N = 6;

string AB = "AB";
vc<vc<int>> x;
vc<vc<int>> m{
        {1, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1}
};

vc<vc<int>> get() {
    vc<vc<int>> x(N, vc<int>(N, 0));
    loop(i, N) {
        string s;
        cin >> s;
        loop(j, N) {
            x[i][j] = s[j] == 'B';
        }
    }
    return x;
}

bool good(int a, int b) {
    return __builtin_popcount(a ^ b) > 2;
}

//bool check() {
//    bool ok = true;
//
//    int nonNeg1 = 0;
//    loop(i, N) nonNeg1 += m[i] != -1;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = i + 1; j < N && m[j] != -1; j++) {
//            ok &= good(m[i], m[j]);
//        }
//    }
//
//
//    if (nonNeg1 == N && ok) {
//        vc<int> cols;
//        loop(j, N) {
//            int c = 0;
//            for (int i = 0; i < N; i++) {
//                if ((m[i] >> j) & 1) {
//                    c ^= (1 << i);
//                }
//            }
//            cols.push_back(c);
//        }
//
//        for (int i = 0; i < cols.size(); i++) {
//            for (int j = i + 1; j < cols.size(); j++) {
//                ok &= good(cols[i], cols[j]);
//            }
//        }
//    }
//
//    return ok;
//}
//
//void print() {
//    loop(j, N) {
//        loop(i, N) {
//            cout << ((m[i] >> j) & 1);
//        }
//        cout << endl;
//    }
//}
//
//void rec(int i) {
//    db(i);
//
//    if (i == N) {
//        cout << "GTAAAA" << endl;
//        print();
//        exit(0);
//        return;
//    }
//
//    for (int rowVal = 0; rowVal < (1 << N); rowVal++) {
//        m[i] = rowVal;
//        if (check()) {
//            rec(i + 1);
//        }
//    }
//}

int indexOf(vc<int> row) {
    loop(i, N)if (x[i] == row) return i;
    return -1;
}

int diff(vc<int> a, vc<int> b){
    int res = 0;
    loop(i,N)
        res += a[i] != b[i];
    return res;
}

bool tryRow(vc<int> &rows) {
    rows.resize(N);

    loop(i, N) {
        bool found = false;


        loop(j, N) {
            if(diff(m[i], x[j]) <= 1){
                rows[j] = i;
                found = true;
            }
        }

        if (!found) return false;
    }

    return true;
}

void tp(vc<vc<int>> &a) {
    loop(i, N) {
        loop(j, N) {
            if (i > j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

bool tryCols(vc<int> &cols) {
    cols.resize(N);

    tp(m);
    tp(x);

    bool ok = tryRow(cols);

    tp(m);
    tp(x);


    return ok;
}

void pr(vc<int> vec){
    for(int &e: vec) cout << e + 1 << ' ';
    cout << endl;
}

int main() {

    loop(i, N) {
        loop(j, N) {
            cout << AB[m[i][j]];
        }
        cout << endl;
    }
    fflush(stdin);

    while (1) {
        string s;
        cin >> s;
        if (s == "Request") {
            x = get();
        }
        if(s == "Accepted") exit(0);

        vc<int> rows;
        bool b1 = tryRow(rows);

        vc<int> cols;
        bool b2 = tryCols(cols);

        if(b1 && b2){
            cout << 0 << endl;
            pr(rows);
            pr(cols);
        } else if(b1){
            cout << 1 << endl;
            pr(rows);
        } else {
            cout << 2 << endl;
            pr(cols);
        }
    }

    return 0;
}
/*
111000
100110
011110
010101
101101
110011


110011
101101
101010
011110
011001
000111


Request
BABBAB
ABBBAA
ABBAAB
AAABBB
BBAABB
BABABA


*/