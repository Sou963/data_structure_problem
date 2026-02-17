#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    while (getline(cin, line)) {
        list<string> result;
        string current = "";
        bool atHome = false;

        for (char c : line) {
            if (c == '[') {
                if (atHome)
                    result.push_front(current);
                else
                    result.push_back(current);

                current = "";
                atHome = true;
            }
            else if (c == ']') {
                if (atHome)
                    result.push_front(current);
                else
                    result.push_back(current);

                current = "";
                atHome = false;
            }
            else {
                current += c;
            }
        }

        // Insert the last collected part
        if (atHome)
            result.push_front(current);
        else
            result.push_back(current);

        // Print final result
        for (const string &part : result) {
            cout << part;
        }
        cout << "\n";
    }

    return 0;
}

