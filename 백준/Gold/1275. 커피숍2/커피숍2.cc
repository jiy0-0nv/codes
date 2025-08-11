#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

int N, Q;
ll tree[262150]; // 2^(17+1)=262144 // **뉴적이므로 long long
int base;

ll trsum(int cur, int cs, int ce, int ss, int se){
    if (ss <= cs && ce <= se) return tree[cur];
    else if (ss > ce || cs > se) return 0; // **
    else {
        int mid = (cs + ce) / 2; // **
        return trsum(cur * 2, cs, mid, ss, se) + trsum(cur * 2 + 1, mid + 1, ce, ss, se); // **
    }
}

void update(int pos, ll num){
    tree[pos] = num;
    if (pos == 1) return;
    int p = pos/2;
    update(p, tree[p*2] + tree[p*2+1]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    int h = (int)ceil(log2(N));
    base = 1 << h;
    // 리프 노드 채우기
    for (int i = 0; i < base; i++){
        if (i < N) cin >> tree[base + i];
        else tree[base + i] = 0;
    }
    // 트리 계산 (바텀업)
    for (int i = base - 1; i > 0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }

    while (Q--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << trsum(1, 1, base, x, y) << "\n";
        update(base + a - 1, b);
    }

    return 0;
}