#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int dp[100001] = { 0, };
	int ans = -100000000;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (dp[i - 1] < 0) {
			dp[i] = t;
		}
		else dp[i] = dp[i - 1] + t;

		if (dp[i] > ans) ans = dp[i];
	}

	cout << ans;

	return 0;
}