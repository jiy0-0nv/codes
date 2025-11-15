#include <bits/stdc++.h>
#include <deque>
using namespace std;

int N, M;
int board[101] = {0, };
bool vst[101] = {true, true, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    while (N--){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    while (M--){
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    // bfs
    deque<pair<int, int>> q;
    q.push_back({1, 0});

    while (!q.empty()){
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop_front();

        // 종료 조건
        if (pos >= 94){
            cout << cnt + 1;
            break;
        }

        for (int i = 1; i<=6; i++){
            if (board[pos + i] == 0 && !vst[pos+i]){
                q.push_back({pos+i, cnt+1});
                vst[pos+i] = true;
            }
            else if (!vst[board[pos+i]]){
                q.push_back({board[pos+i], cnt+1});
                vst[board[pos+i]] = true;
            }
        }
    }

    return 0;
}