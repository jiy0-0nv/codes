#if 01
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int dp[500][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	cin >> dp[0][0];
	
	int ans = dp[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
			if (j == 0) dp[i][j] += dp[i - 1][j];
			else dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);

			if (i == n - 1 && ans < dp[i][j]) ans = dp[i][j];
		}
	}
	cout << ans;

	return 0;
}
#endif