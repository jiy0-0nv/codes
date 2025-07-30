#if 1
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
pair<int, int> jws[300000];
int bags[300000];
priority_queue<int> vq;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> jws[i].first >> jws[i].second;
	for (int i = 0; i < k; i++) cin >> bags[i];
	sort(jws, jws + n);
	sort(bags, bags + k);

	int ji = 0;
	for (int i = 0; i < k; i++) {
		while (ji < n && jws[ji].first <= bags[i]) vq.push(jws[ji++].second);
		if (vq.empty()) continue;
		ans += vq.top();
		vq.pop();
	}
	
	cout << ans;

	return 0;
}
#endif