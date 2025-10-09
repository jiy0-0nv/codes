#include <bits/stdc++.h>
using namespace std;

int N;
int bombmap[1000][1000];

auto DIR = vector<vector<int>>{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++){
        string line;
        cin >> line;
        for (int j=0; j<N; j++){
            if (line[j] != '.'){
                int n = line[j] - '0';
                bombmap[i][j] = -1;
                for (auto d : DIR){
                    if (i + d[0] >= 0 && i + d[0] < N && j + d[1] >= 0 && j + d[1] < N && bombmap[i + d[0]][j + d[1]] != -1){
                        bombmap[i + d[0]][j + d[1]] += n;
                    }
                }
            }
        }
    }

    for (int r=0; r<N; r++){
        for (int c=0; c<N; c++){
            if (bombmap[r][c] == -1) cout << '*';
            else if (bombmap[r][c] > 9) cout << 'M';
            else cout << bombmap[r][c];
        }
        cout << "\n";
    }

    return 0;
}