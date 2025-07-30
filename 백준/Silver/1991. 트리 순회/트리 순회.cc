#include <iostream>

using namespace std;

int cti(char c) {
	return c - 'A' + 1;
}

int il[27][2];

void preorder(int idx) {
	cout << (char)('A' - 1 + idx);
	if (il[idx][0] > 1) preorder(il[idx][0]);
	if (il[idx][1] > 1) preorder(il[idx][1]);
	return;
}

void inorder(int idx) {
	if (il[idx][0] > 1) inorder(il[idx][0]);
	cout << (char)('A' - 1 + idx);
	if (il[idx][1] > 1) inorder(il[idx][1]);
	return;
}

void postorder(int idx) {
	if (il[idx][0] > 1) postorder(il[idx][0]);
	if (il[idx][1] > 1) postorder(il[idx][1]);
	cout << (char)('A' - 1 + idx);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		il[cti(a)][0] = cti(b);
		il[cti(a)][1] = cti(c);
	}

	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);

	return 0;
}