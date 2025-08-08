#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct n_t {
	int val, index;
	inline bool operator<(const n_t &ref) const {
		return this->val < ref.val;
	}
};

int N;
n_t ilst[1000001];
n_t nlst[1000001];
int cnt = 1;
int ans[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> ilst[i].val;
	}

	nlst[0] = {INT_MIN, 0};
	for (int i = 1; i <= N; i++) {
		n_t key = { ilst[i].val, i };
		n_t *pos = lower_bound(nlst, nlst + cnt, key);
		*pos = key;

		ilst[i].index = pos[-1].index;
		if (pos - nlst == cnt) cnt++;
	}
	cout << --cnt << "\n";
	
	// 역추적
	int curidx = nlst[cnt].index;
	for (int j = cnt; j > 0; j--) {
		ans[j] = ilst[curidx].val;
		curidx = ilst[curidx].index;
	}

	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}