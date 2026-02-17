#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;

    while (cin >> Q) {
        map<pair<int,int>, ll> grid;

        while (Q--) {
            string cmd;
            cin >> cmd;

            if (cmd == "SET") {
                int x, y;
                ll d;
                cin >> x >> y >> d;

                if (d == 0)
                    grid.erase({x, y});
                else
                    grid[{x, y}] = d;
            }
            else { // QUERY
                int x, y;
                ll dist;
                cin >> x >> y >> dist;

                ll result = 0;

                for (auto &p : grid) {
                    int gx = p.first.first;
                    int gy = p.first.second;
                    ll val = p.second;

                    if (abs(gx - x) + abs(gy - y) <= dist) {
                        result = std::gcd(result, val);
                        if (result == 1) break; // early stop
                    }
                }

                cout << result << "\n";
            }
        }
    }

    return 0;
}


