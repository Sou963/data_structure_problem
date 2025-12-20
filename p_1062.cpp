#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        while (true) {
            vector<int> target(N);
            cin >> target[0];

            if (target[0] == 0) {
                cout << "\n";
                break;
            }

            for (int i = 1; i < N; i++) cin >> target[i];

            stack<int> station;
            int current = 1;
            int index = 0;

            while (current <= N) {
                station.push(current);
                current++;

                while (!station.empty() && station.top() == target[index]) {
                    station.pop();
                    index++;
                }
            }

            if (index == N)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}

