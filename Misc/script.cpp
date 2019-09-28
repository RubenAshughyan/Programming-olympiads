#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>


#define pii pair<int,int>
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
using namespace std;

template<typename T>
void log(vector<T> &v, string name) {
	printf("%s : ", name.c_str());
	for (auto p : v)
		cout << p << ' ';
	printf("\n");
}

struct state {
	int fi[9][9];
	bool operator < (const state &that) const {
		ostringstream s1, s2;
		loop(i, 9)
			loop(j, 9) {
				s1 << fi[i][j];
				s2 << that.fi[i][j];
			}
		return s1.str() < s2.str();
	}
};

set<state> used;

void pr(state state1) {
	loop(i, 9) {
		loop(j, 9) {
			printf("%d ", state1.fi[i][j]);
		}
		printf("\n");
	}
}

pii norm(string l) {
	int i = l[0] - 'A';
	int j = l[1] - '1';
	return{ i, j };
}

bool ins(int i, int j) {
	return
		0 <= i && i < 9 &&
		0 <= j && j < 9;
}

bool valid(state &s) {
	//printf("checking\n");
	//pr(s);
	int d[10];


	loop(i, 9) {
		loop(j, 10) d[j] = 0;
		loop(j, 9) if (s.fi[i][j] != 0) {
			d[s.fi[i][j]]++;
			if (d[s.fi[i][j]] >= 2) {
				//printf("invalid on %d row\n",i);
				return false;
			}
		}
	}

	loop(j, 9) {
		loop(i, 10) d[i] = 0;
		loop(i, 9) if (s.fi[i][j] != 0) {
			d[s.fi[i][j]]++;
			if (d[s.fi[i][j]] >= 2) {
				//printf("invalid on %d col\n",j);
				return false;
			}
		}
	}


	for (int I = 0; I < 9; I += 3)
		for (int J = 0; J < 9; J += 3) {
			loop(i, 10) d[i] = 0;
			loop(i, 3)loop(j, 3) if (s.fi[I+i][J+j] != 0) {
				d[s.fi[I+i][J+j]]++;
				if (d[s.fi[I+i][J+j]] >= 2) {
				//printf("invalid on %d %d sq\n",I,J);
					return false;
				}
			}
		}
	//printf("valid\n");
	return true;
}

bool solved(state &s) {
	bool b = true;
	loop(i, 9) loop(j, 9) b = b && (s.fi[i][j] != 0);
	return b && valid(s);
}




void rec_solve(state v) {
	//printf("dfs\n");
	//pr(v);

	if (solved(v)) {
		printf("solved\n");
		pr(v);
		exit(0);
	}

	loop(i, 9){
		loop(j, 9) {
			if (v.fi[i][j] == 0) {
				for (int x = 1; x <= 9; x++) {
					v.fi[i][j] = x;
					if (valid(v)) {
						rec_solve(v);
						v.fi[i][j] = 0;
					}
				}
				return;
			}
		}
	}
}


int n;
int main() {
	//freopen("out.txt", "w", stdout);
	set<pii > st;

	for (int i = 1; i <= 9; i++)
		for (int j = i + 1; j <= 9; j++)
			st.insert({ i, j });

	//printf("%d\n", st.size());

	cin >> n;
	state start;

	used.find(start);
	used.insert(start);

	loop(i, 9)loop(j, 9)start.fi[i][j] = 0;
	loop(i, n) {
		int a, b;
		string la, lb;
		cin >> a >> la >> b >> lb;
		st.erase({ a, b });
		st.erase({ b, a });
		pii p = norm(la);
		start.fi[p.first][p.second] = a;
		p = norm(lb);
		start.fi[p.first][p.second] = b;
	}

	for (int i = 1; i <= 9; i++) {
		string str;
		cin >> str;
		pii p = norm(str);
		start.fi[p.first][p.second] = i;
	}

	//pr(start);

	int xx[9][9] = {
{3, 5, 6, 2, 7, 4, 1, 9, 8},
{2, 7, 4, 1, 9, 8, 3, 5, 6},
{1, 9, 8, 3, 5, 6, 2, 7, 4},
{5, 6, 2, 7, 4, 1, 9, 8, 3},
{7, 4, 1, 9, 8, 3, 5, 6, 2},
{9, 8, 3, 5, 6, 2, 7, 4, 1},
{6, 2, 7, 4, 1, 9, 8, 3, 5},
{4, 1, 9, 8, 3, 5, 6, 0, 7},
{8, 3, 5, 6, 2, 7, 4, 0, 9}
	};

	//loop(i, 9)
	//	loop(j, 9)
	//	start.fi[i][j] = xx[i][j];

	//cout << "valid " << valid(start) << endl;
	//cout << "solved " << solved(start) << endl;

	rec_solve(start);
	return 0;
}


