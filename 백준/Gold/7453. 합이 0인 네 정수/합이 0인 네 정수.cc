#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll lst1[4000];
ll lst2[4000];
ll lst3[4000];
ll lst4[4000];
ll ab[16000000];
ll cd[16000000];
int n;
ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lst1[i];
		cin >> lst2[i];
		cin >> lst3[i];
		cin >> lst4[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[n * i + j] = lst1[i] + lst2[j];
			cd[n * i + j] = lst3[i] + lst4[j];
		}
	}

	sort(ab, ab + n * n);
	sort(cd, cd + n * n);

	for (int i = 0; i < n * n; i++) {
		ll t = ab[i];
		int l = lower_bound(cd, cd + n * n, -t) - cd;
		int u = upper_bound(cd, cd + n * n, -t) - cd;
		ans += u - l;
	}
	cout << ans;
	return 0;
}