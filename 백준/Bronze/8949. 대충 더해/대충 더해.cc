#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;
    int ans[7];

    int idx = 0;
    for (idx = 0; idx < 7; idx++){
        ans[idx] = A % 10 + B % 10;
        A /= 10;
        B /= 10;
        if (A == 0 && B == 0) break;
    }
    while (idx >= 0) cout << ans[idx--];

    return 0;
}