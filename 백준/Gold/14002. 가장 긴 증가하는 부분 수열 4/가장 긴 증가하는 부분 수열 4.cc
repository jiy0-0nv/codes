#include <iostream>

using namespace std;

int N;
int nlst[1001] = { 0, }; // 1~
int dp[1001] = {0, 1, };
int pv[1001] = {};
int ansidx = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nlst[i];
		for (int j = 0; j < i; j++) {
			if (nlst[j] < nlst[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				pv[i] = j;
			}
		}
		if (dp[i] > dp[ansidx]) {
			ansidx = i;
		}
	}
	cout << dp[ansidx] << "\n";

	int ans[1001];
	int t = ansidx;
	for (int i = dp[ansidx]; i > 0; i--) {
		ans[i] = nlst[t];
		t = pv[t];
	}
	for (int i = 1; i <= dp[ansidx]; i++) cout << ans[i] << " ";

	return 0;
}