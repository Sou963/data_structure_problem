#include <bits/stdc++.h>
using namespace std;
struct Shirt
{
    string name;
    string color;
    char size;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    bool first = true;
    while (cin >> N && N != 0)
    {
        cin.ignore();
        vector<Shirt> shirts(N);
        for (int i = 0; i < N; i++)
        {
            getline(cin, shirts[i].name);
            cin >> shirts[i].color >> shirts[i].size;
            cin.ignore();
        }
        sort(shirts.begin(), shirts.end(), [](const Shirt &a, const Shirt &b)
        {
            if (a.color != b.color)
                return a.color < b.color;
            if (a.size != b.size)
                return a.size > b.size;
            return a.name < b.name;
        });
        if (!first) cout << "\n";
        first = false;

        for (auto &s : shirts)
        {
            cout << s.color << " " << s.size << " " << s.name << "\n";
        }
    }
    return 0;
}

