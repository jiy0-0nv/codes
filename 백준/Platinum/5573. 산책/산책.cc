#include <iostream>

using namespace std;

int h, w, n;
bool town[1001][1001];
int walk[1001][1001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) cin >> town[i][j];
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int t = walk[i - 1][j][0] + walk[i][j - 1][1];
			if (i == 1 && j == 1) t = n - 1;
			walk[i][j][0] = t / 2; // 아
			walk[i][j][1] = t / 2; // 오
			if (t % 2) {
				walk[i][j][town[i][j]] += 1;
				town[i][j] = !(town[i][j]);
			}
		}
	}

	int r = 1, c = 1;

	while (1) {
		if (r > h || c > w) {
			cout << r << " " << c;
			break;
		}
		else {
			if (town[r][c]) c++;
			else r++;
		}
	}

	return 0;
}