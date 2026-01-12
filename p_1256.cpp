#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int M, C;
        cin >> M >> C;

        vector<vector<int>> table(M);

        for (int i = 0; i < C; i++)
        {
            int x;
            cin >> x;
            table[x % M].push_back(x);
        }

        for (int i = 0; i < M; i++)
        {
            cout << i << " ->";
            for (int key : table[i])
            {
                cout << " " << key << " ->";
            }
            cout << " \\\n";
        }

        if (T) cout << "\n";
    }

    return 0;
}

