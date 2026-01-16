#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<int> E[100001];
vector<int> tree[100001];
int ans[100001];

void maketree(int root) {
    ans[root] = 1;
    for (int node : E[root]) {
        if (ans[node] == 0) {
            maketree(node);
            ans[root] += ans[node];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;
    for (int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    maketree(R);

    while (Q--) {
        int u;
        cin >> u;
        cout << ans[u] << "\n";
    }

    return 0;
}