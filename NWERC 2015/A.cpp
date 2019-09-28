
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

int n, m;

int main() {
    cin >> n >> m;
    vector<pii > start_ends(n);
    for (int i = 0; i < n; ++i) {
        int s, a;
        cin >> s >> a;
        start_ends[i] = MP(s, s + a);
    }
    sort(all(start_ends));
    int count = 0;
    map<int, int> end_to_counts;

    for (int j = 0; j < start_ends.size(); ++j) {
        pii x = start_ends[j];
        vector<int> rm_ends;
        bool done = false;
        for (auto p : end_to_counts) {
            if (p.first > x.first) {
                end_to_counts[x.second]++;
                count++;
                done = true;
                break;
            } else {
                if (p.first + m >= x.first) {
                    end_to_counts[p.first]--;
                    end_to_counts[x.second]++;
                    if (end_to_counts[p.first] == 0) {
                        rm_ends.push_back(p.first);
                    }
                    done = true;
                    break;
                }
            }
        }
        if (!done) {
            count++;
            end_to_counts[x.second]++;
        }
        for (int i = 0; i < rm_ends.size(); ++i) {
            end_to_counts.erase(rm_ends[i]);
        }
    }
    cout << n - count;
    return 0;
}
/*
3 4
1 5
6 3
14 6

3 5
1 5
6 3
14 6

5 10
1 2
2 6
3 9
15 6
17 7
 */