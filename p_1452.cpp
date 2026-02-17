#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        vector<unordered_set<string>> servers(N);

        // Read servers
        for (int i = 0; i < N; i++) {
            int Qi;
            cin >> Qi;
            for (int j = 0; j < Qi; j++) {
                string app;
                cin >> app;
                servers[i].insert(app);
            }
        }

        int totalConnections = 0;

        // Read clients
        for (int i = 0; i < M; i++) {
            int Pj;
            cin >> Pj;

            vector<string> clientApps(Pj);
            for (int j = 0; j < Pj; j++) {
                cin >> clientApps[j];
            }

            // Check connection with each server
            for (int s = 0; s < N; s++) {
                bool connected = false;

                for (const string &app : clientApps) {
                    if (servers[s].count(app)) {
                        connected = true;
                        break;
                    }
                }

                if (connected)
                    totalConnections++;
            }
        }

        cout << totalConnections << "\n";
    }

    return 0;
}

