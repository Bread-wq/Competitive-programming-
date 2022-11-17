#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=1;
    int mod=1e9+7;
    for (int i=0; i<n; i++){
        ans*=2;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}