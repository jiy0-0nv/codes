#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int X;
        cin >> X;

        bool app[10] = {};
        int bs = 0;

        while (X > 0) {
            int t = X % 10;
            if (!app[t]){
                app[t] = true;
                bs++;
            }

            X /= 10;
        }

        cout << bs << "\n";
    }

    return 0;
}