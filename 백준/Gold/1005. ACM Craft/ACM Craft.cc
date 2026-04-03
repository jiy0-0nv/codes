#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> N >> K;

        vector<int> dvec(N+1);
        vector<vector<int>> dag(N+1);
        vector<int> indeg(N+1);

        for (int i=1; i<=N; i++)
            cin >> dvec[i];
        while (K--) {
            int x, y;
            cin >> x >> y;
            dag[x].push_back(y);
            indeg[y]++;
        }

        vector<int> psum(N+1);
        queue<int> nq;
        
        for (int i=1; i<=N; i++) {
            if (indeg[i] == 0) {
                nq.push(i);
                psum[i] = dvec[i];
            }
        }
        
        while (!nq.empty()) {
            int i = nq.front();
            nq.pop();

            for (int ni : dag[i]) {
                psum[ni] = max(psum[ni], psum[i] + dvec[ni]);
                indeg[ni]--;
                if (indeg[ni] == 0)
                    nq.push(ni);
            }
        }
        
        int w;
        cin >> w;
        cout << psum[w] << "\n"; 
    }

    return 0;
}