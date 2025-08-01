#include <iostream>

using namespace std;

int w, h;
int dp[101][101][2][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;

	for (int i = 1; i <= h; i++) dp[i][0][0][0] = 1;
	for (int i = 1; i <= w; i++) dp[0][i][1][0] = 1;

	dp[1][2][0][1] = 1;
	dp[1][2][1][0] = 1;
	dp[2][1][0][0] = 1;
	dp[2][1][1][1] = 1;
	dp[2][2][0][0] = 1;
	dp[2][2][0][1] = 1;
	dp[2][2][1][0] = 1;
	dp[2][2][1][1] = 1;

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (i < 3 && j < 3) continue;
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i-1][j][0][1]) % 100000;
			dp[i][j][0][1] = dp[i - 1][j][1][0] % 100000;
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % 100000;
			dp[i][j][1][1] = dp[i][j - 1][0][0] % 100000;
		}
	}

	h--;
	w--;
	cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % 100000;

	return 0;
}