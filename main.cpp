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

using namespace std;

using namespace std;

// int add(int param1, int param2) {
//   return param1 + param2;
// }


#define add Add()

struct Add {
    Add(){};

    int operator () (int param1, int param2) {
        return param1 + param2;
    }
};
int main() {

    cout << add(1,2);

    return 0;
}



