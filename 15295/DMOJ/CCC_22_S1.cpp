#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    if (n<4 || n==6||n==7||n==11){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    cin>>n;
    // 4 5 6 7 8 9 10 11 12 13 14 
    // 4 5 8 9 10 12 13 14 15 16 
    //int memo[5];
    if (n<4 || n==6||n==7||n==11){
        cout<<0;
    }
    else if (n<20){
        cout<<1;
    }
    else{
        if (n%4==0 || n%5==0) cout<<n/20+1;
        else {
            cout<<fun(n%20)+n/20;
        }
    }
    
    return 0;
}

// 30: 5*6, 5*2+4*5
