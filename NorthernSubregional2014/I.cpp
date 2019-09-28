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
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
#define loop1(xxx, yyy) for(int xxx = 1; xxx <= yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
//#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

int n;

struct Arriva {
    int val;
    int length;
    bool sheet;
};

typedef pair<Arriva, Arriva>  paa;
vector<Arriva> v;
vector<Arriva> nv;

vector<vector<int>> nodes;

set<pii> consec;
map<int, int> counts;
map<pii,int> consec_ind;

vc<int> sv;


int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int elem;
        cin >> elem;
        Arriva a;
        a.val = elem;
        a.length = 1;
        a.sheet = true;
        v.push_back(a);
        sv.push_back(elem);
    }

    sort(all(sv));
    for (int l = 0; l < sv.size(); ++l) {
        counts[sv[l]]++;
    }
    for(int i = 0; i +1 < n; i++){
        if(sv[i] != sv[i + 1]){
            consec.insert({sv[i], sv[i + 1]});
        }
    }

    int GI = 0;
    for(auto p : consec){
        consec_ind[p] = GI++;
    }

    // compress
    for (Arriva x : v) {
        if (nv.empty() || nv.back().val != x.val) {
            nv.push_back(x);
        }
        else {
            nv.back().length++;
        }
    }
    v = nv;

    //unique
    for (int i = 0; i < v.size(); ++i) {
        if (counts[v[i].val] == v[i].length){
            for (int j = 0; i+j+1 < (int)v.size(); ++j) {
                if (0==consec.count(MP(v[i+j].val, v[i+j+1].val)))
                    break;
                if (v[i+j+1].length == counts[v[i+j+1].val]) {
                    v[i+1+j].sheet = false;
                }
                else{
                    v[j+1+i].sheet = false;
                    break;
                }
            }

            for (int j = 0; i-j-1 >= 0; ++j) {
                if (0==consec.count(MP(v[i-j].val, v[i-j-1].val)))
                    break;
                if (v[i-j-1].length == counts[v[i-j-1].val]) {
                    v[i-1-j].sheet = false;
                }
                else{
                    v[i-1-j].sheet = false;
                    break;
                }
            }

        }
    }

    // cosntruct graph
    nodes.resize(consec.size());
    for (int j = 0; j + 1 < v.size(); ++j) {
        if (consec.count(MP(v[j].val, v[j + 1].val)) && v[j].sheet && v[1+j].sheet){
            nodes[consec_ind[MP(v[j].val, v[j + 1].val)]].push_back(j);
        }
    }

    //

    // find max
    vector<int> kpcrac; // hajordin
    int lastk = 0; // voch 2
    for (int k = 0; k < nodes.size(); ++k) {
        if (nodes[k].size() != 2){
            if (nodes[k].size() == 1){
                // tars et vaze
                int kk = k;
                int ind = nodes[k][0];
                while (kk > lastk){
                    kk--;
                    for (int i = 0; i < nodes[kk].size(); ++i) {
                        if (nodes[kk][i] != ind - 1) {
                            ind = nodes[kk][i];
                            kpcrac.push_back(ind - 1);
                            break;
                        }
                    }
                    ind = 1 - ind;
                }
                // uxix araj vaze
                ind = nodes[k][0];
                while (k + 1 < nodes.size()){
                    k++;
                    bool b=false;
                    for (int i = 0; i < nodes[k].size(); ++i) {
                        if (nodes[k][i] != ind + 1){
                            ind = nodes[k][i];
                            kpcrac.push_back(ind);
                            b = true;
                            break;
                        }
                    }
                    if (b)
                        break;
                    if (nodes[k].size() == 2)
                        ind = 1 - ind;
                    else
                        nodes[k][ind] = -2;
                }
                lastk = k;
                continue;
            }
        }
    }
    if (1 + lastk != nodes.size()){
        int k = nodes.size();
        int ind = nodes[k][0];
        while (k > lastk){
            k--;
            for (int i = 0; i < nodes[k].size(); ++i) {
                if (nodes[k][i] != ind - 1){
                    ind = nodes[k][i];
                    kpcrac.push_back(ind-1);
                    break;
                }
            }
            ind = 1 - ind;
        }
    }
    sort(all(kpcrac));
    int indd = 0, indt = 0;
    for (int m = 0; m < v.size(); ++m) {
        indd += v[m].length;
        if (m != kpcrac[indt]){
            cout << indd << " ";
            indd = 0;
        }
    }
    return 0;
}
