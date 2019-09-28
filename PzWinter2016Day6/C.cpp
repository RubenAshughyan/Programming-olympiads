#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"


#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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



typedef complex<double> base;

int rev(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; ++i)
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    return res;
}

void fft(vector<base> &a, bool invert) {
    int n = (int) a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n) ++lg_n;

    for (int i = 0; i < n; ++i)
        if (i < rev(i, lg_n))
            swap(a[i], a[rev(i, lg_n)]);

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < (len >> 1); ++j) {
                base u = a[i + j], v = a[i + j + (len >> 1)] * w;
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}

vc<int> multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    size_t n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);

    fft(fa, false), fft(fb, false);
    for (size_t i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = int(fa[i].real() + 0.5);
    return res;
}

int solve(string &a1, string &a2) {
//    string a1, a2;
//    cin >> a1 >> a2;

    vc<int> sum;
    vc<vc<int> > m(1000), _m(1000), mm(1000);

    string str = "abcde";
    for (char c : str) {
        for (char ch : a1)
            m[c].pb(ch == c);
        for (char ch : a2)
            _m[c].pb(ch == c);

        reverse(_m[c].begin(), _m[c].end());
    }

    for (char c : str)
        multiply(m[c], _m[c], mm[c]);


    size_t mx = 0;
    for (char c : str) mx = max(mx, mm[c].size());

    for (char c : str)
        while (mm[c].size() < mx)
            mm[c].pb(0);

    for (int i = 0; i < mx; i++) {
        sum.pb(0);
        for (char c : str) {
            sum.back() += mm[c][i];
        }
    }

    int maxMatch = 0;
    int start = a2.size() - 1;
    int end = start + a1.size() - a2.size();

    for (int i = start; i <= end; i++)
        maxMatch = max(maxMatch, sum[i]);

    return a2.size() - maxMatch;
}

char buf[50*1000+55];

int main(){
    string a,b;

    scanf("%s",buf);
    a = buf;

    scanf("%s",buf);
    b = buf;

//    cin >> a >> b;

    for(char &c : a){
        c = tolower(c);
    }


    string new_a = a;


    vc<int> perm;
    loop(i,5) perm.push_back(i);

    int mx = 0;
    int mn = 0;

    do {
        new_a = a;

        for(char &c : new_a){
            c = perm[c-'a']+'a';
        }

        // matchings number
        new_a += new_a;
        int cur = solve(new_a, b);

        // vat
        cur = a.length() - cur;

//        db(cur);
        mx = max(cur, mx);
        mn = min(cur, mn);
    } while(next_permutation(all(perm)));

    printf("%d",(int)a.length() - mx);

}

/*

 BCDE
 cdab

 ABCD
cdab


 DABCCEC
abcedde

 ACBDCBABACD
babcdbadcab

*/