#if 01
#include <iostream>

using namespace std;

int N, M;
long long sum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}

	return 0;
}
#endif