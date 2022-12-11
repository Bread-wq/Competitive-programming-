#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // odd number type of chocolate
    int N, A, G;
    vector<int> a,g;
    
    ll ans=0, gun_sum=0;
    cin>>G>>A>>N;
    for (int i=0; i<G; i++){
        int x;
        cin>>x;
        gun_sum+=x;
        g.push_back(x);
    }
    for (int i=0; i<A; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(g.begin(),g.end());
    sort(a.begin(),a.end());
    int armor_idx=N/G, gun_idx=G;
    if (N%G!=0) armor_idx++;
    int min_sum=g[G-1]+a[armor_idx-1];
    while (gun_idx>0){
        
    }

    cout<<ans;

}