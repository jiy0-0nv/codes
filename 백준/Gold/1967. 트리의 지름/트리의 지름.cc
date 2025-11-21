#include <bits/stdc++.h>
using namespace std;

int n;
int mxnod = 1;
int mxdst = 0;

// 인접 리스트
vector<vector<pair<int, int>>> tree;

bool vst[10001];

void dfs(int node, int d) {
    if (mxdst < d) {
        mxdst = d;
        mxnod = node;
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

    vst[1] = true;
    dfs(1, 0);

    fill(vst, vst+(n+1), false);

    vst[mxnod] = true;
    dfs(mxnod, 0);

    cout << mxdst;

    return 0;
}