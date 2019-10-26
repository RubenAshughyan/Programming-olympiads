#include <iostream>
 #include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define all(j) j.begin(), j.end()
#define db(x) cout << #x << ": " << x << endl;
#define dbCont(x) cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;
#define SQ(x)	((x) * (x))

#define ll long long

using namespace std;
const int N = 500 * 1000 + 123;

const ll max_right = 1000 * 1000 * 1000;
const ll max_left = -1000 * 1000 * 1000;

struct Point {
	int x, y;

	bool operator < (const Point& other) const {
		return make_pair(x, y) < make_pair(other.x, other.y);
	}
};

int length2(Point& a, Point& b) {
	return SQ(a.x - b.x) + SQ(a.y - b.y);
}

vector<Point> pnts;

bool parallel(Point& a, Point& b, Point& c, Point& d) {
	return (b.x - a.x) * (d.y - c.y) == (d.x - c.x) * (b.y - a.y);
}

void check() {
	vector<ll> lens;
	int par_pairs = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			lens.push_back(length2(pnts[i], pnts[j]));
		}
	}


	sort(lens.begin(), lens.end());
	if (lens[0] == lens[1] && lens[0] == lens[2] && lens[0] == lens[3] && 
		lens[4] == lens[5] && lens[4] == lens[0] * 2) {
		cout << "Square" << endl;
		return;
	}
	

	if (lens[0] == lens[1] && lens[2] == lens[3] && lens[4] == lens[5] && lens[4] == lens[0] + lens[2]) {
		cout << "Rectangle" << endl;
		return;
	}

	if (lens[0] == lens[1] && lens[0] == lens[2] && lens[0] == lens[3] ||
		lens[4] == lens[1] && lens[4] == lens[2] && lens[4] == lens[3]) {
		cout << "Rhomb" << endl;
		return;
	}

	sort(pnts.begin(), pnts.end());
	do {
		par_pairs += parallel(pnts[0], pnts[1], pnts[2], pnts[3]);
	}while(next_permutation(pnts.begin(), pnts.end()));
	
	if (par_pairs == 0) {
		cout << "Quadrangle" << endl;
		return;
	}
	if (par_pairs == 16) {
		cout << "Parallelogram" << endl;
		return;
	}
	if (par_pairs == 8) {
		cout << "Trapezium" << endl;
		return;
	}
	assert(false);
}

int main() {
	pnts.resize(4);
	for(int i = 0; i < 4; i++) {
		cin >> pnts[i].x >> pnts[i].y;
	}

	check();
	//main();
	return 0;
}


/*

0 0
0 1
1 1
1 0


0 0
1 0
0 1
1 1


0 0 
1 1
2 1
1 0

0 0
1 1
2 1
3 0


2 0
2 4
0 2
4 2

5 2
6 4
6 0
7 2

1 0
0 1
0 -1
-1 0



*/

