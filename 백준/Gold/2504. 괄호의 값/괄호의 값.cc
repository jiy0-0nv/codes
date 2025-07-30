#if 1
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

string s;
stack<int> st;

long ans = 0;
int s2 = 0, s3 = 0;

bool update = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	for (char c : s) {
		if (c == '(') {
			st.push(2);
			s2++;
			update = true;
		}
		else if (c == '[') {
			st.push(3);
			s3++;
			update = true;
		}
		else if (c == ')') {
			if (st.empty() || st.top() != 2) {
				cout << 0; return 0;
			}
			st.pop();
			if (update) ans += pow(2, s2) * pow(3, s3);
			s2--;
			update = false;
		}
		else if (c == ']') {
			if (st.empty() || st.top() != 3) {
				cout << 0; return 0;
			}
			st.pop();
			if (update) ans += pow(2, s2) * pow(3, s3);
			s3--;
			update = false;
		}
	}

	if (st.empty()) cout << ans;
	else cout << 0;

	return 0;
}
#endif