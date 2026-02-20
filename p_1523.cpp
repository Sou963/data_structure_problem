#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Car {
    int arrival;
    int departure;
};

void solve() {
    int N, K;
    while (cin >> N >> K && (N != 0 || K != 0)) {
        stack<Car> parking;
        bool possible = true;

        for (int i = 0; i < N; ++i) {
            int c, s;
            cin >> c >> s;

            if (!possible) continue;

            // 1. Remove cars that should have already left
            while (!parking.empty() && parking.top().departure <= c) {
                parking.pop();
            }

            // 2. Check if there's room in the parking lot
            if (parking.size() >= K) {
                possible = false;
            }

            // 3. Check if this car will block the car behind it
            // The car being parked must leave BEFORE the car currently at the top
            if (!parking.empty() && s > parking.top().departure) {
                possible = false;
            }

            parking.push({c, s});
        }

        if (possible) {
            cout << "Sim" << endl;
        } else {
            cout << "Nao" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
