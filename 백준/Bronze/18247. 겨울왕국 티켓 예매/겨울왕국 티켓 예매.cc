#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--){
        int N, M;
        cin >> N >> M;

        if (M < 4 || N < 12){
            cout << "-1\n";
        }
        else {
            cout << 11 * M + 4 << "\n";
        }
    }

    return 0;
}