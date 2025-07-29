#include <iostream>

using namespace std;

int tree[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int m;
	cin >> n >> m;

	int maxh = 0;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		if (tree[i] > maxh) maxh = tree[i];
	}

	int ans = 0;
	int up = maxh;
	int low = 0;
	int t = (up + low) / 2;

	while (low <= up) {
		long sum = 0;
		for (int i = 0; i < n; i++) { 
			if (tree[i] > t) sum += (tree[i] - t);
		}

		if (sum < m) {
			up = t - 1;
			t = low + (up - low) / 2;
		}
		else if (sum == m) {
			ans = t;
			break;
		}
		else {
			ans = t;
			low = t + 1;
			t = low + (up - low) / 2;
		}
	}
	cout << ans;
	return 0;
}