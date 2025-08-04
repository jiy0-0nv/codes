#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<int> graph[501];
vector<int> graph_reverse[501];

int bfs(int x) {
	int ret = 1;

	bool vst[501] = {};
	vst[x] = true;
	deque<int> q = { x };
	while (!q.empty()) {
		int t = q.front();
		q.pop_front();
		for (int s : graph[t]) {
				if (!vst[s]) {
					vst[s] = true;
					q.push_back(s);
					ret++;
			}
		}
	}
	q.push_back(x);
	while (!q.empty()) {
		int t = q.front();
		q.pop_front();
		for (int s : graph_reverse[t]) {
			if (!vst[s]) {
				vst[s] = true;
				q.push_back(s);
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph_reverse[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (bfs(i) == n) ans += 1;
	}

	cout << ans;

	return 0;
}
