#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[101],dp[101];
	int ones = 0;
	bool all_ones = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ones += a[i];
		if (a[i] == 0) all_ones = false;
	}
	if (all_ones) {
		cout << n - 1;
		return 0;
	}
	dp[0] = 0;
	//Construction of DP
	for (int i = 0; i < n; i++) {
		if (a[i] == 1)
			dp[i + 1] = dp[i] - 1;
		else// a[i] == 0
			dp[i + 1] = dp[i] + 1;
	}

	//Kayf mas
	int best = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int cur = dp[j + 1] - dp[i];
			best = max(best, cur);
		}
	}

	cout << best + ones;

	return 0;
}
