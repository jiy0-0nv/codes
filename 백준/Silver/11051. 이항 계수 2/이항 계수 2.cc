#include <iostream>

using namespace std;

int dp[1001][1001];

int comb(int a, int b) {
	if (b == 0) return 1;
	if (dp[a][b]) return dp[a][b];
	else if (a == b) {
		dp[a][b] = 1;
	}
	else if (b == 1) {
		dp[a][b] = a;
	}
	else {
		dp[a][b] = (comb(a - 1, b) + comb(a - 1, b - 1)) % 10007;
	}
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << comb(n, k);

	return 0;
}