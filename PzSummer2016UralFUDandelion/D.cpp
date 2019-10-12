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
#define x first
#define y second

//#define ld long double
#define dbl long double
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

int R;

map<int, int> queries;
int COUNT = 0;

int query(int b) {
    if (queries.count(b)) {
        return queries[b];
    }
    COUNT++;
    assert(COUNT <= 60);
    cout << b << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "AC")
        exit(0);
    if (s == "WA") {
        int x;
        cin >> x;
        queries[b] = x;
        return x;
    }
    exit(0);
}

vector<int> nums;

void solve(int lastm = -1) {
    int sz = nums.size();
    if (sz < 5) {
        assert(sz != 0);
        for (int i = 0; i < sz; ++i) {
            query(nums[i]);
        }
        assert(false);
    }
    int l = nums.front();
    int r = nums.back();

    int m;
    if (lastm == -1) {
        m = nums[sz / 2];
        query(m);
    } else {
        m = lastm;
    }
    int li = sz / 4;
    int ri = 3 * sz / 4;
    int lm = nums[li];
    int rm = nums[ri];
    int ma = queries[m];
    int lma = query(lm);
    int rma = query(rm);
    vector<int> newnums;
    if (lma == rma) {
        for (int i = 0; i < sz; ++i) {
            if (i > li && i < ri)
                continue;
            newnums.push_back(nums[i]);
        }
        nums = newnums;
        solve(lm);
        return;
    }
    if (lma > rma) {
        if (lma == ma){
            for (int i = 0; i < sz; ++i) {
                if ((nums[i] < m && nums[i] > lm) || nums[i] > rm)
                    continue;
                newnums.push_back(nums[i]);
            }
            nums = newnums;
            solve(lm);
            return;
        }
        if (lma > ma) {
            for (int i = 0; i < sz; ++i) {
                if (nums[i] > m)
                    continue;
                newnums.push_back(nums[i]);
            }
            nums = newnums;
            solve(lm);
            return;
        } else {
            for (int i = 0; i < sz; ++i) {
                if (i < li || i > ri)
                    continue;
                newnums.push_back(nums[i]);
            }
            nums = newnums;
            solve(m);
        }
        return;
    }

    if (rma == ma){
        for (int i = 0; i < sz; ++i) {
            if ((nums[i] > m && nums[i] < rm) || nums[i] < lm)
                continue;
            newnums.push_back(nums[i]);
        }
        nums = newnums;
        solve(rm);
        return;
    }

    if (rma > ma) {
        for (int i = 0; i < sz; ++i) {
            if (nums[i] < m)
                continue;
            newnums.push_back(nums[i]);
        }
        nums = newnums;
        solve(rm);
    } else {
        for (int i = 0; i < sz; ++i) {
            if (i < li || i > ri)
                continue;
            newnums.push_back(nums[i]);
        }
        nums = newnums;
        solve(m);
    }
}

int main() {
    cin >> R;
    for (int i = 0; i <= R; ++i) {
        nums.push_back(i);
    }
    solve();
    return 0;
}
/*
4
0 0
1 0
0 1
1 1

3
0 0
0 10
5 8
*/