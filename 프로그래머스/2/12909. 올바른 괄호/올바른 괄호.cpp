#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt = 0;
    
    for (char c : s) {
        if (c == '(') {
            cnt++;
        }
        else if (cnt > 0) {
            cnt--;
        }
        else {
            return false;
        }
    }
    
    if (cnt > 0)
        answer = false;

    return answer;
}