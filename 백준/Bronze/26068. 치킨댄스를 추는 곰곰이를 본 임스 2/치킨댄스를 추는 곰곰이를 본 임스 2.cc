#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int ans = 0;

    while (N--){
        string x;
        cin >> x;
        if (x.length() <= 3) ans++;
        else if (x.length() >= 5) continue;
        else {
            if (x[2] == '9' && x[3] > '0') continue;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}