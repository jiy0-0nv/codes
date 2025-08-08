#include <iostream>

using namespace std;

int dp[501][501];
int N;
int sz[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		if (i == 1) sz[0] = a;
		sz[i] = b;
	}

	for (int i = 2; i <= N; i++) { // 구간 길이
		for (int j = 1; j + i - 1 < N + 1; j++) { // 시작 위치
			dp[j][j + i - 1] = dp[j + 1][j + i - 1] + sz[j - 1] * sz[j] * sz[j + i - 1];
			for (int k = j + 1; k < j + i - 1; k++) {
				int t = dp[j][k] + dp[k + 1][j + i - 1] + sz[j - 1] * sz[k] * sz[j + i - 1];
				if (dp[j][j + i - 1] > t) dp[j][j + i - 1] = t;
			}
		}
	}

	cout << dp[1][N];

	return 0;
}
