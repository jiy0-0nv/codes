#if 1
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> mnh;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (mnh.empty()) cout << 0 << "\n";
			else {
				cout << mnh.top() << "\n";
				mnh.pop();
			}
		}
		else {
			mnh.push(x);
		}
	}

	return 0;
}
#endif