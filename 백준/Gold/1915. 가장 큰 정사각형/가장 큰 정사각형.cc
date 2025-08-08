#include <iostream>

using namespace std;

int N, M;
int sum[1001][1001];

int ans = 0;

bool find(int l) {
	for (int i = 0; i + l <= N; i++) {
		for (int j = 0; j + l <= M; j++) {
			if (sum[i][j] + sum[i + l][j + l] - sum[i][j + l] - sum[i + l][j] == l * l) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char t;
			cin >> t;
			sum[i][j] = (t - '0') + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	for (int l = 1; l <= N; l++) {
		if (find(l)) ans = l;
		else break;
	}

	cout << ans * ans;

	return 0;
}