#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    int city = 1;
    bool first = true;

    while (cin >> N && N != 0)
    {

        if (!first) cout << endl;
        first = false;

        map<int, int> mp;
        int totalPeople = 0;
        int totalConsumption = 0;

        for (int i = 0; i < N; i++)
        {
            int X, Y;
            cin >> X >> Y;

            int perPerson = Y / X;
            mp[perPerson] += X;

            totalPeople += X;
            totalConsumption += Y;
        }

        cout << "Cidade# " << city++ << ":" << endl;

        bool firstPrint = true;
        for (auto it : mp)
        {
            if (!firstPrint) cout << " ";
            firstPrint = false;
            cout << it.second << "-" << it.first;
        }
        cout << endl;

        double avg = (double) totalConsumption / totalPeople;
        avg = (int)(avg * 100) / 100.0;

        cout << fixed << setprecision(2);
        cout << "Consumo medio: " << avg << " m3." << endl;
    }

    return 0;
}
