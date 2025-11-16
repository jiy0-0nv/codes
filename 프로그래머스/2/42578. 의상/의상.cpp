#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<string> v_1, vector<string> v_2) {
    return v_1[1] > v_2[1];
}

int solution(vector<vector<string>> clothes) {
    sort(clothes.begin(), clothes.end(), cmp);
    
    int idx = 1;
    int count = 1;
    int answer = 1;
    while (idx < clothes.size()) {
        if (clothes[idx][1] == clothes[idx - 1][1]) {
            count++;
        }
        else {
            answer *= (count + 1);
            count = 1;
        }
        idx++;
    }
    
    answer *= (count + 1);
    answer--;
    return answer;
}