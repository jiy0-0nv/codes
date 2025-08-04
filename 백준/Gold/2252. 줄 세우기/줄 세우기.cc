#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;

vector<int> AdjacentList[32001];
int d[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int a, b;

	while (m--) {
		cin >> a >> b;
		AdjacentList[a].push_back(b);
		d[b] += 1;
	}

	deque<int> q;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		if (!d[i]) q.push_back(i);
	}

	while (!q.empty())
	{
		int t = q.front();
		q.pop_front();
		ans.push_back(t);

		for (int next : AdjacentList[t]) {
			d[next] -= 1;
			if (!d[next]) q.push_back(next);
		}
	}

	for (int s : ans) cout << s << " ";

	return 0;
}