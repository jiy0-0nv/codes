#include <string>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int solution(vector<vector<int>> jobs) {    
    vector<pair<int, int>> reqt[1001] = {}; // 각 시점에 요청된 (소요시간, 작업번호) 집합
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh; // (소요시간, 요청시간, 작업번호)
    
    for (int i=0; i<jobs.size(); i++) {
        int s = jobs[i][0];
        int l = jobs[i][1];
        reqt[s].push_back({l, i});
    }
    
    ll sum_tt = 0;
    int n_j = jobs.size();
    int rem_t = 0;
    
    for (int t = 0; t<=1000 || !minh.empty(); t++) {
        // 남은 작업 시간 감소
        if (rem_t > 0) rem_t--;
        
        // 요청이 들어온 작업을 대기 큐에 저장
        if (t<=1000 && !reqt[t].empty()) {
            for (pair<int, int> req : reqt[t]) {
                minh.push({req.first, t, req.second});
            }
        }
        
        // (실행중인 작업이 없을 경우) 우선순위가 높은 작업을 대기 큐에서 꺼내 실행
        if (rem_t > 0 || minh.empty()) continue;
        
        vector<int> task = minh.top();
        minh.pop();
        
        sum_tt += (t+task[0]-task[1]);
        rem_t = task[0];
    }
    
    int answer = (int)(sum_tt / n_j);
    return answer;
}