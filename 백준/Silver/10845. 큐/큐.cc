#if 1
#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;
string cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size") {
			if (q.empty()) cout << 0 << "\n";
			else cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << q.empty() << "\n";
		}
		else if (cmd == "front") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
			}
		}
	}

	return 0;
}
#endif