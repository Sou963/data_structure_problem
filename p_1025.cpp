#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    int caseNum = 1;

    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<int> marbles(N);

        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":\n";

        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;
            auto it = lower_bound(marbles.begin(), marbles.end(), query);

            if (it != marbles.end() && *it == query) {
                int pos = it - marbles.begin() + 1;
                cout << query << " found at " << pos << "\n";
            } else {
                cout << query << " not found\n";
            }
        }
    }

    return 0;
}

