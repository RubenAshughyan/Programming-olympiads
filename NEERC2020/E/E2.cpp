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
#define ll long long
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


// Function to implement the extended 
// euclid algorithm 
int gcd_extend(int a, int b,
               int& x, int& y)
{
    // Base Case 
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

        // Recursively find the gcd
    else {
        int g = gcd_extend(b,
                           a % b, x, y);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}

// Function to print the solutions of 
// the given equations ax + by = c 
void print_solution(int a, int b, int c)
{
    int x, y;
    if (a == 0 && b == 0) {

        // Condition for infinite solutions 
        if (c == 0) {
            cout
                    << "Infinite Solutions Exist"
                    << endl;
        }

            // Condition for no solutions exist
        else {
            cout
                    << "No Solution exists"
                    << endl;
        }
    }
    int gcd = gcd_extend(a, b, x, y);

    // Condition for no solutions exist 
    if (c % gcd != 0) {
        cout
                << "No Solution exists"
                << endl;
    }
    else {

        // Print the solution 
        cout << "x = " << x * (c / gcd)
             << ", y = " << y * (c / gcd)
             << endl;
    }
}

// Driver Code 
int main(void)
{
    int a, b, c;

    // Given coefficients 
    a = 4;
    b = 18;
    c = 10;

    // Function Call 
    print_solution(a, b, c);
    return 0;
} 