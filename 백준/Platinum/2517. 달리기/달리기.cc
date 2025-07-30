#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int n;
pair<int, int> arr[500000];

int sz;
int base = 1;
int segtree[1048576];

int ans[500000];

void update1(int idx) {
	int node = base + idx;
	segtree[node] = 1;
	while (node > 1) {
		node /= 2;
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
	return;
}

int trsum(int node, int nodeStart, int nodeEnd, int sumStart, int sumEnd) {
	if (nodeStart >= sumStart && nodeEnd <= sumEnd) return segtree[node];
	else if (nodeStart > sumEnd || nodeEnd < sumStart) return 0;
	else {
		int mid = (nodeStart + nodeEnd) / 2;
		return trsum(node * 2, nodeStart, mid, sumStart, sumEnd) + trsum(node * 2 + 1, mid + 1, nodeEnd, sumStart, sumEnd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
    while (base < n) base <<= 1;
    sz = base << 1;
	
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[i] = { t, i };
	}

	sort(arr, arr + n, greater<pair<int, int>>());

	for (int i = 0; i < n; i++) {
        ans[arr[i].second] = trsum(1, 0, base - 1, 0, arr[i].second) + 1;
        update1(arr[i].second);
	}

    for (int i = 0; i < n; i++) cout << ans[i] << "\n";

	return 0;
}