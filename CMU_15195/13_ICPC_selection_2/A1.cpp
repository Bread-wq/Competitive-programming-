#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0, sum[3];
int num[3];

int main(){
    // odd number type of chocolate
    int N, A, G;
    vector<pair<int,int>> a;
    
    cin>>G>>A>>N;
    for (int i=0; i<G; i++){
        int x;
        cin>>x;
        a.push_back({x,1});
    }
    for (int i=0; i<A; i++){
        int x;
        cin>>x;
        a.push_back({x,2});
    }
    sort(a.begin(),a.end());
    int size=0;
    int idx=0;
    for (auto x:a){
        sum[x.second]+=x.first;
        num[x.second]++;
        if (num[1]*num[2]>=N){
            break;
        }
        idx++; // the last one included
    }
    int capacity_diff=num[1]*num[2]-N;
    ans=sum[1]*num[2]+sum[2]*num[1];
    if (capacity_diff!=0){
        int type=a[idx].second;
        ans=ans-(a[idx].first*capacity_diff);
        while (capacity_diff>0){
            idx--;
            if (a[idx].second!=type){
                capacity_diff--;
                ans-=a[idx].first;
            }
        }
    }
    // TODO: minus the extra
    cout<<ans;

}