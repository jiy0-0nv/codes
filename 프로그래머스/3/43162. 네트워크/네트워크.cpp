#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    queue<int> q;
    vector<bool> vst(n, false);
    
    for (int i=0; i<n; i++) {
        if (vst[i]) continue;
        
        q.push(i);
        vst[i] = true;
        answer++;
        
        // bfs
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            
            for (int nc = 0; nc < n; nc++) {
                if (computers[c][nc] == 0 || vst[nc]) continue;
                q.push(nc);
                vst[nc] = true;
            }
        }
    }
    
    return answer;
}