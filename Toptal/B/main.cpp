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
#define ind first
#define area second
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


const int N = 1000 * 1000 + 5;

int DEBUG = 1;
using namespace std;

vector<pair<char, int>> compress(string &S) {
    vector<pair<char, int>> result;
    int n = S.length();
    int c = 0;
    for (int i = 0; i < n; i++) {
        c++;
        if (i == n - 1 || S[i] != S[i - 1]) {
//            string count = c > 1 ? to_string(c) : "";
            result.push_back(make_pair(S[i], c));
            c = 0;
        }
    }
    return result;
}

int printLen(int x) {
    if (x <= 1) return 0;

    return to_string(x).length();
}


int eval(pair<char, int> p) {
    if (p.second == 0) return 0;

    return 1 + printLen(p.second);
}

int eval(vector<pair<char, int>> x) {
    int answer = 0;
    for (auto p : x) {
        answer += eval(p);
    }
    return answer;
}


vector<int> getPrefix(string S) {
    int n = S.length();

    vector<int> v(n);
    vector<int> counts;
    int curScore = 0;
    for (int i = 0; i < n; i++) {


        if (i == 0 || S[i] != S[i - 1]) {
            counts.push_back(1);
            curScore++;
        } else {
            curScore -= 1 + printLen(counts.back());
            counts.back()++;
            curScore += 1 + printLen(counts.back());
        }

        v[i] = curScore;
    }
    return v;
}

int solution(string &S, int K) {
    int n = S.length();

    if (K == 0) {
        vector<pair<char, int>> compressed = compress(S);
        return eval(compress(S));
    }
    if (K == n) {
        return 0;
    }

    // Calculate links
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && S[j + 1] == S[i]) {
            j++;
        }
        for (int k = i; k <= j; k++) {
            left[k] = i;
            right[k] = j;
        }
        i = j;
    }
    dbCont(left);
    dbCont(right);

    // Get pref suff
    vector<int> prefix = getPrefix(S);

    string reverseS = S;
    reverse(reverseS.begin(), reverseS.end());
    vector<int> suffix = getPrefix(S);
    reverse(suffix.begin(), suffix.end());

    dbCont(prefix);
    dbCont(suffix);

    // Brute position
    int answer = 1e9;
    for (int start = 0; start + K - 1 < n; start++) {
        int finish = start + K - 1;

        cout << "\n\n";
        db(start);
        db(finish);

        // Getting answers independent
        int curAnswer = 0;
        if (start - 1 >= 0) {
            curAnswer += left[start - 1] - 1 >= 0 ? prefix[left[start - 1] - 1] : 0;
        }
        if (finish + 1 < n) {
            curAnswer += right[finish + 1] + 1 < n ? suffix[right[finish + 1] + 1] : 0;
        }
        db(curAnswer);



        // Answers that may change
        pair<char, int> curRight = make_pair('#', 0);
        if (finish + 1 < n) {
            curRight = make_pair(
                    S[finish + 1],
                    right[finish + 1] - (finish + 1) + 1
                    );
        }
        pair<char, int> curLeft = make_pair('$', 0);
        if (start - 1 >= 0) {
            curLeft = make_pair(
                    S[start - 1],
                    (start - 1) - left[start - 1] + 1
                    );
        }

        db(curLeft);
        db(curRight);
        cout << "Maybe combine\n";
        if(curLeft.first == curRight.first){
            curLeft.second += curRight.second;
            curRight = make_pair('$', 0);
        }
        db(curLeft);
        db(curRight);
        curAnswer += eval(curLeft) + eval(curRight);

        db(curAnswer);

        answer = min(answer, curAnswer);
    }

    return answer;
}

int main() {

//    string S = "ABBBCCDDCCC";
//    string S = "AAAAAAAAAAABXXAAAAAAAAAA";
    string S = "ABCDDDEFG"; int K = 2;

    int ans = solution(S,K);

    db(ans);
    return 0;
}


/*




 */



