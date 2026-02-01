#include <bits/stdc++.h>
using namespace std;

int V, E;
int root[10001]; // 각 노드의 부모

// Union-Find
int find(int k) {
    if (!root[k]) return k;
    else return root[k] = find(root[k]);
}
void join(int a, int b) {
    int x = find(a);
    int y = find(b);
    root[y] = x;
}

struct edge_t {
    int a, b, cost;
    // 비교 연산자 오버로딩
    inline bool operator<(const edge_t &ref) const {
        return this->cost < ref.cost;
    }
} Edge[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> Edge[i].a >> Edge[i].b >> Edge[i].cost;
    }
    sort(Edge, Edge+E);

    int cnt = 0; // 연결된 간선 수 (최대 V-1개)
    int sum = 0;

    for (int i=0; i<E && cnt<V-1; i++) {
        if (find(Edge[i].a) != find(Edge[i].b)) {
            join(Edge[i].a, Edge[i].b);
            cnt++;
            sum += Edge[i].cost;
        }
    }

    cout << sum;

    return 0;
}