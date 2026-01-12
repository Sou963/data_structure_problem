#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    while (cin >> N >> M)
    {
        cout << N << " " << M << "\n";
        if (N == 0 && M == 0) break;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), [&](int a, int b)
        {
            int ma = a % M;
            int mb = b % M;
            if (ma != mb) return ma < mb;
            bool aOdd = (a & 1);
            bool bOdd = (b & 1);
            if (aOdd != bOdd) return aOdd > bOdd;
            if (aOdd) return a > b;
            return a < b;
        });

        for (int x : arr)
        {
            cout << x << "\n";
        }
    }

    return 0;
}

