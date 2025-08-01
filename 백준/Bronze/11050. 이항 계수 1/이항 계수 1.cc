#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int ans = 1;

	for (int i = 0; i < k; i++) {
		ans *= (n - i);
		ans /= (i + 1);
	}

	cout << ans;

	return 0;
}