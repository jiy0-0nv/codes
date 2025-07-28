#if 1
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;

int h[100][2];
int c[13][2];
int hn = 0;
int cn = 0;

int cd[100][13];

int ans = 100 * 100;

bool vst[13];
int sd[13];

void bt(int d) {
	if (d == m) {
		int s = 0;
		for (int k = 0; k < hn; k++) {
			int mcd = 100;
			for (int l = 0; l < m; l++) {
				if (mcd > cd[k][sd[l]]) mcd = cd[k][sd[l]];
			}
			s += mcd;
		}
		if (ans > s) ans = s;
		return;
	}

	for (int i = 0; i < cn; i++) {
		if (vst[i]) continue;
		if (d > 0 && sd[d - 1] >= i) continue;
		vst[i] = true;
		sd[d] = i;
		bt(d + 1);
		vst[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == 1) { h[hn][0] = i; h[hn][1] = j; hn++; }
			else if (t == 2) { c[cn][0] = i; c[cn][1] = j; cn++; }
		}
	}

	for (int i = 0; i < hn; i++) {
		for (int j = 0; j < cn; j++) {
			cd[i][j] = abs(h[i][0] - c[j][0]) + abs(h[i][1] - c[j][1]);
		}
	}

	bt(0);

	cout << ans;
	return 0;
}
#endif