#include <iostream>
using namespace std;

int n;
int ans = 0;
bool vc[15];
int col[15];

void dfs(int coln) {
	if (coln == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {

		bool cango = true;
		if (vc[i]) continue;

		for (int r = 0; r < coln; r++) {
			if (col[r] - r == i - coln) {
				cango = false;
				break;
			}
			else if (col[r] + r == i + coln) {
				cango = false;
				break;
			}
		}

		if (!cango) continue;
		col[coln] = i;
		vc[i] = true;
		dfs(coln + 1);
		vc[i] = false;
	}
}

int main()
{

	cin >> n;
	dfs(0);
	cout << ans << "\n";

	return 0;
}