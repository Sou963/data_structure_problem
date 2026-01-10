#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b) {
                return a.size() > b.size();
            }
        );
        for (int i = 0; i < words.size(); i++) {
            if (i) cout << " ";
            cout << words[i];
        }
        cout << "\n";
    }

    return 0;
}
