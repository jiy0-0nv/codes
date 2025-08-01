#if 1
#include <iostream>
#include <algorithm>

using namespace std;

int t;

int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;

		int nl[100];

		for (int i = 0; i < n; i++) {
			cin >> nl[i];
		}

		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = nl[i], b = nl[j];
				ans += gcd(a, b);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
#endif