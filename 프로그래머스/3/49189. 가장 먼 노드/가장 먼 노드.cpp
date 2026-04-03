#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {    
    vector<vector<int>> graph(n + 1);
    
    for (vector<int> e : edge) {
        int a = e[0];
        int b = e[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    vector<int> vst(n + 1, false);
    vector<int> ans(n + 1, 0);
    
    q.push(1);
    vst[1] = true;
    ans[1] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int nn : graph[node]) {
            if (vst[nn]) continue;
            
            q.push(nn);
            vst[nn] = true;
            ans[nn] = ans[node] + 1;
        }
    }
    
    int maxl = *max_element(ans.begin(), ans.end());
    int answer = count(ans.begin(), ans.end(), maxl);
    
    return answer;
}