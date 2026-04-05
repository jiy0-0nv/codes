#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    int N = operations.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    priority_queue<pair<int, int>> maxh;
    vector<bool> avail(N, false);
    
    for (int i=0; i<N; i++) {
        stringstream cmd(operations[i]);
        char a;
        int b;
        cmd >> a >> b;
        
        if (a == 'I') {
            minh.push({b, i});
            maxh.push({b, i});
            avail[i] = true;
        }
        else if (b == 1) {
            if (maxh.empty()) continue;
            pair<int, int> t = maxh.top();
            maxh.pop();
            while (!avail[t.second]) {
                if (maxh.empty()) break;
                t = maxh.top();
                maxh.pop();
            }
            avail[t.second] = false;
        }
        else {
            if (minh.empty()) continue;
            pair<int, int> t = minh.top();
            minh.pop();
            while (!avail[t.second]) {
                if (minh.empty()) break;
                t = minh.top();
                minh.pop();
            }
            avail[t.second] = false;
        }
    }
    
    vector<int> answer = {0, 0};
    
    while (!maxh.empty()) {
        if (avail[maxh.top().second]) {
            answer[0] = maxh.top().first;
            break;
        }
        maxh.pop();
    }
    
    while (!minh.empty()) {
        if (avail[minh.top().second]) {
            answer[1] = minh.top().first;
            break;
        }
        minh.pop();
    }
    
    return answer;
}