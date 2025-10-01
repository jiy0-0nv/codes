#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <algorithm>

struct Comp {
    bool operator() (const string& a, const string& b) const {
        if (a.length() != b.length()) {
            return a.length() > b.length();
        }
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<string, vector<string>, Comp> q;

    while (N--){
        string line;
        cin >> line;
        line += 'a';
        string n = "";
        for (char c : line){
            if (c >= '0' && c <= '9'){
                n += c;
            }
            else if (n.length() > 0){
                if (n.front() == '0'){
                    int idx = 0;
                    for (int i=0; i<n.length(); i++){
                        if (n[i] != '0') break;
                        else idx++;
                    }
                    if (idx == n.length())
                        q.push("0");
                    else
                        q.push(n.substr(idx));
                } else {
                    q.push(n);
                }
                n = "";
            }
        }
    }

    while (!q.empty()){
        cout << q.top() << "\n";
        q.pop();
    }

    return 0;
}