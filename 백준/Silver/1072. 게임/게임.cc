#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long x, y;
	cin >> x >> y;

	long long z = (y * 100) / x;

	if (z == 99 || z == 100) {
		cout << -1;
		return 0;
	}

	if (((z + 1) * x - 100 * y) % (100 - z - 1) == 0)
		cout << ((z + 1) * x - 100 * y) / (100 - z - 1);
	else cout << ((z + 1) * x - 100 * y) / (100 - z - 1) + 1;
}