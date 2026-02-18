#include <bits/stdc++.h>
using namespace std;

int N;
deque<pair<int, int>> dq = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=1; i<=N; i++) {
        int n;
        cin >> n;
        dq.push_back({i, n});
    }

    while (!dq.empty()) {
        int b = dq.front().first;
        int p = dq.front().second;
        cout << b << " ";
        
        dq.pop_front();
        if (dq.empty()) break;

        if (p > 0) {
            while (--p) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while (p++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}