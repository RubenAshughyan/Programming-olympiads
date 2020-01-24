#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

#define PB push_back
#define ll long long

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;
const ll mod = 1000000007;

vector<ll> queries;
vector<ll> values;
vector<vector<ll> > m;
vector<ll> predicted;

ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    return binpow((a * a) % mod, n / 2) * ((n & 1) ? a : 1) % mod;
}

ll inverse(ll a) {
    return binpow(a, mod - 2);
}

void subtr(int from, int the, ll mult) {
    for (int k = 0; k < m[0].size(); k++)
        (m[from][k] += mod - m[the][k] * mult % mod) %= mod;
}

void gauss(int degree) {
    m.clear();
    for (int i = 0; i < queries.size(); i++) {
        m.PB(vector<ll>(degree + 2, 0));
        m[i].back() = values[i];
        m[i][degree] = 1;
        for (int j = degree - 1; j >= 0; j--)
            m[i][j] = m[i][j + 1] * queries[i] % mod;
    }

    for (int i = 0; i < m.size(); i++) {
        for (int j = i; j < m.size(); j++) {
            if (m[j][i]) {
                ll inv = inverse(m[j][i]);
                for (int k = 0; k < degree + 2; k++)
                    (m[j][k] *= inv) %= mod;
            }

            if (m[i][i] == 0 && m[j][i] != 0)
                swap(m[i], m[j]);
        }

        for (int j = 0; j < m.size(); j++) {
            if (i != j && m[j][i])
                subtr(j, i, m[j][i]);
        }
    }

    predicted.clear();
    for (int i = m.size() - 1; i >= 0; i--) {
        predicted.PB(m[i].back());
    }
}

bool check() {
    bool ok = true;
    for (int i = 0; i < queries.size(); i++) {
        ll val = 0, pw = 1;
        for (int j = 0; j < predicted.size(); j++) {
            (val += pw * predicted[j]) %= mod;
            (pw *= queries[i]) %= mod;
        }
        if (val != values[i])
            ok = false;
    }
    return ok;
}

void ask() {
    ll x = rand() % mod;

    while (find(queries.begin(), queries.end(), x) != queries.end()) {
        x = rand() % mod;
    }
    queries.PB(x);

    cout << "ask " << x << endl;
    fflush(stdout);

    cin >> x;

    values.PB(x);
}

int main() {
    srand(time(0));
    ask();
    for (int d = 0; d <= 10; d++) {
        gauss(d);
        ask();
        if (check()) {
            cout << "degree " << d << endl;
            fflush(stdout);
            return 0;
        }
    }
    return 0;
}