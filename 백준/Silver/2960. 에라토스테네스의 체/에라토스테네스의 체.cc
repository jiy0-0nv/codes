#if 1
#include <iostream>

using namespace std;

int n, k;
bool arr[1001];
int p = 2;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	while (k) {
		int mn;
		for (int i = p; i <= n; i++) {
			if (!arr[i]) {
				mn = i;
				break;
			}
		}
		p = mn + 1;
		for (int i = mn; i <= n && k > 0; i+=mn) {
			if (!arr[i]) {
				arr[i] = true;
				ans = i;
				k--;
			}
		}
	}

	cout << ans;

	return 0;
}
#endif