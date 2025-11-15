#include <bits/stdc++.h>
#include <queue>
using namespace std;

int N;
priority_queue<pair<int, int>> coos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (N--) {
        int x, y;
        cin >> x >> y;
        coos.push({-y, -x});
    }

    while (!coos.empty()){
        pair<int, int> tp;
        tp = coos.top();
        cout << -tp.second << " " << -tp.first << "\n";
        coos.pop();
    }

    return 0;
}