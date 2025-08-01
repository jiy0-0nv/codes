#if 1
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

ll gcd(ll x, ll y) {
	while (x) {
		y %= x;
		swap(x, y);
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string n;
		cin >> n;

		ll a = 0;
		int an = 0;
		int cn = 0;

		bool cc = false;

		for (int i = 2; i < n.length(); i++) {
			char c = n[i];
			if (c == '(') cc = true;
			else if (c == ')') break;
			else {
				a *= 10;
				a += (c - '0');
				if (cc) cn++;
				an++;
			}
		}

		ll b = pow(10, an);
		if (cn > 0) {
			b -= pow(10, an - cn);
			a -= a / (int)(pow(10, cn));
		}
		
		ll c = gcd(a, b);

		cout << a / c << "/" << b / c << "\n";
	}

	return 0;
}
#endif