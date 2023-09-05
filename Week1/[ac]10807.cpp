#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b;
    cin >> a;
    
    vector<int> v(a);
    for(int i=0;i<a;i++){
        cin >> v[i];
    }

    cin >> b;

    int count=0;
    for(int i=0;i<a;i++){
        if(v[i] == b)
            count ++;
    }

    cout << count;

    return 0;

}