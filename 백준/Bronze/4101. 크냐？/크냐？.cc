#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (a > b) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}