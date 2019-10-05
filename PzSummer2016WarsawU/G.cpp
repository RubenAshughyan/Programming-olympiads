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


const int N = 1000*1000+7;
const int MOD = 1000*1000*1000 + 7;

struct treap {
    treap *l, *r, *p;
    int counts[30];
    int x, y, size;

    treap(int _x) {
        y = rand();
        x = _x;
        size = 1;
        l = p = r = nullptr;
        for(int i = 0; i < 30; ++i)
            counts[i] = 0;
    }

    static int sizeOf(treap * node) {
        return node ? node->size : 0;
    }

    void update() {
        this->size = sizeOf(this->l) + sizeOf(this->r) + 1;
        for(int i = 0; i < 30; ++i)
            this->counts[i] = (l ? l->counts[i] : 0) + (r ? r->counts[i] : 0);
    }

    static long long xored_sum(treap* root, int xor_value) {
        if (root == nullptr)    return 0;
        long long sz = sizeOf(root), result = 0;
        for(int i = 0; i < 30; i++) {
            if ((xor_value) & (1 << i))
                result += root->counts[i] * (1 << i);
            else
                result += (sz - root->counts[i]) * (1 << i);
        }
        return result;
    }

    static treap * merge(treap* a, treap* b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;

        if (a->y > b->y) {
            treap * tmp = merge(a, b->l);
            tmp->p = b;
            b->l = tmp;
            b->update();
            return b;
        }
        else {
            treap * tmp = merge(a->r, b);
            tmp->p = a;
            a->r = tmp;
            a->update();
            return a;
        }
    }

    static pair<treap*, treap*> splitByRank(treap* root, int leftSize) {
        if (root == nullptr)    return {nullptr, nullptr};
        if (sizeOf(root->l) >= leftSize) {
            auto tmp = splitByRank(root->l, leftSize);
            if (tmp.second != nullptr)  tmp.second->p = root;
            root->r = tmp.second;
            if (tmp.first != nullptr)   tmp.first->p = nullptr;
            root->update();
            return {tmp.first, root};
        }
        else {
            auto tmp = splitByRank(root->r, leftSize - sizeOf(root->l) - 1);
            if (tmp.first != nullptr)  tmp.first->p = root;
            root->l = tmp.first;
            if (tmp.second != nullptr)   tmp.second->p = nullptr;
            root->update();
            return {root, tmp.second};
        }
    }

    static pair<treap*, treap*> splitByValue(treap* root, int value) {
        if (root == nullptr)    return {nullptr, nullptr};
        if (root->x > value) {
            auto tmp = splitByRank(root->l, value);
            if (tmp.second != nullptr)  tmp.second->p = root;
            root->l = tmp.second;
            if (tmp.first != nullptr)   tmp.first->p = nullptr;
            root->update();
            return {tmp.first, root};
        }
        else {
            auto tmp = splitByRank(root->r, value);
            if (tmp.first != nullptr)  tmp.first->p = root;
            root->r = tmp.first;
            if (tmp.second != nullptr)   tmp.second->p = nullptr;
            root->update();
            return {root, tmp.second};
        }
    }

    static void query1SipmleAdd(treap*& root, int _x) {
        treap* node = new treap(_x);
        root = merge(root, node);
    }

    static void query1AddIntoSorted(treap*& root, int _x) {
        auto tmp = splitByValue(root, _x);
        treap* node = new treap(_x);
        tmp.first = merge(tmp.first, node);
        root = merge(tmp.first, tmp.second);
    }

    static treap* divideAndCombine(treap* root, int count, bool from, int bit_id, int xor_value, long long& container) {
        if (root == nullptr)    return root;
        if (sizeOf(root) == count)  {
            container += xored_sum(root, xor_value);
            return root;
        }
        int middle_value = ((~((1 << (bit_id + 1)) - 1)) & root->x);
        auto tmp = splitByValue(root, middle_value);
        bool swapped = ((xor_value >> bit_id) & 1);

        int ls = sizeOf(tmp.first), rs = sizeOf(tmp.second);

        if (from == 0) {
            if (!swapped) {
                if (ls >= count) {
                    tmp.first = divideAndCombine(tmp.first, count, from, bit_id - 1, xor_value, container);
                    return merge(tmp.first, tmp.second);
                }
                else {
                    tmp.second = divideAndCombine(tmp.second, count, from, bit_id - 1, xor_value, container);
                    container += xored_sum(tmp.first, xor_value);
                    return merge(tmp.first, tmp.second);
                }
            }
            else {
                if (rs >= count) {
                    tmp.second = divideAndCombine(tmp.second, count, from, bit_id - 1, xor_value, container);
                    return merge(tmp.first, tmp.second);
                }
                else {
                    tmp.first = divideAndCombine(tmp.first, count, from, bit_id - 1, xor_value, container);
                    container += xored_sum(tmp.second, xor_value);
                    return merge(tmp.first, tmp.second);
                }
            }
        }
        else {
            if (swapped) {
                if (ls >= count) {
                    tmp.first = divideAndCombine(tmp.first, count, from, bit_id - 1, xor_value, container);
                    return merge(tmp.first, tmp.second);
                }
                else {
                    tmp.second = divideAndCombine(tmp.second, count, from, bit_id - 1, xor_value, container);
                    container += xored_sum(tmp.first, xor_value);
                    return merge(tmp.first, tmp.second);
                }
            }
            else {
                if (rs >= count) {
                    tmp.second = divideAndCombine(tmp.second, count, from, bit_id - 1, xor_value, container);
                    return merge(tmp.first, tmp.second);
                }
                else {
                    tmp.first = divideAndCombine(tmp.first, count, from, bit_id - 1, xor_value, container);
                    container += xored_sum(tmp.second, xor_value);
                    return merge(tmp.first, tmp.second);
                }
            }
        }
    }

    static long long queryInterval(treap*& root, int l_bound, int r_bound, int xor_val) {
        // Treap as array. return sum on interval
        auto tmp = splitByRank(root, r_bound);
        auto tmp2 = splitByRank(tmp.first, l_bound - 1);
        long long answer = xored_sum(tmp2.second, xor_val);
        tmp.first = merge(tmp2.first, tmp2.second);
        root = merge(tmp.first, tmp.second);
        return answer;
    }

    static long long query2(treap*& root, treap*& addit, int l_bound, int r_bound, int xor_val) {
        long long overall = 0;
        int sz = sizeOf(root);
        if (l_bound <= sz) {
            int r_lim = min(r_bound, sz);
            long long cont = 0;
            root = divideAndCombine(root, r_lim, false, 29, xor_val, cont);
            overall -= cont;
            if (l_bound != 1) {
                cont = 0;
                root = divideAndCombine(root, l_bound - 1, false, 29, xor_val, cont);
            }
        }

        if (r_bound > sz) {
            l_bound = max(1, l_bound - sz);
            r_bound -= sz;
            overall += queryInterval(root, l_bound, r_bound, xor_val);
        }

        return overall;
    }

    static void generate(treap* root, vector<int>& values) {
        if (root == nullptr) return;
        generate(root->l, values);
        values.push_back(root->x);
        generate(root->r, values);
    }

    static void combineIntoSorted(treap*& root, treap*& addit) {
        vector<int> values;
        generate(addit, values);

        for(auto value : values) {
            query1AddIntoSorted(root, value);
        }
    }

    static void print(treap* root) {
        if (root == nullptr) return;
        print(root->l);
        cout << root->x << " ";
        print(root->r);
    }
};


int n, xr = 0;

void test(){
    treap* unsorted = nullptr, *sorted = nullptr, *addit = nullptr;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        treap::query1SipmleAdd(unsorted, a);
        treap::query1AddIntoSorted(sorted, a);
    }

    treap::print(unsorted);
    cout << endl;
    treap::print(sorted);
    cout << endl;
    int m, tp, x, lf, rg;
    cin >> m;
    bool nsort = true;

    while(m--) {
        cin >> tp;

        if (tp == 1) {
            cin >> x;
            if (nsort)
                treap::query1SipmleAdd(unsorted, x^xr);
            treap::query1SipmleAdd(addit, x^xr);
        }
        else if (tp == 2) {
            cin >> lf >> rg;
            if (nsort) {
                cout << treap::queryInterval(unsorted, lf, rg, xr) << endl;
            }
            else {
                cout << treap::query2(sorted, addit, lf, rg, xr) << endl;
            }
        }
        else if (tp == 3) {
            cin >> x;
            xr ^= x;
        }
        else {
            nsort = false;
            treap::combineIntoSorted(sorted, addit);
        }
    }

}

int main() {
    int t = 1;
    // cin >> t;
    loop(i,t){
        test();
    }

    return 0;
}

/*
100
2 AND
5 5
1

5 AND
5 4 3 2 1
1 2 2 4
5 XOR
5 4 3 2 1
1 2 2 4
5 OR
5 4 3 2 1
1 2 2 4


 */