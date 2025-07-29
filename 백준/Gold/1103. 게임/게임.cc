#include <iostream>

using namespace std;

int n, m;
int board[50][50];

int dp[50][50];
bool vst[50][50];

int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

int dfs(int cr, int cc) {

	for (int* d : dir) {
		int nr = cr + d[0] * board[cr][cc];
		int nc = cc + d[1] * board[cr][cc];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] == -1) {
			if (dp[cr][cc] < 1) dp[cr][cc] = 1;
			continue;
		}

		if (vst[nr][nc]) {
			return -1;
		}

		else if (dp[nr][nc] > 0) {
			if (dp[cr][cc] < dp[nr][nc] + 1) dp[cr][cc] = dp[nr][nc] + 1;
			continue;
		}

		else { 
			vst[nr][nc] = true;
			if (dfs(nr, nc) == -1) return -1;
			vst[nr][nc] = false;
			if (dp[cr][cc] < dp[nr][nc] + 1) dp[cr][cc] = dp[nr][nc] + 1;
		}
	}
	return dp[cr][cc];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			if (t == 'H') board[i][j] = -1;
			else board[i][j] = t - '0';
		}
	}

	vst[0][0] = true;
	if (dfs(0, 0) == -1) cout << -1;
	else cout << dp[0][0];

	return 0;
}
