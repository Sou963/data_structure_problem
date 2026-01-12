#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool first = true;

    while (getline(cin, line)) {
        if (!first) cout << "\n";
        first = false;

        map<int, int> freq;

        // Count frequencies
        for (char c : line) {
            freq[(int)c]++;
        }

        // Move to vector for sorting
        vector<pair<int, int>> v;
        for (auto &p : freq) {
            v.push_back({p.first, p.second});
        }

        // Sort by frequency asc, ASCII desc
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        });

        // Output
        for (auto &p : v) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}

