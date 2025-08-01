#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (cin >> n) {
		int ans = 1;
		int t = 1;

		while (t % n > 0) {
			t = (t % n) * 10 + 1;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
