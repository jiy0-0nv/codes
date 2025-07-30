#if 1 
#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> mxq; // 최대힙
priority_queue<int, vector<int>, greater<int>> mnq; // 최소힙

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;

		if (i % 2 == 1) {
			mxq.push(t);
		}
		else {
			mnq.push(t);
		}

		if (i > 1) {
			int x = mxq.top();
			int y = mnq.top();
			if (x > y) {
				mxq.pop();
				mnq.pop();
				mxq.push(y);
				mnq.push(x);
			}
		}

		cout << mxq.top() << "\n";
	}

	return 0;
}
#endif