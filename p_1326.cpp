#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, string>> reaction;
map<string, int> memo;
set<string> produced;

int solve(const string &s) {
    // If already computed
    if (memo.count(s)) return memo[s];

    // If initial substance (not produced by any reaction)
    if (!reaction.count(s)) {
        return memo[s] = 1;
    }

    auto [a, b] = reaction[s];
    int ca = solve(a);
    int cb = solve(b);

    if (ca == cb)
        return memo[s] = ca + 1;
    else
        return memo[s] = max(ca, cb);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R;
    while (cin >> R && R != 0) {
        reaction.clear();
        memo.clear();
        produced.clear();

        string line;
        getline(cin, line); // consume endline

        string lastProduct;

        for (int i = 0; i < R; i++) {
            getline(cin, line);

            string a, plus, b, arrow, c;
            stringstream ss(line);
            ss >> a >> plus >> b >> arrow >> c;

            reaction[c] = {a, b};
            produced.insert(c);
            lastProduct = c;
        }

        int result = solve(lastProduct);
        cout << lastProduct << " requires " << result << " containers\n";
    }

    return 0;
}

