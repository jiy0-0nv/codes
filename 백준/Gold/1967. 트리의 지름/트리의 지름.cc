#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;

// 인접 리스트
vector<vector<pair<int, int>>> tree;

bool vst[10001];

void dfs(int node, int d) {
    if (d > 0 && tree[node].size() == 1) {
        ans = max(ans, d);
        return;
    }

    for (auto e : tree[node]) {
        if (!vst[e.first]) {
            vst[e.first] = true;
            dfs(e.first, d + e.second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.resize(n + 1);

    for (int i=1; i<n; i++) {
        int p, c, d;
        cin >> p >> c >> d;

        tree[p].push_back({c, d});
        tree[c].push_back({p, d});
    }

    for (int i = 1; i <= n; i++) {
        if (tree[i].size() == 1) {
            fill(vst, vst+(n+1), false);
            vst[i] = true;
            dfs(i, 0);
        }
    }

    cout << ans;

    return 0;
}