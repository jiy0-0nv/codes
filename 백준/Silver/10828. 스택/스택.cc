#if 1
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st;
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
			st.push(x);
		}
		else if (cmd == "pop") {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (cmd == "size") {
			if (st.empty()) cout << 0 << "\n";
			else cout << st.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << st.empty() << "\n";
		}
		else {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
			}
		}
	}

	return 0;
}
#endif