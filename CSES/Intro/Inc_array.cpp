#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

// 3 2 5 1 7

int main(){
    int n;
    cin>>n;
    ll ans=0;
    int x[n];
    for (int i=0; i<n; i++){
        cin>>x[i];
        if (i==0) continue;
        if (x[i]<x[i-1]){
            ans=ans+(x[i-1]-x[i]);
            x[i]=x[i-1];
        }
    }
    cout<<ans;
    return 0;
}