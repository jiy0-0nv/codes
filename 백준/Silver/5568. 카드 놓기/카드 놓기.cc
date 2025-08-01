#if 1
#include <iostream>

using namespace std;

bool app[100000000]; //0~99,999,999
int cards[10];
int n, k;
int ans = 0;

bool vst[10];
int pick[4];
int cnt = 0;
void bt(int t) {
	if (t == k) {
		int sum = 0;
		int d = 1;
		for (int i = 0; i < cnt; i++) {
			sum += d * pick[i];
			if (pick[i] < 10) d *= 10;
			else d *= 100;
		}
		
		if (!(app[sum])) {
			app[sum] = true;
			ans++;
		}

		return;
	}

	for (int i = 0; i < n; i++) {
		if (vst[i]) continue;
		else {
			vst[i] = true;
			pick[cnt++] = cards[i];
			bt(t + 1);
			cnt--;
			vst[i] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> cards[i];

	bt(0);
	cout << ans;

	return 0;
}
#endif