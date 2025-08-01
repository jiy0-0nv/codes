#if 1
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int see[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	see[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		see[i] = see[i - 1] + 2;
		for (int j = 2; j <= i; j++) {
			if (gcd(i, j) == 1) see[i] += 2;
		}
	}


	while (c--) {
		int n;
		cin >> n;
		cout << see[n] << "\n";
	}

	return 0;
}
#endif