#include <iostream>
#define ll long long

using namespace std;

int n;
ll dp[100][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int t;
	cin >> t;
	dp[0][t] = 1;
	                                                                                          
	for (int j = 1; j < n - 1; j++) {
		cin >> t;
		for (int i = 0; i <= 20; i++) {
			if (dp[j - 1][i]) {
				if (i + t <= 20) dp[j][i + t] += dp[j - 1][i];
				if (i - t >= 0) dp[j][i - t] += dp[j - 1][i];
			}
		}
	}
	cin >> t;
	cout << dp[n - 2][t];

	return 0;
}