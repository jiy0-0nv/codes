#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;
    list<char> editor(input.begin(), input.end());

    auto cursor = editor.end();
    string cmd;

    int m;
    cin >> m;
    while (m--) {
        cin >> cmd;
        if (cmd == "L" && cursor != editor.begin()) cursor--;
        else if (cmd == "D" && cursor != editor.end()) cursor++;
        else if (cmd == "B" && cursor != editor.begin()) cursor = editor.erase(--cursor);
        else if (cmd == "P"){
            char s;
            cin >> s;
            editor.insert(cursor, s);
        }
    }
    for (char c : editor) cout << c;
    return 0;
}