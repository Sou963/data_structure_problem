#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);

        int diamonds = 0;
        int open = 0;

        for (char c : s) {
            if (c == '<') {
                open++;
            }
            else if (c == '>') {
                if (open > 0) {
                    diamonds++;
                    open--;
                }
            }
        }

        cout << diamonds << "\n";
    }

    return 0;
}
