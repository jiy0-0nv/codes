#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    return str_a + str_b > str_b + str_a;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    
    if (numbers[0] == 0)
        return "0";
    
    string answer = "";
    for (int n : numbers) {
        answer += to_string(n);
    }
    return answer;
}