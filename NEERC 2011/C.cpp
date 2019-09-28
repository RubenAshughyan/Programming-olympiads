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

#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int INF = 1000 * 1000;
const int DEBUG = 0;

int m,n, k,smin, smax;
string oldText, newText;
map<char, vc<vc<char>>> mp;

vc<char> allLetters;
vc<vc<char>> os;


void draw(vc<vc<char>> &field, int col, char c){
    loop(i, m){
        loop(j,k){
            field[i][col+j] = mp[c][i][j];
        }
    }
}

void print(vc<vc<char>> field){
    loop(i,field.size()){
        loop(j,field[i].size()){
            cout << field[i][j];
        }
        cout << endl;
    }
}

vc<vc<int>> memoLetter(2040+5, vc<int> (27, -1));
int getDiffLetter(int col, char c){

    int memoVal = memoLetter[col][c-'A'];
    if(memoVal != -1) return memoVal;

    int ans = 0;
    loop(i,m){
        loop(j,k){
            if(mp[c][i][j] != os[i][col+j]){
                ans++;
            }
        }
    }
    return memoLetter[col][c-'A'] = ans;
}

vc<int> memoDiffSpace(2000+5, -1);

int getDiffSpacePref(int col){
    if(col < 0) return 0;
    if(memoDiffSpace[col] != -1)
        return memoDiffSpace[col];

    int ans = 0;
    loop(i,m){
            if('*' == os[i][col]){
                ans++;
            }
    }
    return memoDiffSpace[col] = ans + getDiffSpacePref(col-1);
}

int getDiffSpace(int lcol, int rcol){
    return getDiffSpacePref(rcol) - getDiffSpacePref(lcol-1);
}

vc<int> answerVec;

map<int,map<int,int>> memo;
map<int,map<int,vc<int>>> memoAns;

vc<int> SPACES = {311, 0, 2, 0, 0, 7, 0, 0, 6, 0, 10, 8, 0, 1, 10, 10, 10, 0, 0, 9, 2, 0, 10, 1, 0, 10, 2, 10, 9, 1};


int solve(int j, int i){
//    if(memo[i].count(j)){
//        answerVec = memoAns[i][j];
//        return memo[i][j];
//    }

    printf("i j %d %d\n",i,j);

    if(i == newText.size()){
        answerVec.clear();
        printf("all letters done\n");

        return getDiffSpace(j, n-1);
    }


    int ans = INF;

    int L = smin, R = smax;
    if(i == 0){
        L = 0;
        R = n;
    }

    //////////////////
//    L = R = SPACES[i];
    //////////////////

    vc<int> curAnsVec;
    for(int s = L; s <= R; s++){
        // put
        if(j+s+k >= n) continue;
        int curDiff = getDiffLetter(j+s, newText[i]);
        curDiff += getDiffSpace(j, j+s-1);

        int curAnswer = curDiff + solve(j+s+k, i+1);
        if(ans > curAnswer){
            ans = curAnswer;
            curAnsVec = answerVec;
            curAnsVec.push_back(s);
        }
    }
    answerVec = curAnsVec;


    memoAns[i][j] = answerVec;
    return memo[i][j] = ans;
}

int main() {
    freopen("caption.in", "r", stdin);
    freopen("caption.out", "w", stdout);

    string s;
    getline(cin,s);

    istringstream numbers(s);
    numbers >> m >> n >> k >> smin >> smax;

    printf("get whole lines\n");
    vc<string> lines;
    loop(i,m) {
        getline(cin, s);
        lines.push_back(s);
    }

    printf("get all letters\n");
    for(char c : lines[0]){
        if(isupper(c)){
            allLetters.push_back(c);
            mp[c].resize(m);
        }
    }

    dbCont(allLetters);

    printf("set all symbol\n");

    for(char &c: lines[0]) if(isupper(c)) c = ' ';

    loop(i,m){
        int letterIndex = -1;
        string line = lines[i];
        loop(j, line.length()){
            if(line[j] != ' ' && line[j-1] == ' '){
                letterIndex++;
            } else if(lines[i][j] == ' ') {
                continue;
            }


            mp[allLetters[letterIndex]][i].push_back(line[j]);

        }
    }

    printf("set space\n");
    mp[' '] = mp.begin()->second;
    loop(i,m){
        loop(j,k){
            mp[' '][i][j] = '.';
        }
    }

    printf("read old text\n");
    getline(cin, oldText);

    printf("read spaces\n");
    getline(cin,s);
    numbers = istringstream(s);

    vc<int> spaces;
    loop(i, oldText.length()){
        spaces.push_back(0);
        numbers >> spaces.back();
    }


    printf("read new text\n");
    getline(cin, newText);


    for(char c : allLetters){
        db(c);
    }

    printf("make original field\n");
    os = vc<vc<char>>(m, vc<char> (n, '.'));

    int j = 0;
    loop(i, oldText.size()){
        j += spaces[i];
        draw(os, j, oldText[i]);
        j += k;
    }

    print(os);
    // solution

    int answer = solve(0,0);
    cout << answer << endl;
    reverse(all(answerVec));


//    assert(answerVec.size() == newText.size());

    loop(i,answerVec.size()){
        cout << answerVec[i];
        if(i+1 != answerVec.size()){
            cout << ' ';
        }
    }

    return 0;
}

/*
5
1 2
2 3
3 4
3 5

 */