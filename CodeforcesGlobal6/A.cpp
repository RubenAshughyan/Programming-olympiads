#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x)  (int)(x).size()

template<typename T>
using trp = tuple<T, T, T>;
using ll = long long;
using ld = long double;
const int N = 100 * 1000 + 10;
const ll mod = 998244353;

bool check(string s) {
    sort(s.begin(), s.end());
    if (s[0] != '0') {
        return false;
    }
    bool ev = false;
    int sum = 0;
    for (int i = 1; i < s.size(); i++) {
        int d = s[i] - '0';
        if (d % 2 == 0) {
            ev = true;
        }
        sum += d;
    }
    return ev && (sum % 3 == 0);
}

string s;


void input() {
    cin >> s;
}

void solve() {
    cout << (check(s) ? "red" : "cyan") << endl;
}

void prec() {

}

int main() {
    int testcases = 1;
    prec();
    scanf("%d", &testcases);
    for (int testId = 1; testId <= testcases; testId++) {
        input();
        solve();
    }
    return 0;
}