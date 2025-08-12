#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int>> graph[100000];
int depth[100000];
int mxd = 0;
int ld;
pair<int, pair<int, int>> parent[18][100000];

bool vst[100000];

// 부모[0], 깊이 찾기
void dfs(int node){
    for (pair<int, int> v : graph[node]){
        int child = v.first;
        if (vst[child]) continue;
        
        int road = v.second;

        vst[child] = true;
        depth[child] = depth[node] + 1;
        parent[0][child] = {node, {road, road}};

        dfs(child);
    }

    mxd = max(mxd, depth[node]);
}

// 희소 배열 채우기: 부모[1~N-1]
void sparse(){
    for (int i = 1; i <= ld; i++){
        for (int j = 2; j <= N; j++){
            int p0 = parent[i - 1][j].first;
            int mn = min(parent[i - 1][j].second.first, parent[i - 1][p0].second.first);
            int mx = max(parent[i - 1][j].second.second, parent[i - 1][p0].second.second);
            parent[i][j] = {parent[i - 1][p0].first, {mn, mx}};
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vst[1] = true;
    depth[1] = 0;
    parent[0][1] = {0, {0, 0}};
    dfs(1);
    ld = (int)ceil(log2(mxd));
    sparse();

    cin >> K;
    while (K--){
        int d, e; cin >> d >> e;
        if (depth[d] > depth[e]) swap(d, e);

        int mn = 1000000;
        int mx = 0;

        // e를 d까지 올리자
        int sb = depth[e] - depth[d];
        int exp = 0;
        while (sb > 0) {
            if ((sb & 1) == 1){ // 가장 작은 비트가 1 -> 2^exp 부모로 올림
                mn = min(parent[exp][e].second.first, mn);
                mx = max(parent[exp][e].second.second, mx);
                e = parent[exp][e].first;
            }
            sb >>= 1;
            exp++;
        }

        // 두 노드가 같으면 끝
        if (d == e){
            cout << mn << " " << mx << "\n";
            continue;
        }

        // 다르면 같이 올려줘야 함
        for (int i = ld; i >= 0; i--){
            if (parent[i][d].first != parent[i][e].first){
                mn = min(mn, parent[i][d].second.first);
                mx = max(mx, parent[i][d].second.second);
                d = parent[i][d].first;
                mn = min(mn, parent[i][e].second.first);
                mx = max(mx, parent[i][e].second.second);
                e = parent[i][e].first;
            }
        }
        
        mn = min(mn, parent[0][d].second.first);
        mx = max(mx, parent[0][d].second.second);
        mn = min(mn, parent[0][e].second.first);
        mx = max(mx, parent[0][e].second.second);
        cout << mn << " " << mx << "\n";
    }

    return 0;
} 