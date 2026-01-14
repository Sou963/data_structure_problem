#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](int a, int b)
    {
        if (a % 2 == 0 && b % 2 == 0)
            return a < b;
        if (a % 2 == 1 && b % 2 == 1)
            return a > b;
        return a % 2 == 0;
    });

    for (int x : v)
    {
        cout << x << "\n";
    }
    return 0;
}

