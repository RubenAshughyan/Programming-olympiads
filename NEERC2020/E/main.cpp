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
#define ll bigint
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


const int N = 1000 * 1000 + 5;

int DEBUG = 0;

using namespace std;

const int Dig = 10;

struct bigint {
    deque<int> num;
    int sign = 1;

    //constructor
    bigint() {
    }
    bigint(long long x) {
        num.clear();
        if (x < 0)
            sign = -1, x = -x;
        if (x == 0)
            num.push_back(x);
        while (x > 0) {
            num.push_back(x % Dig);
            x /= Dig;
        }
    }
    bigint(int x) {
        num.clear();
        if (x < 0)
            sign = -1, x = -x;
        if (x == 0)
            num.push_back(x);
        while (x > 0) {
            num.push_back(x % Dig);
            x /= Dig;
        }
    }
    bigint(const bigint &x) {
        sign = x.sign;
        num = x.num;
    }

    // change to int
    friend int BtoI(const bigint &x) {
        int res = 0, t = 1;
        for (int i = 0; i < x.num.size(); i++)
            res += t * x.num[i];
        return res;

    }

    //absolut
    friend bigint abs(const bigint &x) {
        bigint res = x;
        res.sign = 1;
        return res;
    }

    //clear 0
    void clr() {
        while (!num.empty() and !num.back())
            num.pop_back();
    }

    //normalize
    void normalize() {
        (*this).clr();
        int carry = 0;
        for (int i = 0; i < num.size(); i++) {
            int t = num[i] + carry;
            if (t < 0) {
                t += Dig;
                carry = -1;
                num[i] = t;
            }
            else {
                num[i] = t % Dig;
                carry = t / Dig;
            }
        }
        if (carry > 0)
            num.push_back(carry);
        if (carry < 0) {
            sign *= -1;
            num.push_back(-carry);
        }
        (*this).clr();
        if (num.empty())
            sign = 1;

    }

    //is 0
    bool isZero() {
        (*this).normalize();
        return num.empty();
    }

    //compare operators
    bool operator<(const bigint &x) const {
        if (sign != x.sign)
            return sign < x.sign;
        bool res = false, flag = false;
        if (num.size() != x.num.size()) {
            res = (num.size() < x.num.size());
            flag = true;
        }
        else {
            for (int i = num.size() - 1; i >= 0; i--)
                if (num[i] != x.num[i]) {
                    flag = true;
                    res = (num[i] < x.num[i]);
                    break;
                }
        }
        if (!flag)
            return false;
        if (sign == -1)
            return !res;
        return res;
    }
    bool operator==(const bigint &x) const {
        if (sign == x.sign and num.size() == x.num.size()) {
            bool res = true;
            for (int i = 0; i < num.size() and res; i++)
                if (num[i] != x.num[i])
                    res = false;
            return res;
        }
        else
            return false;
    }
    bool operator<=(const bigint &x) const {
        return (((*this) < x) or ((*this) == x));
    }
    bool operator>(const bigint &x) const {
        return (!((*this) <= x));
    }
    bool operator>=(const bigint &x) const {
        return (!((*this) < x));
    }
    bool operator!=(const bigint &x) const {
        return (!((*this) == x));
    }
    friend bigint max(const bigint &x, const bigint &y) {
        return (x > y? x: y);
    }
    friend bigint min(const bigint &x, const bigint &y) {
        return (x < y? x: y);
    }

    //math operators
    bigint operator+(const bigint &x) const {
        if (sign == x.sign) {
            bigint res;
            res.sign = sign;
            for (int i = 0; i < max(x.num.size(), num.size()); i++) {
                int t = (i >= num.size()? 0: num[i]) + (i >= x.num.size()? 0: x.num[i]);
                res.num.push_back(t);
            }
            res.normalize();
            return res;
        }
        if (sign == -1)
            return x - abs(*this);
        else
            return (*this) - abs(x);
    }
    bigint operator-(const bigint &x) const {
        if (sign == x.sign) {
            bigint res, a = abs(*this), b = abs(x);
            a.clr();
            b.clr();
            if (a == b) {
                res = 0;
                return res;
            }
            if (b < a) {
                for (int i = 0; i < a.num.size(); i++) {
                    int t = a.num[i] - (i >= b.num.size()? 0: b.num[i]);
                    res.num.push_back(t);
                }
                res.normalize();
            }
            else {
                for (int i = 0; i < b.num.size(); i++) {
                    int t = b.num[i] - (i >= a.num.size()? 0: a.num[i]);
                    res.num.push_back(t);
                }
                res.normalize();
                res.sign *= -1;
            }
            if (sign == -1)
                res.sign *= -1;
            return res;
        }
        if (sign == -1) {
            bigint res = abs(*this) + x;
            res.sign *= -1;
            return res;
        }
        else
            return (*this) + abs(x);
    }
    void operator+=(const bigint &x) {
        (*this) = (*this) + x;
    }
    void operator-=(const bigint &x) {
        (*this) = (*this) - x;
    }
    void operator++() {
        (*this) += 1;
    }
    bigint operator++(int) {
        bigint res;
        ++(*this);
        return res;
    }
    void operator--() {
        (*this) -= 1;
    }
    bigint operator--(int) {
        bigint res;
        --(*this);
        return res;
    }
    bigint operator*(const bigint &x) const {
        bigint res;
        bigint a = (*this), b = x;
        if (a.isZero() or b.isZero())
            return 0;
        a.clr();
        b.clr();
        for (int i = 0; i < b.num.size(); i++) {
            bigint t;
            for (int j = 1; j <= i; j++)
                t.num.push_back(0);
            for (int j = 0; j < a.num.size(); j++)
                t.num.push_back(a.num[j] * b.num[i]);
            t.normalize();
            res += t;
        }
        res.normalize();
        res.sign = a.sign * b.sign;
        return res;
    }
    void operator*=(const bigint &x) {
        (*this) = (*this) * x;
    }
    friend pair<bigint, bigint> dmod(const bigint &x, const bigint &y) {
        bigint res, a = abs(x), b = abs(y), carry;
        res.sign = y.sign * x.sign;
        a.clr();
        b.clr();
        if (b.isZero())
            return {-1, -1};
        if (a < b) {
            return {0, x};
        }
        int cnt = a.num.size() - 1;
        for (int i = a.num.size() - 1; carry < b; i--) {
            carry.num.push_front(a.num[i]);
            cnt = i - 1;
        }
        for (int i = 1; i <= 10; i++) {
            bigint t = b * i;
            if (t > carry) {
                res.num.push_front(i - 1);
                t -= b;
                carry -= t;
                break;
            }
        }
        for (int i = cnt; i >= 0; i--) {
            carry.num.push_front(a.num[i]);
            carry.normalize();
            if (carry >= b) {
                for (int j = 1; j <= 10; j++) {
                    bigint t = b * j;
                    if (t > carry) {
                        res.num.push_front(j - 1);
                        t -= b;
                        carry -= t;
                        break;
                    }
                }
            }
            else {
                res.num.push_front(0);
            }
        }
        res.normalize();
        if (res.sign == -1)
            carry = y - x;
        return {res, carry};

    }
    bigint operator/(const bigint &x) const {
        pair<bigint, bigint> res = dmod((*this), x);
        return res.first;
    }
    void operator/=(const bigint &x) {
        (*this) = (*this) / x;
    }
    bigint operator%(const bigint &x) const {
        pair<bigint, bigint> res = dmod((*this), x);
        return res.second;
    }
    void operator%=(const bigint &x) {
        (*this) = (*this) % x;
    }
    friend bigint pow(const bigint &x, const bigint &y) {
        bigint tmp = y;
        if (tmp.isZero())
            return 1;
        bigint res = 1, t = y, a = x;
        pair<bigint, bigint> dm;
        while (t > 0) {
            if ((t % 2) == 1)
                res = res * a;
            a *= a;
            t /= 2;
        }
        return res;
    }
    friend bigint gcd(bigint x, bigint y) {
        return (y.isZero()? x: gcd(y, x % y));
    }
    friend bigint lcm(const bigint &x, const bigint &y) {
        return (x * y) / gcd(x, y);
    }
    friend bigint sqrt(const bigint &x) {
        if (x.sign == -1)
            return -1;
        bigint carry, res, lef;
        deque<pair<int, int>> t;
        for (int i = 0; i < x.num.size(); i += 2) {
            if (i + 1 == x.num.size())
                t.push_front({x.num[i], 1});
            else
                t.push_front({x.num[i] + x.num[i + 1] * 10, 2});
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i].second == 1)
                carry.num.push_front(t[i].first);
            else
                carry.num.push_front(t[i].first / 10), carry.num.push_front(t[i].first % 10);
            carry.normalize();
            lef.num.push_front(0);
            for (int i = 1; i <= 10; i++) {
                lef.num[0] = i;
                bigint tmp = (lef) * i;
                if (tmp > carry) {
                    lef.num[0] = i - 1;
                    tmp = lef * (i - 1);
                    carry -= tmp;
                    lef += (i - 1);
                    res.num.push_front(i - 1);
                    break;
                }
            }
        }
        res.normalize();
        return res;
    }
    //base

    //string to bigint and bigint to string
    void toBig(string &s) {
        if (s[0] == '-') {
            sign = -1;
            s = s.substr(1);
        }
        else
            sign = 1;
        reverse(s.begin(), s.end());
        num.clear();
        for (int i = (s[0] == '-'); i < s.size(); i += Dig / 10) {
            string sp;
            for (int j = i; j < i + (Dig / 10); j++)
                sp += s[j];
            long long t = stol(sp);
            num.push_back(t);
        }
    }
    friend string to_string(const bigint &x) {
        string res;
        if (x.num.empty()) {
            res += '0';
            return res;
        }
        if (x.sign == -1)
            res += '-';
        for (int i = x.num.size() - 1; i >= 0; i--) {
            string t = to_string(x.num[i]);
            reverse(t.begin(), t.end());
            res += t;
        }
        return res;
    }
    //change base
    friend bigint change_base(const bigint &a, int x) {
        bigint res, t = a;
        while (t > 0) {
            res.num.push_back(BtoI(t % x));
            t /= x;
        }
        return res;
    }

    //cin and cout
    friend istream& operator>>(istream &stream, bigint &x) {
        string s;
        stream >> s;
        x.toBig(s);
        return stream;
    }
    friend ostream& operator<<(ostream &stream, bigint &x) {
        if (x.num.empty()) {
            stream << 0;
            return stream;
        }
        if (!x.num.empty() and x.sign == -1)
            stream << '-';
        stream << (x.num.empty() ? 0 : x.num.back());
        for (int i = (int) x.num.size() - 2; i >= 0; i--)
            stream  << x.num[i];
        return stream;
    }

};

bigint gcd(bigint a, bigint b, bigint &x, bigint &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    bigint x1, y1;
    bigint d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(bigint a, bigint b, bigint c, bigint &x0, bigint &y0, bigint &g) {
    g = gcd(a, b, x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    return true;
}

void shift_solution(bigint &x, bigint &y, bigint a, bigint b, bigint cnt) {

    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    db(a);
    db(b);
    db(c);

    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = +1;
    ll sign_b = +1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -1);
    ll rx1 = x;

    shift_solution(x, y, a, b, (y-miny) / (a));
    if (y < miny)
        shift_solution(x, y, a, b, -1);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, ( y-maxy) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);


    return (rx - lx) / b + 1;
}

//ll brute(ll d, ll b) {
//    ll ans = 0;
//    for (ll a = 1; a <= 1e7; a++) {
////            if(a*b + d*c == b*b){
//
//        if((b*b-a*b) % d == 0){
//            ll c = (b*b-a*b)/d;
//            if(c > 0) ans++;
//        }
//    }
//    return ans;
//}

ll solve(ll d, ll b){

    ll LIM = bigint((long long)1e18);//18
    ll ans = find_all_solutions(b, d, b * b, 1, LIM, 1, LIM );
    return ans;
}

//ll stress(){
//    while(1){
//        cout << endl;
//        ll b = rand()%5000+1;
//        ll d = rand()%5000+1;
//        cout << "b d " << b << ' ' << d << endl;
//
//        ll slv = solve(b,d);
//        ll brt = brute(b,d);
//        db(slv);
//        db(brt);
//
//        if(slv != brt){
//            cout << "HOOP" << endl;
//            exit(0);
//        }
//
//    }
//}

int main() {


//    cout << solve(74, 1659) << endl;
//    cout << brute(74, 1659) << endl;
//
//    stress();
//    exit(0);

    int t;
    cin >> t;
    loop(i, t) {
        ll b, d;
        cin >> b >> d;
        cout << to_string(solve(d,b)) << endl;

    }
    return 0;
}


/*


1
74 1659

 b d 74 1659

4
1000000 1
9 6
40 60
60 40



 */



