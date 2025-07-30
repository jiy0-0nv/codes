#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	int nlst[100000];
	for (int i = 0; i < n; i++) cin >> nlst[i];

	int ans = n + 1;

	int l = 0, r = 0;
	int sum = nlst[0];
	while (r < n) {
        if (sum >= s) {
            if (ans > r - l + 1) ans = r - l + 1;
            sum -= nlst[l++];
        }
        else {
            if (r == n - 1) break;
            sum += nlst[++r];
        }
	}

	if (ans == n + 1) cout << 0;
	else cout << ans;
	
	return 0;
}