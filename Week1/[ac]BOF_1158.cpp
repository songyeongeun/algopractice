#include <bits/stdc++.h>
using namespace std;

vector<int> josephus(int n, int k)
{
    vector<int> people;
    for (int i = 1; i <= n; i++)
    {
        people.push_back(i);
    }

    vector<int> result;
    int i = 0;

    while (!people.empty())
    {
        i = (i + k - 1) % people.size();
        result.push_back(people[i]);
        people.erase(people.begin() + i);
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> permutation = josephus(n, k);

    cout << "<";
    for (int i = 0; i < permutation.size(); i++)
    {
        cout << permutation[i];
        if (i != permutation.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}