#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i=1; i<phone_book.size(); i++) {
        string a = phone_book[i-1];
        string b = phone_book[i];
        for (int j=0; j<a.length(); j++) {
            if (a[j]!=b[j]) break;
            else if (j == a.length()-1) return false;
        }
    }
    
    return answer;
}