#include <iostream>

using namespace std;

int N;
int stair[301];
int dp[301][2] = {};

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> stair[i];

	dp[N][0] = stair[N];
	dp[N - 1][1] = stair[N] + stair[N - 1];
	for (int i = N-2; i > 0; i--) {
		if (dp[i + 2][0] > 0 || dp[i + 2][1] > 0) dp[i][0] = max(dp[i + 2][0], dp[i + 2][1]) + stair[i];
		if (dp[i + 1][0] > 0) dp[i][1] = dp[i + 1][0] + stair[i];
	}

	int ans = dp[1][0];
	if (ans < dp[1][1]) ans = dp[1][1];
	if (ans < dp[2][1]) ans = dp[2][1];
	cout << ans;

	return 0;
}