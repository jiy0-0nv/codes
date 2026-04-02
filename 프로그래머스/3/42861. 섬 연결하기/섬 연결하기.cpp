#include <string>
#include <vector>
#include <queue>

using namespace std;
using Edge = pair<int, pair<int, int>>;

// union-find
int find(vector<int>& roots, int node) {
    if (roots[node]==node) return node;
    else return roots[node] = find(roots, roots[node]);
}
void join(vector<int>& roots, int a, int b) {
    int ra = find(roots, a);
    int rb = find(roots, b);
    if (ra == rb) return;
    roots[ra] = rb;
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> roots(n);
    for (int i=0; i<n; i++) roots[i] = i; // 자기 자신을 root로 초기화
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> minh;
    
    for (vector<int> cost : costs) {
        minh.push({cost[2], {cost[0], cost[1]}});
    }
    
    int answer = 0;
    
    while (!minh.empty()) {
        Edge e = minh.top();
        minh.pop();
        int n1 = e.second.first;
        int n2 = e.second.second;
        
        // 이미 연결됨
        if (find(roots, n1) == find(roots, n2)) continue;
        
        // 새로 연결
        join(roots, n1, n2);
        answer += e.first;
    }
    
    return answer;
}