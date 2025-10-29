#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x; cin >> x;
    int ans = 1;
    int l = 64;

    while (l > x){
        if ((l >> 1) < x){
            x -= (l >> 1);
            ans += 1;
        }
        l >>= 1;
    }
    cout << ans;

    return 0;
}