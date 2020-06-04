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
#include <random>

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

int lcs(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    vc<vc<int>> L(m + 1, vc<int> (n + 1,0));

    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int solveLcs(string a, string b){
    int len = a.length();
//    int l = lcs(a,b);
//
//
//    return max(l, (int)a.length() - l);

    // rem first letters;
    while(a.size() && a[0] == b[0]) {
        a = a.substr(1);
        b = b.substr(1);
    }


    int i = 0;
    while(b[i] != a[0]) i++;

    b = b.substr(i);


    //
    while(b.size() != 1 && a.size() && a.back() != b.back()){
        a.pop_back();
    }

    if(a == "") return len-1;

    int l = lcs(a, b);
    return (int)a.length() - l;
}

vc<string> neigs(string a){
    int len = a.length();

    vc<string> ans;
    loop(i,len){
        for(int j = i+1; j < len; j++){
            string na = a.substr(0,i) + a[j] + a.substr(i, j-i) + a.substr(j+1);
            ans.PB(na);
        }
    }
    return ans;
}




int solveBrute(string a, string b){
    map<string, int> d;
    d[a] = 0;

    queue<string> q;
    q.push(a);

    while(!q.empty()){
        string from = q.front();
//        db(from);
        if(from == b) break;
        q.pop();

        for(string to: neigs(from)){
            if(!d.count(to)) {
                q.push(to);
                d[to] = d[from]+1;
            }
        }
    }

    return d[b];
}

void test() {
    string a,b;
    int n;
    cin >> n;

    cin >> a >> b;
    string aa = a;
    string bb = b;

    sort(all(aa));
    sort(all(bb));

    if(aa != bb){
        cout << - 1 << endl;
        return;
    }

    int l = lcs(a,b);

    db(solveLcs(a,b));
    db(solveBrute(a,b));

//    cout << n- l << endl;

}

void stress(){
    cout << "_____________" << endl;

    int len = 5;
    string a = "";
    for(int i = 0;  i < len; i++){
        a.PB('a'+random()%26);
    }


    string b = a;
    loop(i,6*len){
        int i1 = random()%len;
        int i2 = random()%len;
        swap(b[i1], b[i2]);
    }



    db(a);
    db(b);
    int ans1 = solveLcs(a,b);
    int ans2 = solveBrute(a,b);
    cout << ans1 << ' ' << ans2 << endl;

    if(ans1 != ans2){
        cout << "!!!!!!!!!!!!!!!!" << endl;

        exit(0);
    }


}



int main() {
    loop(i,1000000) {
        stress();
    }


    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*

 1
 3
abc
cab


 */



