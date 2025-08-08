#include <iostream>
#include <algorithm>

using namespace std;

int T;
int dp[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		fill(&dp[0][0], &dp[0][0] + 1000000, 0);
		
		int cards[1000];
		for (int i = 0; i < N; i++) {
			cin >> cards[i];
			if (N & 1) dp[i][i] = cards[i];
		}

		for (int d = 2; d <= N; d++) {
			for (int i = 0; i + d - 1 < N; i++) {
				// 명우 차례
				if (N + d & 1) {
					dp[i][i + d - 1] = min(dp[i + 1][i + d - 1], dp[i][i + d - 2]);
				}
				// 근우 차례
				else {
					dp[i][i + d - 1] = max(cards[i] + dp[i + 1][i + d - 1], dp[i][i + d - 2] + cards[i + d - 1]);
				}
			}
		}

		cout << dp[0][N - 1] << "\n";
	}

	return 0;
}