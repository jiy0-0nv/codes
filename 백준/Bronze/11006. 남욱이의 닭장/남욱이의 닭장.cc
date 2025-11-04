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
        cout << M * 2 - N << " " << N - M << "\n";
    }

    return 0;
}