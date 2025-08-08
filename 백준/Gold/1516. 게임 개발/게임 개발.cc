#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n;
int time[501];
vector<int> graph[501];
int d[501];
deque<int> q = {};
int tsum[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		time[i] = t;

		bool first = true;
		cin >> t;
		while (t != -1) {
			graph[t].push_back(i);
			d[i]++;
			if (first) first = false;
			cin >> t;
		}
		if (first) {
			q.push_back(i);
			tsum[i] = time[i];
		}
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop_front();
		for (int s : graph[t]) {
			if (tsum[s] < tsum[t] + time[s]) tsum[s] = tsum[t] + time[s];
			d[s]--;
			if (d[s] == 0) q.push_back(s);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << tsum[i] << "\n";
	}

	return 0;
}