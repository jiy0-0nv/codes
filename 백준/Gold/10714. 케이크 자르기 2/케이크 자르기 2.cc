#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cake[2000];
long long dp[2000][2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cake[i];
		dp[i][i] = (N & 1) ? cake[i] : 0;
	}

	for (int d = 2; d <= N; d++) { // d조각 남았을 때
		for (int i = 0; i < N; i++) {
			// 남의 차례 -> greedy
			if (N + d & 1) {
				dp[i][(i + d - 1 + N) % N] = cake[i] > cake[(i + d - 1 + N) % N] ? dp[(i + 1) % N][(i + d - 1 + N) % N] : dp[i][(i + d - 2 + N) % N];
			}
			// 내 차례 -> 최선
			else {
				dp[i][(i + d - 1 + N) % N] = max(cake[i] + dp[(i + 1) % N][(i + d - 1 + N) % N], cake[(i + d - 1 + N) % N] + dp[i][(i + d - 2 + N) % N]);
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i][(i + N - 1 + N) % N]);
	}
	cout << ans;

	return 0;
}