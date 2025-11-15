#include <bits/stdc++.h>
using namespace std;

int N;
int graph[101][101];

int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int a, int b, int color){
    for (auto d:DIR){
        int na = a+d[0];
        int nb = b+d[1];
        if (na>=0 && na<N && nb>=0 && nb<=N && graph[na][nb] == color){
            graph[na][nb] = (graph[na][nb] == 3) ? 5 : 4;
            if (color > 3) graph[na][nb] = 0;
            dfs(na, nb, color);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++){
        string row;
        cin >> row;
        for (int j=0; j<N; j++){
            if (row[j] == 'R') graph[i][j] = 1;
            else if (row[j] == 'G') graph[i][j] = 2;
            else graph[i][j] = 3;
        }
    }

    int ans = 0; 

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (graph[i][j] < 4){
                int c = graph[i][j];
                if (c==0){
                    return 1;
                }
                ans++;
                graph[i][j] = (c == 3) ? 5 : 4;
                dfs(i, j, c);
            }
        }
    }
    cout << ans << " ";

    ans = 0;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (graph[i][j]){
                int c = graph[i][j];
                ans++;
                graph[i][j] = 0;
                dfs(i, j, c);
            }
        }
    }
    cout << ans;

    return 0;
}