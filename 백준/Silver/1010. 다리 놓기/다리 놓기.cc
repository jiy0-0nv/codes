#include <iostream>

using namespace std;

int dp[30][30];

int comb(int a, int b) {
	if (dp[a][b]) return dp[a][b];
	else if (a == b) dp[a][b] = 1;
	else if (b == 1) dp[a][b] = a;
	else dp[a][b] = comb(a - 1, b) + comb(a - 1, b - 1);
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << comb(m, n) << "\n";
	}

	return 0;
}