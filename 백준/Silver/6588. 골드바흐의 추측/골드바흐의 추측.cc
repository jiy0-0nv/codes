#if 1
#include <iostream>

using namespace std;

int notPrime[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i < 1001; i++) {
		if (notPrime[i] == false) {
			for (int j = i * 2; j < 1000001; j += i) {
				notPrime[j] = true;
			}
		}
	}

	int n;
	while (cin >> n) {
		int i = 3;
		for (; i <= n / 2; i += 2) {
			if (notPrime[i] == false && notPrime[n - i] == false) {
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
			if (i > n / 2) {
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
		}
	}

	return 0;
}
#endif