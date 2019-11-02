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
#define i first
#define j second

#define type first
#define pos second

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

//////////////////////////////////////////////
const int N = 8;
//////////////////////////////////////////////


const int R = 0;
const int B = 1;
const int Q = 2;


int di[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

int inside(int i, int j) {
    return
            0 <= i && i < N &&
            0 <= j && j < N;
}

struct state {
    pii bk;
    vc<pair < int, pii>> wps;
    int white_turn = 1;

    bool operator < (const state &that) const {
        if(bk != that.bk) {
            return bk < that.bk;
        }

        if(wps != that.wps) {
            return wps < that.wps;
        }
        return white_turn < that.white_turn;
    }
};

string TYPE = "RBQ";
void print(state st){
    vc<vc<char>> x(N, vc<char> (N, '.'));
    for(auto wp: st.wps){
        x[wp.pos.i][wp.pos.j] = TYPE[wp.type];
    }
    x[st.bk.i][st.bk.j] = 'K';

    loop(i,N){
        loop(j,N){
            cout << x[i][j];
        }
        cout << endl;
    }
    cout << "-----------" << endl;

    cout << "KING: " << st.bk.i << ' ' << st.bk.j << endl;
    for(auto wp: st.wps){
        cout << TYPE[wp.type] << ": " <<  wp.pos.i << ' ' << wp.pos.j << endl;
    }
    db(st.white_turn);

    cout << "\n\n\n";
}

map<state, int> used;


pii input_pos() {
    string s;
    cin >> s;
    return {s[0] - 'a', s[1] - '1'};
}

int input_type() {
    string s;
    cin >> s;
    if (s == "R") return R;
    if (s == "B") return B;
    if (s == "Q") return Q;

    assert(false);
}

bool _can_rock_move(int fi, int  fj, int ni, int nj){
    return
            fi == ni || fj == nj;
}

bool _can_bishop_move(int fi, int  fj, int ni, int nj){
    return
            fi + fj == ni + nj ||
            fi - fj == ni - nj ;
}

int _can_piece(int type, int fi, int fj, int ni, int nj) {
//    db(type);
    if (type == R) {
        return _can_rock_move(fi, fj, ni, nj);
    }
    if (type == B) {
        return _can_bishop_move(fi, fj, ni, nj);
    }
    if (type == Q) {
        return
                _can_rock_move(fi, fj, ni, nj) ||
                _can_bishop_move(fi, fj, ni, nj);
    }

    assert(false);
}

int det(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x1 - x3) * (y2 - y3) - (y1-y3)*(x2-x3);
    //    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}


int align_1D(int a, int b, int c){
    return min(a,c) <= b && b <= max(a,c);
}


bool align(int ai, int aj, int bi, int bj, int ci, int cj){
    // must be on the same line
    if(det(ai, aj, bi, bj, ci, cj) != 0) return false;

    return
            align_1D(ai, bi, ci) &&
            align_1D(aj, bj, cj);


}

// maybe free cell
bool white_can_move(state st, int piece_i, int ni, int nj, bool ignore_black_king = false) {
    pair<int, pii > wp = st.wps[piece_i];

    int fi = wp.pos.i;
    int fj = wp.pos.j;

//    db(fi);
//    db(fj);
//    db(ni);
//    db(nj);

    // cant stay in place
    if (fi == ni && fj == nj) return false;

    // erase that piece
//    db(piece_i);
    st.wps.erase(st.wps.begin() + piece_i);


    if (_can_piece(wp.type, fi, fj, ni, nj)) {
        bool not_intersect = true;

        vc<pair < int, pii >> to_check = st.wps;

        if (!ignore_black_king) {
            to_check.push_back({-1, st.bk});
        }

        for (auto other_p: st.wps) {
            if (align(fi, fj, other_p.pos.i, other_p.pos.j, ni, nj)) {
                not_intersect = false;
            }
        }

        if (not_intersect) return true;
    }

    return false;


}

void normalize_state_if_captured(state &st) {

    int erase_ind = -1;

    loop(pi, st.wps.size()) {
        pair<int, pii > wp = st.wps[pi];

        // coincide with black king
        if (st.bk == MP(wp.pos.i, wp.pos.j)) {
            erase_ind = pi;
        }
    }

    if (erase_ind != -1) {
        st.wps.erase(st.wps.begin() + erase_ind);
    }
}

bool is_king_checked(const state &st) {
    bool is_checked = false;

    int pi = 0;
    for (auto wp : st.wps) {
        if (white_can_move(st, pi, st.bk.i, st.bk.j)) {
            is_checked = true;
        }
        pi++;
    }
    return is_checked;
}

vc<state> get_neighbors(state &st) {

    vc<state> neighbors;

    if (st.white_turn) {

        // try all pieces
        loop(pi, st.wps.size()) {


            // try all moves
            loop(ni, N) {
                loop(nj, N) {
                    if (white_can_move(st, pi, ni, nj)) {

                        state to = st;
                        to.wps[pi].second = {ni, nj};
                        to.white_turn ^= 1;

//                        cout << "cannnnnnnnnnnnnnnnnnn" << endl;
//                        db(pi);
//                        print(st);
//                        print(to);
//                        exit(0);


                        neighbors.push_back(to);
                    }
                }
            }


        }

        return neighbors;
    }

    // black turn

    // try_all moves
    loop(d, 8) {
        int i = st.bk.i + di[d];
        int j = st.bk.j + dj[d];
        if (!inside(i, j)) continue;

        state to = st;
        to.bk = {i, j};
        to.white_turn ^= 1;

        normalize_state_if_captured(to);

        // check if king moved under check
        if (is_king_checked(to)) continue;

        neighbors.push_back(to);

    }

//    vc<state> unused;
//    for(auto neigh: neighbors){
//        if(!used[neigh]){
//            used[neigh] = 1;
//            unused.push_back(neigh);
//        }
//    }
//    return unused;
    return neighbors;
}

bool is_checkmate(state st) {

    // king must be checked
    if (!is_king_checked(st)) return false;


    // after trying any move it must be still in check
    // try_all moves
    loop(d, 8) {
        int i = st.bk.i + di[d];
        int j = st.bk.j + dj[d];
        if (!inside(i, j)) continue;

        state to = st;
        to.bk = {i, j};
        to.white_turn ^= 1;

        normalize_state_if_captured(to);

        // check if king moved under check
        if (!is_king_checked(to)) {
            // king made a move and escaped a checkmate
            return false;
        }

    }

    return true;
}

bool is_pat(state st) {

    // king must be not checked checked
    if (!is_king_checked(st)) return false;


    // after trying any move it must be in check
    // try_all moves
    loop(d, 8) {
        int i = st.bk.i + di[d];
        int j = st.bk.j + dj[d];
        if (!inside(i, j)) continue;

        state to = st;
        to.bk = {i, j};
        to.white_turn ^= 1;

        normalize_state_if_captured(to);

        // check if king moved under check
        if (!is_king_checked(to)) {
            // king made a move and escaped a pat
            return false;
        }
    }

    return true;
}

int minimize(state &st);

int maximize(state &st) {

////////////////////////////////
    cout << "maximize" << endl;
    print(st);

    ///////////////////

    used[st] = 1;


    // black turn

    // ete mate 0 qaylic
    if (is_checkmate(st)) {
        db("checkmate a");
        return 0;
    }

    // ete pata
    if (is_pat(st)) {
        db("pata a");

        return +1e9;
    }

    vc<state> neighbors = get_neighbors(st);
//    for(state neigh: neighbors){
//        print(neigh);
//    }

    int mx = 0;
    for (auto neigh: neighbors) {
        if(used[neigh]) continue;

        int curVal = minimize(neigh);
        mx = max(mx, curVal);
    }

    return mx+1;
}

int minimize(state &st) {


//////////////////////////////
    db(used.size());
    cout << "minimize" << endl;
    print(st);

    //////////

    used[st] = 1;

    // white turn

    // cant be terminal

    int mn = +1e9;

    vc<state> neighbors = get_neighbors(st);
    reverse(all(neighbors));
    for(state neigh: neighbors){
        print(neigh);
    }

    for (auto neigh: neighbors) {
        if(used[neigh]) continue;


        int curVal = maximize(neigh);
        mn = min(mn, curVal);
    }

    return mn+1;
}


void test() {
    pii bk = input_pos();

    int t1 = input_type();
    pii wp1 = input_pos();

    int t2 = input_type();
    pii wp2 = input_pos();

    state start;
    start.bk = bk;
    start.wps = {{t1, wp1},
                 {t2, wp2}};
    start.white_turn = 1;

    int ans = minimize(start);

    db(ans);
    cout << ans << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    loop(i, t) {
        test();
    }

    return 0;
}
/*



*/