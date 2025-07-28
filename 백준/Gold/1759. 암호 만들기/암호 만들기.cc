#if 1
#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char chars[15];

int ans[15];
bool vst[15];

int aeiou(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	else
		return 0;
}

void bt(int d) {
	if (d == l) {
		int cnt = 0;
		for (int i = 0; i < l; i++) cnt += aeiou(chars[ans[i]]);
		if (cnt < 1 || l - cnt < 2) return;
		for (int i = 0; i < l;i++) cout << chars[ans[i]];
		cout << "\n";
		return;
	}
	for (int i = 0; i < c; i++) {
		if (vst[i]) continue;
		if (d > 0 && ans[d - 1] >= i) continue;
		ans[d] = i;
		vst[i] = true;
		bt(d + 1);
		vst[i] = false;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i<c; i++) {
		cin >> chars[i];
	}
	sort(chars, chars + c);

	bt(0);
	return 0;
}

#endif
