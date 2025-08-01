#if 1
#include <iostream>

using namespace std;

long long n, p, k;

int vst[21];

long long fac(long long x) {
	if (x == 0) return 1;
	long long ret = 1;
	while (x) {
		ret *= x;
		if (x == 1) break;
		x--;
	}
	return ret;
}

void find() {
	k -= 1;
	long long f;
	for (int t = n - 1; t >= 0; t--) {
		f = fac(t);
		int a = k / f;
		for (int i = 1; i <= n; i++) {
			if (vst[i]) continue;
			else a--;
			if (a < 0) {
				cout << i << " ";
				vst[i] = true;
				break;
			}
		}
		k %= f;
	}
	return;
}

void problem1() {
	cin >> k;
	find();
	return;
}

void problem2() {
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> k;
		vst[k] = true;
		// k의 등수 계산 (자기 앞에 몇 개 있는지)
		int r = 0;
		for (int j = 1; j < k; j++) {
			if (!(vst[j])) r++;
		}
		ans += fac(n - i - 1) * r;
	}
	cout << ans;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p;

	if (p == 1) problem1();
	else problem2();

	return 0;
}
#endif