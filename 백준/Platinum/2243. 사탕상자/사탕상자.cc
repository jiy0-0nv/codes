#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#define ll long long
#define BASE 1048576 // 2^20=1,048,576

using namespace std;

int N;
ll segtree[2100000]; // 2^21=2,097,152

void update(int pos, int num){
    segtree[pos] += num;
    if (pos == 1) return;
    update(pos / 2, num);
}

int find(int node, int sum){
    if (node >= BASE)
        return node - BASE + 1;
    int left = node * 2;
    int right = node * 2 + 1;
    if (segtree[left] >= sum){ // **
        return find(left, sum);
    }
    else {
        return find(right, sum - segtree[left]); // **
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (N--){
        int a; cin >> a;
        if (a == 1){
            // 사탕상자에서 사탕을 꺼내는 경우
            int b; cin >> b;
            int candy = find(1, b);
            cout << candy << "\n";
            update(BASE + candy - 1, -1);
        }
        else if (a == 2){
            // 사탕을 넣는 경우
            int b, c; cin >> b >> c;
            update(BASE + b - 1, c);
        }
    }

    return 0;
}