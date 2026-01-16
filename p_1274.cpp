#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0) break;
        vector<int> target(N);
        for (int i = 0; i < N; i++)
            cin >> target[i];
        vector<int> check = target;
        sort(check.begin(), check.end());
        bool ok = true;
        for (int i = 0; i < N; i++)
        {
            if (check[i] != i + 1)
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << "No solution\n";
            continue;
        }
        vector<int> cur(N);
        iota(cur.begin(), cur.end(), 1);

        vector<int> strokes;

        for (int i = 0; i < N; i++)
        {
            int pos = -1;
            for (int j = i; j < N; j++)
            {
                if (cur[j] == target[i])
                {
                    pos = j;
                    break;
                }
            }
            for (int j = pos; j > i; j--)
            {
                swap(cur[j], cur[j - 1]);
                strokes.push_back(j);
            }
        }
        cout << strokes.size();
        for (int s : strokes)
            cout << " " << s;
        cout << "\n";
    }

    return 0;
}

