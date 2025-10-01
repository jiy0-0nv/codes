#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, J;
    cin >> N >> M >> J;

    int l = 1;
    int r = M;
    int ans = 0;

    while (J--){
        int p;
        cin >> p;

        if (l <= p && p <= r)
            continue;
        else if (l > p) {
            int d = l - p;
            l -= d;
            r -= d;
            ans += d;
        }
        else {
            int d = p - r;
            l += d;
            r += d;
            ans += d;
        }
    }

    cout << ans;

    return 0;
}