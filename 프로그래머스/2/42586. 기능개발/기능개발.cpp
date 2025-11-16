#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int days[100] = {};
    
    for (int i = 0; i < progresses.size(); i++) {
        int prog = progresses[i];
        int speed = speeds[i];
    
        // 필요한 일수 계산
        int day = (100 - prog) / speed;
        if (prog + speed * day < 100) {
            day += 1;
        }
        // cout << "[DEBUG] " << day << "days\n";
        
        if (i > 0 && days[i - 1] >= day) {
            // 큐잉되는 경우
            days[i] = days[i - 1];
            answer[answer.size() - 1]++;
        }
        else {
            days[i] = day;
            answer.insert(answer.end(), 1);
        }
    }
    
    return answer;
}