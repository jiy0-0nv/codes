#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    for (int j = 0; j < N; j++){
        for (int i = 0; i < j; i++) cout << " ";
        for (int i = 0; i < 2 * N - 1 - j * 2; i++) cout << "*";
        cout << "\n";
    }

    return 0;
}