#include <bits/stdc++.h>
using namespace std;

struct Team {
    int id;
    int leaguePoints = 0;
    int scored = 0;
    int received = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int instance = 1;

    while (cin >> n && n != 0) {
        vector<Team> teams(n + 1);

        for (int i = 1; i <= n; i++) {
            teams[i].id = i;
        }

        int totalGames = n * (n - 1) / 2;
        while (totalGames--) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;

            teams[x].scored += y;
            teams[x].received += w;
            teams[z].scored += w;
            teams[z].received += y;

            if (y > w) {
                teams[x].leaguePoints += 2;
                teams[z].leaguePoints += 1;
            } else {
                teams[z].leaguePoints += 2;
                teams[x].leaguePoints += 1;
            }
        }

        vector<Team> order;
        for (int i = 1; i <= n; i++)
            order.push_back(teams[i]);

        sort(order.begin(), order.end(), [](const Team &a, const Team &b) {
            if (a.leaguePoints != b.leaguePoints)
                return a.leaguePoints > b.leaguePoints;

            double avgA = (a.received == 0) ? a.scored : (double)a.scored / a.received;
            double avgB = (b.received == 0) ? b.scored : (double)b.scored / b.received;
            if (fabs(avgA - avgB) > 1e-9)
                return avgA > avgB;

            if (a.scored != b.scored)
                return a.scored > b.scored;

            return a.id < b.id;
        });

        cout << "Instancia " << instance++ << "\n";
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << order[i].id;
        }
        cout << "\n\n";
    }

    return 0;
}

