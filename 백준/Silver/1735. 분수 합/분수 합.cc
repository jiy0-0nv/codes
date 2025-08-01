#if 1
#include <iostream>

using namespace std;

int xa, xb, ya, yb;
long za, zb;

int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> xa >> xb >> ya >> yb;

	int xd = gcd(xa, xb);
	xa /= xd;
	xb /= xd;

	int yd = gcd(ya, yb);
	ya /= yd;
	yb /= yd;

	za = xa * yb + ya * xb;
	zb = xb * yb;
	
	int zd = gcd(za, zb);
	za /= zd;
	zb /= zd;

	cout << za << " " << zb;

	return 0;
}
#endif