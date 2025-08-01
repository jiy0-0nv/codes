#if 1
#include <iostream>
#define ll long long

using namespace std;

int n;

ll nl[1000000];
ll lgcd[1000000];
ll rgcd[1000000];

ll gcd(ll a, ll b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b; 
}

ll ans = -1;
ll ansn = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nl[i];
		if (i == 0) lgcd[i] = nl[i];
		else lgcd[i] = gcd(lgcd[i - 1], nl[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) rgcd[i] = nl[i];
		else rgcd[i] = gcd(rgcd[i + 1], nl[i]);
	}

	for (int i = 0; i < n; i++) {
		ll tgcd;
		if (i == 0) tgcd = rgcd[1];
		else if (i == n - 1) tgcd = lgcd[n - 2];
		else tgcd = gcd(lgcd[i - 1], rgcd[i + 1]);

		if (nl[i] % tgcd != 0 && ans < tgcd) {
			ans = tgcd;
			ansn = nl[i];
		}
	}

	cout << ans;
	if (ansn > 0) cout << " " << ansn;

	return 0;
}
#endif