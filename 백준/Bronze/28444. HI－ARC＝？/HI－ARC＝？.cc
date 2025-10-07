#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, I, A, R, C;
    cin >> H >> I >> A >> R >> C;
    cout << H * I - A * R * C;

    return 0;
}