#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define msk first
#define cnt second

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

const int N = 100000 + 5;
const ll INF = 1000000000000000000;
int n;
vector<int> input;

struct LinOp{
    ll a;
    ll b;
    ll l, r;
    LinOp *left=nullptr, *right=nullptr;
    LinOp(ll x=0, ll y=INF):a(x), b(y){}
    void add_line(LinOp& other){
        ll m = (l + r) / 2;
        bool lef = this->get_val(l) > other.get_val(l);
        bool mid = this->get_val(m) > other.get_val(m);
        if (mid){
            swap(this->a, other.a);
            swap(this->b, other.b);
        }

        if (r - l == 1)
            return;
        if (lef == mid){
            if (this->right != nullptr)
                this->right->add_line(other);
            else{
                this->right = new LinOp(other.a, other.b);
                this->right->l = m;
                this->right->r = r;
            }
        }
        else{
            if (this->left != nullptr)
                this->left->add_line(other);
            else{
                this->left = new LinOp(other.a, other.b);
                this->left->l = l;
                this->left->r = m;
            }
        }
    }
    ll get_min(ll x){
        ll m = (l + r) / 2;
        if (r - l == 1)
            return get_val(x);
        ll val=INF, sval = get_val(x);
        if (x < m && this->left!=nullptr)
            val = this->left->get_min(x);
        else if (x >= m && this->right!=nullptr)
            val = this->right->get_min(x);
        if (val < sval)
            return val;
        return sval;
    }
    ll get_val(ll x){
        return a * x + b;
    }
};

//inline ll min(ll a, ll b){
//	return a==-1?b:b==-1?a:a<b?a:b;
//}

ll solve(){
    vector<int> a(n);
    LinOp t;
    t.l = 0;
    t.r = (ll)10 * 1000 * 1000 * 1000;
    for(int i=0;i<n;++i){
        a[i] = input[i];
        if (i)
            a[i] += a[i-1];
    }
    if (a[n-1]<0){
        for(int i = 0;i<n;++i)
            a[i]*=-1;
    }
    if (a[n-1] == 0){
        cout << 0 <<endl;
        return 0;
    }
    LinOp op(0, 0);
    t.add_line(op);
    vector<ll> dp(n+1, -1);
    dp[0] = 0;
    for(int i=0;i<n;++i){
        ll x = a[i];
        //dp[i+1] = min_j (dp[j] + (a_j-a_i)^2)
        dp[i+1] = x * x + t.get_min(x);
        LinOp op(-2*x, x*x+dp[i+1]);
        t.add_line(op);
    }
    return (a[n-1]*a[n-1] - dp[n]) / 2;
}


void test_gen() {
    n = 10;
    input.resize(n);

    for(int i = 0; i < n; i++) {
        input[i] = rand()%20 - 10;
    }
}
//-----------------------------------------------------------
//--------------------Bruteforce solution--------------------
//-----------------------------------------------------------

ll brute_ans = 0;
vector<ll> groups;
vector<ll> best;

void dfs(int id) {
    if (id == n) {
        ll cur_ans = 0;
        for(int i = 0; i < groups.size(); i++) {
            for(int j = i + 1; j < groups.size(); j++) {
                cur_ans += groups[i] * groups[j];
            }
        }
        if (cur_ans > brute_ans) {
            brute_ans = max(cur_ans, brute_ans);
            best = groups;
        }
    }
    else {
        if (groups.size() == 0) {
            groups.push_back(input[id]);
            dfs(id + 1);
            groups.pop_back();
        }
        else {
            groups.back() += input[id];
            dfs(id + 1);
            groups.back() -= input[id];
            groups.push_back(input[id]);
            dfs(id + 1);
            groups.pop_back();
        }
    }
}

ll brute_solve() {
    brute_ans = 0;
    dfs(0);
    return brute_ans;
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------

int main() {
    while(true) {
        puts("Generating test...\n");
        test_gen();

        dbCont(input);
        puts("Running...\n");
        ll ans1 = solve(),
                ans2 = brute_solve();

        if (ans1 == ans2) {
            cout << "OK " << ans1 << endl;
        }
        else {
            cout << "WA for size " << n << endl;
            cout << "Expected " << ans2 << " but got " << ans1 << endl;
            for(int elem : input) {
                cout << elem << " ";
            }
            cout << "Groups are " << endl;
            for(int elem : best) {
                cout << elem << " ";
            }
            exit(0);
        }
    }

    system("pause");
    return 0;
}
/*
6
3 -2 1 -4 5 2
9

6
-3 2 -1 4 -5 -2
9


5
1 2 3 2 1
31

5
-1 -2 -3 -2 -1
31

5
10 2 -5 3 3
51

5
3 3 -5 2 10
51

11
1 1 2 3 -6 3 1 -2 2 -4 1
1

4
1 1 -2 2
1

4
2 -2 1 1
1

5
1 2 -3 2 1
3

1
1
0

2
5 5
25

2
5 -6
0

3
2 -1 3
4

6
1 2 -4 5 -4 4
4

6
-1 -2 4 -5 4 -4
4


*/