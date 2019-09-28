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



const int INF = 1e9;

struct node {
    int x, y;
    node *l, *r;
    int sz;
    node(int _x) {
        x = _x;
        y = rand();
        l = NULL;
        r = NULL;
        sz = 1;
    }

    node(int _x, int _y, node *_l, node *_r) {
        x = _x;
        y = _y;
        l = _l;
        r = _r;
    }
};

int node_sz(node * v){
    if(v == NULL) return 0;
    return v->sz;
}

void recalc(node * v){
    if(v == NULL) return;
    v->sz = 1+ node_sz(v->l) + node_sz(v->r);
}

node * merge(node * l, node * r){
    node * res;

    if(l == NULL) res = r;
    else if(r == NULL) res = l;
    else if(l->y < r->y){
        node * new_left = merge(l,r->l);
        node * new_right = r->r;
        res = new node(r->x, r->y,new_left,new_right);
    }
    else{
        node * new_right = merge(l->r,r);
        node * new_left = l->l;
        res = new node(l->x, l->y,new_left,new_right);
    }
    recalc(res);
    return res;
}

void split(node *v, int _x, node *&l, node *&r){
    if(v == NULL){
        l = r = NULL;
    }
    else if(_x <= v->x){
        split(v->l,_x,l, v->l);
        r = v;
    }
    else{
        split(v->r,_x, v->r, r);
        l = v;
    }
    recalc(l);
    recalc(r);
}


void insert(node * &root, int _x){
    node * l, * r;
    split(root,_x,l,r);

    node * m = new node(_x);
    root = merge(merge(l,m),r);
}

void erase(node * & root ,int _x){
    node * l, *m, * r;
    split(root,_x,l,r);
    split(r,_x+1,m,r);

    root = merge(l,r);
}

int n, m;
int a[N];
map<int, node *> mp;

void dfs(node * v){
    if(v == NULL) return;

    dfs(v->l);
    printf("%d ",v->x);
    dfs(v->r);
}

void out(){
    for(auto p : mp){
        printf("%d: ",p.first);
        dfs(p.second);
        printf("\n");
    }
    printf("--------------\n");
}


int main() {
/*
    node * root = NULL;
    while(1){
        string op;
        int x;
        cin >> op >> x;
        if(op == "i"){
            insert(root,x);
        }
        else{
            erase(root,x);
        }

        printf("sz %d\n",node_sz(root));
        dfs(root);
        printf("\n");
    }

*/
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        node *&root = mp[a[i]];
        insert(root,i);
    }

//    out();


    int ind, nw;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &ind, &nw);

        int old = a[ind];

//        dfs(mp[old]); cout << endl;
        erase(mp[old], ind);
//        dfs(mp[old]); cout << endl;


//        dfs(mp[nw]); cout << endl;
        insert(mp[nw],ind);
//        dfs(mp[nw]); cout << endl;


        node *l,*r;
        split(mp[nw],ind,l,r);
        printf("%d\n",node_sz(l));
        mp[nw] = merge(l,r);

        a[ind] = nw;

//        printf("array is :\n");
//        for(int j = 0; j < n; j++){
//            cout<< a[j] << ' ';
//        }
//        cout << endl;
    }


    return 0;
}
