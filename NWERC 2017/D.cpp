
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

vector<string> sentence;

map<string, vc<string>> correct;
map<string, vc<string>> incorrect;

int main(){
    int n;
    cin >> n;
    loop(i,n){
        string s;
        cin >> s;
        sentence.push_back(s);
    }

    int m;
    cin >> m;
    loop(i,m){
        string a,b,type;
        cin >> a >> b >> type;
        if(type == "correct"){
            correct[a].push_back(b);
        } else {
            incorrect[a].push_back(b);
        }
    }

    bool allOne = true;
    for(string word: sentence){
        if(correct[word].size() + incorrect[word].size() != 1){
            allOne = false;
        }
    }
    if(allOne){
        bool isCorrect = true;
        for(string word: sentence){
            string translation;
            if(correct[word].size())
                translation =  correct[word].front();
            else {
                translation = incorrect[word].front();
                isCorrect = false;
            }
            cout <<translation << ' ';


        }
        cout << endl;
        if(isCorrect)
            cout << "correct" << endl;
        else
            cout << "incorrect" << endl;
        return 0;
    }

    ll correctCnt = 1;
    for(string word: sentence){
//        db(correct[word].size());
        correctCnt *= correct[word].size();
    }

    ll allCnt = 1;
    for(string word: sentence){
        allCnt *= (incorrect[word].size() + correct[word].size());
    }
    cout << correctCnt << " correct" << endl;
    cout << allCnt-correctCnt << " incorrect" << endl;
}


/*
7
als mollen mollen mollen mollen
mollen mollen
4
als when correct
mollen moles correct
mollen destroy correct
mollen mills incorrect


 5
de zuigers zijn buiten werking
6
zijn are correct
banaan banana correct
de the correct
zuigers suckers incorrect
buiten out correct
werking working incorrect

*/