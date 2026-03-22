#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n;
        int m;

        cin >> n;
        double money;
        cin >> money;
        m = round(money * 100);

        if (n == 0 && m == 0.0) break;

        int dp[10001] = {};

        for (int i=0; i<n; i++) {
            int c;
            double p;
            cin >> c >> p;
            int pint = round(p * 100);

            for (int j=pint; j<=m; j++) {
                dp[j] = max(dp[j - pint] + c, dp[j]);
            }
        }

        cout << dp[m] << "\n";
    }

    return 0;
}