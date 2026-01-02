#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        vector<string> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];

        sort(v.begin(), v.end());

        long long saved = 0;

        for (int i = 1; i < N; i++) {
            int cnt = 0;
            int L = v[i].size();

            // count prefix match between v[i] and v[i-1]
            for (int j = 0; j < L; j++) {
                if (v[i][j] == v[i - 1][j]) cnt++;
                else break;
            }

            saved += cnt;
        }

        cout << saved << "\n";
    }

    return 0;
}

