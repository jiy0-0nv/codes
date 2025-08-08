#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 100000000

using namespace std;

// D[시행 횟수][왼쪽발][오른쪽발] = 최소의 힘
int D[100001][5][5];

int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int cnt = 0;
	fill(&D[0][0][1], &D[0][0][0] + 100001 * 5 * 5, INF);

	int c;
	while (1) {
		cin >> c;
		if (c == 0) break;

		cnt++;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				int t;

				if (c == j) t = 1;
				else if (j == 0) t = 2;
				else if ((j + c) & 1) t = 3;
				else t = 4;
				D[cnt][c][k] = min(D[cnt][c][k], D[cnt - 1][j][k] + t);

				if (c == k) t = 1;
				else if (k == 0) t = 2;
				else if ((k + c) & 1) t = 3;
				else t = 4;
				D[cnt][j][c] = min(D[cnt][j][c], D[cnt - 1][j][k] + t);
			}
		}
	}

	int ans = INF;
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			ans = min(ans, D[cnt][j][k]);
		}
	}
	cout << ans;

	return 0;
}