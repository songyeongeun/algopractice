#include <bits/stdc++.h>
using namespace std;

int main(){
    string str,res,k;
    cin >> str;
    map<char, int> english; //알파벳 넣을 배열
    cnt=0;  //홀수 카운트
    string arr[26];  

    for(int i=0;i<str.length();i++){ //각 알파벳 몇개인지 저장하기
        for(int i=0;i<26;i++){
            int a = str[i] - 'A';
            english[a]++;
        }
    }

    for(int i=0;i<26;i++){  //홀수인 문자 구하기
        if(english[i.second]%2==1){
            cnt ++;
            arr[i] = i+'A';
        }
        if(cnt >=2){    //홀수인 문자가 2개 이상이면 팰린드롬 안됨.
            cout << "I'm Sorry Hansoo"<<endl;
            return 0;
        }
    }

    
    //전부 짝수일 때, 홀수 하나 있을 때 구해야함.
    //짝수는 절반만 정렬해서 출력하고 나머지는 reverse해서 출력하기
    //홀수는 절반만 정렬해서 출력하고 홀수 하나는 베열에 넣어놓고 출력하고 나머지 reverse

    
}