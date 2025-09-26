#include <bits/stdc++.h>
#include <deque>
using namespace std;

int M, N, K;
bool graph[100][100];
deque<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> sz;
int ans = 0;

void bfs(){
    int a = q.front().first;
    int b = q.front().second;
    q.pop_front();

    if (a + 1 < N && !graph[b][a + 1]){
        graph[b][a + 1] = true;
        q.push_back(pair<int, int>(a + 1, b));
    }
    if (b + 1 < M && !graph[b + 1][a]){
        graph[b + 1][a] = true;
        q.push_back(pair<int, int>(a, b + 1));
    }
    if (a - 1 >= 0 && !graph[b][a - 1]){
        graph[b][a - 1] = true;
        q.push_back(pair<int, int>(a - 1, b));
    }
    if (b - 1 >= 0 && !graph[b - 1][a]){
        graph[b - 1][a] = true;
        q.push_back(pair<int, int>(a, b - 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K;

    while (K--){
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        for (int y=y0; y<y1; y++){
            for (int x=x0; x<x1; x++){
                graph[y][x] = true;
            }
        }
    }

    for (int y=0; y<M; y++){
        for (int x=0; x<N; x++){
            if (graph[y][x]) continue;

            q.clear();

            graph[y][x] = true;
            q.push_back(pair<int, int>(x, y));

            int cnt = 0;
            while (!q.empty()) {
                bfs();
                cnt++;
            }

            sz.push(cnt);
            ans++;
        }
    }

    cout << ans << "\n";
    for (int i=0; i<ans; i++){
        cout << sz.top() << " ";
        sz.pop();
    }

    return 0;
}