#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Standard DSU structure with a points array
struct DSU {
    vector<int> parent;
    vector<int> points;

    DSU(int n, const vector<int>& p) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        points.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            points[i] = p[i - 1];
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Merge root_j into root_i
            parent[root_j] = root_i;
            points[root_i] += points[root_j];
        }
    }
};

void solve() {
    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<int> initial_points(N);
        for (int i = 0; i < N; ++i) {
            cin >> initial_points[i];
        }

        DSU guilds(N, initial_points);
        int rafael_wins = 0;

        for (int i = 0; i < M; ++i) {
            int Q, A, B;
            cin >> Q >> A >> B;

            if (Q == 1) {
                guilds.unite(A, B);
            } else {
                int root_A = guilds.find(A);
                int root_B = guilds.find(B);
                int root_Rafael = guilds.find(1); // Rafael is always player 1

                if (root_A != root_B) {
                    if (root_A == root_Rafael) {
                        if (guilds.points[root_A] > guilds.points[root_B]) {
                            rafael_wins++;
                        }
                    } else if (root_B == root_Rafael) {
                        if (guilds.points[root_B] > guilds.points[root_A]) {
                            rafael_wins++;
                        }
                    }
                }
            }
        }
        cout << rafael_wins << "\n";
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
