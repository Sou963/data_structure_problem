#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    for (int tc = 1; tc <= T; tc++)
    {
        map<string, long long> freq;
        string line;
        long long total = 0;
        while (true)
        {
            if (!getline(cin, line)) break;
            if (line.empty()) break;
            freq[line]++;
            total++;
        }
        for (auto &p : freq)
        {
            double percentage = (p.second * 100.0) / total;
            cout << p.first << " "
                 << fixed << setprecision(4)
                 << percentage << "\n";
        }
        if (tc < T)
            cout << "\n";
    }

    return 0;
}

