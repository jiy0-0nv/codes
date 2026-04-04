#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool compareBooks(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    unordered_map<string, int> bs;

    while (N--) {
        string t;
        cin >> t;
        if (bs.count(t)) {
            bs[t]++;
        }
        else {
            bs[t] = 1;
        }
    }

    vector<pair<string, int>> books(bs.begin(), bs.end());
    sort(books.begin(), books.end(), compareBooks);

    cout << books[0].first;

    return 0;
}