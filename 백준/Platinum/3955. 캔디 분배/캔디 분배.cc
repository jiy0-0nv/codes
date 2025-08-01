#if 1
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
int t;
ll k, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> k >> c;

		if (k == 1000000000) {
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}
		else if (c == 1) {
			cout << k + 1 << "\n";
			continue;
		}
		else if (k == 1) {
			cout << 1 << "\n";
			continue;
		}

		ll s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = c, r1 = k;
		ll q;

		while (1) {
			if (r1 == 0) {
				cout << "IMPOSSIBLE" << "\n";
				break;
			}
			if (r1 == 1) {
				if (s1 > 1000000000) cout << "IMPOSSIBLE" << "\n";
				if (s1 < 0) s1 += k;
				cout << s1 << "\n";
				break;
			}

			q = r0 / r1;
			r0 -= q * r1;
			s0 -= q * s1;
			t0 -= q * t1;
			
			swap(r0, r1);
			swap(s0, s1);
			swap(t0, t1);
		}
	}
	return 0;
}
#endif