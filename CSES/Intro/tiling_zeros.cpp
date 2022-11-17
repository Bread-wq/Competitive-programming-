#include <bits/stdc++.h>
using namespace std;

int main(){
    int pow_5=5;
    int n;
    cin>>n;
    int ans=0;

    while (pow_5<=n){
        ans+=(n/pow_5);
        pow_5*=5;
    }
    cout<<ans;
    return 0;
}