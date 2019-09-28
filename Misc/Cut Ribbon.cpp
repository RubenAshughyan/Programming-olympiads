#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a, b, c;

vector<int> dp(4001, INT_MAX);

int solve(int l) {

	if (l < 0)	return -1;
	if (l == 0) return 0;

	if (dp[l] != INT_MAX)
		return dp[l];

	int recursion = max(max(solve(l - a), solve(l - b)), solve(l - c));

	if (recursion == -1) {
		dp[l] = -1;
		return -1;
	}

	dp[l] = recursion + 1;
	return recursion + 1;
}

int main() {
	cin >> n >> a >> b >> c;
	cout << solve(n);
	return 0;
}
