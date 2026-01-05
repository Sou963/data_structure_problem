#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> dict;   // stores unique sorted words
    string line;

    while (getline(cin, line)) {
        string word = "";
        for (char c : line) {
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    dict.insert(word);
                    word.clear();
                }
            }
        }
        if (!word.empty()) {
            dict.insert(word);
        }
    }

    for (auto &w : dict) {
        cout << w << "\n";
    }

    return 0;
}

