#include <bits/stdc++.h>
using namespace std;

int N, M;
int root[500000];

int find(int x) {
    if (x == root[x]) return x;
    else {
        return root[x] = find(root[x]);
    }
}

void uni(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        root[rx] = ry;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        root[i] = i;
    }

    int res = 0;

    for (int t=1; t<=M; t++) {
        int a, b;
        cin >> a >> b;
        if (res > 0) continue;
        
        if (find(a) == find(b)) {
            res = t;
        }
        else {
            uni(a, b);
        }
    }

    cout << res;
    return 0;
}