#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nlst[1000001];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> nlst[cnt++];

	for (int i = 1; i < N; i++) {
		int t;
		cin >> t;
		if (t > nlst[cnt - 1]) nlst[cnt++] = t;
		else nlst[lower_bound(nlst, nlst + cnt, t) - nlst] = t;
	}
	cout << cnt;

	return 0;
}