#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int alst[10000];
	for (int i = 0; i < n; i++)cin >> alst[i];

	int ans = 0;

	for (int l = 0; l < n; l++) {
		int sum = 0;
		for (int r = l; r < n; r++) {
			sum += alst[r];
			if (sum == m) ans++;
			if (sum >= m) break;
		}
	}

	cout << ans;
}