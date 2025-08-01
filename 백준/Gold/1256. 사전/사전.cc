#include <iostream>

using namespace std;

int n, m, k;
int dp[201][201];

int x, y, z;

int cb(int a, int b) {
	if (b == 0) return 1;
	if (dp[a][b]) return dp[a][b];

	if (a == b) dp[a][b] = 1;
	else if (b == 1) dp[a][b] = a;
	else dp[a][b] = cb(a - 1, b) + cb(a - 1, b - 1);
	if (dp[a][b] > 1000000000) dp[a][b] = 1000000001;
	return dp[a][b];
}

int find(int a, int b, int c) {

	if (c <= cb(a - 1, b - 1)) {
		cout << 'a';
		x = a - 1;
		y = b - 1;
		return 0;
	}
	else {
		cout << 'z';
		z -= cb(a - 1, b - 1);
		x = a - 1;
		y = b;
		return 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	if (k > cb(m+n, n)) {
		cout << -1;
		return 0;
	}

	x = n + m;
	y = n;
	z = k;
	for (int i = 0; i < n+m; i++) {
		if (y == 0) {
			cout << 'z';
			x--;
		}
		else if (y == x) {
			cout << 'a';
			y--;
		}
		else find(x, y, z);
	}

	return 0;
}