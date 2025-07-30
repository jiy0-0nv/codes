#if 1
#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[5000000];

int sz;
int segtree[500000 * 4];

/*
void update(int idx, int value) {
	int node = arr[idx];
	segtree[node] = value;
	while (node > 1) {
		node /= 2;
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
	//cout << "\n";
	//for (int i = 0; i < sz; i++) cout << segtree[i] << " ";
	//cout << "\n";
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
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	sz = 1 << ((int)ceil(log2(n)) + 1);
	
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[i] = { t, i };
	}
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}
#endif
