#include <bits/stdc++.h>
using namespace std;

int N;
int graph[64][64] = {};


void recur(int a, int b, int n){
    int t = graph[a][b];

    for (int i=a; i<a+n; i++){
        for (int j=b; j<b+n; j++){
            if (graph[i][j] != t){
                cout << "(";
                recur(a, b, n/2);
                recur(a, b+n/2, n/2);
                recur(a+n/2, b, n/2);
                recur(a+n/2, b+n/2, n/2);
                cout << ")";
                return;
            }
        }
    }

    cout << t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++){
        char line[65];
        cin >> line;
        for (int j=0; j<N; j++){
            graph[i][j] = line[j]-'0';
        }
    }

    recur(0, 0, N);

    return 0;
}