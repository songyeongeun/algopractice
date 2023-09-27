#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string name;
    cin >> name;

    vector<int> count(26, 0); // 알파벳 개수를 저장할 배열
    string hol = "";          // 홀수 개수의 알파벳을 저장할 문자열
    string even = "";         // 짝수 개수의 알파벳을 저장할 문자열

    // 각 알파벳의 개수를 세기
    for (char c : name)
    {
        count[c - 'A']++;
    }

    // 홀수 개수의 알파벳 확인
    int oddCount = 0;   // 홀수 개수의 알파벳 수
    char oddChar = ' '; // 홀수 개수의 알파벳 중 하나

    for (int i = 0; i < 26; i++)
    {
        if (count[i] % 2 == 1)
        {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    // 홀수 개수의 알파벳이 2개 이상인 경우 팰린드롬을 만들 수 없음
    if (oddCount >= 2)
    {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }

    // 짝수 개수의 알파벳을 문자열에 추가
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < count[i] / 2; j++)
        {
            even += 'A' + i;
        }
    }

    // 팰린드롬 생성
    string palindrome = even;
    reverse(palindrome.begin(), palindrome.end()); // 짝수 문자열을 뒤집음
    if (oddCount == 1)
    {
        palindrome = even + oddChar + palindrome; // 홀수 문자를 중앙에 추가
    }
    else
    {
        palindrome = even + palindrome;
    }

    cout << palindrome << endl;

    return 0;
}
