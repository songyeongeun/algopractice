// 일반 트리 부모 찾기

// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <map>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    multimap<int, int> map;

    int n;
    cin >> n;

    int a;
    int b;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;

        // 이미 맵에 저장되어 있는지 확인
        bool exist = false;
        auto range = map.equal_range(a); // key값이 a인 모든 요소들의 범위 반환
        for (auto i = range.first; i != range.second; ++i)
        {
            if (i->second == b)
            {
                exist = true;
                break;
            }
        }

        // 맵에 저장되어 있지 않으면, 저장
        if (!exist)
        {
            map.insert(make_pair(a, b));
            map.insert(make_pair(b, a));
        }
    }

    vector<int> parent(n + 1, 0);
    multimap<int, int>::iterator iter; // 멀티맵 안에서 사용될 반복자인 iter를 선언

    // 1번 노드에 연결된 노드의 부모를 설정
    for (iter = map.lower_bound(1); iter != map.upper_bound(1); iter++)
    {
        parent[iter->second] = 1;
    }

    // 나머지 노드에 대해 부모를 설정
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] == 0)
        { // 부모가 아직 설정되지 않은 노드
            for (iter = map.lower_bound(i); iter != map.upper_bound(i); iter++)
            {
                if (parent[iter->second] != 0)
                {
                    parent[i] = iter->second; // 부모가 이미 있는 노드를 부모로 설정
                    break;
                }
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        cout << parent[i];
    }

    return 0;
}