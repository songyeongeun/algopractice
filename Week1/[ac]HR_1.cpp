#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp = 0;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        temp = vec[i];
        vec[i] = vec[n - 1 - i];
        vec[n - 1 - i] = temp;
        temp = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}