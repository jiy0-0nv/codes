#include <iostream>
#include <deque>

using namespace std;

int n, l;
int lst[5000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}

	deque<int> d;

	for (int i = 0; i < n; i++) {
		int ne = lst[i];

		while (!(d.empty())) {
			int ci = d.back();
			if (lst[ci] > lst[i]) d.pop_back();
			else break;
		}

		d.push_back(i); 

		if (d.front() == i - l) {
			d.pop_front();
		}

		cout << lst[d.front()] << " ";
	}

	return 0;
}