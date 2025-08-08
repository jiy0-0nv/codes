#if 01
#include <iostream>
#define INF 400000000

using namespace std;

int n, m;
int dst[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dst[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dst[a][b] > c) dst[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int s = 1; s <= n; s++) {
			if (dst[s][i] == INF) continue;
			for (int e = 1; e <= n; e++) {
				if (dst[i][e] == INF) continue;
				if (dst[s][e] > dst[s][i] + dst[i][e]) dst[s][e] = dst[s][i] + dst[i][e];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dst[i][j] == INF) cout << "0 ";
			else cout << dst[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
#endif