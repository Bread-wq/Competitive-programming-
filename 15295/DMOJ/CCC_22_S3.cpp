#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N,M,K;
    cin>>N>>M>>K;
    // good: subarray s.t. no two consec same number
    // max good in S with |S|=n and M>=n: (n+1)n/2
    // if M<n: 
    // 1 2 3 1 2 3
    // 6+M+M+M
    ll max_pos=(M+1)*M/2+(N-M)*M;
    //cout<<max_pos<<"\n";
    
    if (max_pos<K || K<N){
        cout<<-1;
        return 0;
    }
    vector<ll> sol(N,1);
    ll cur=N;
    ll node=1, idx=0;
    if (N==K){
        for (ll i=0; i<N; i++){
            cout<<1<<' ';
        }
        return 0;
    }
    
    while (K>cur && N>idx){
        
        sol[idx]=node;
        if (idx<M) cur+=(node-1);
        else cur+=(M-1);
        idx++;
        //cur+=(node);
        if (node==M){
            node=0;
        }
        node++;
    }
    
    ll diff=min(idx,M)-(cur-K);
    //cout<<cur-K<<"\n";
    //cout<<diff<<"\n";
    idx--;
    //cout<<idx<<"\n";
    if (cur-K!=0){
        //idx--;
        sol[idx]=sol[idx-diff];
    }
    
    for (ll i=0; i<idx; i++){
        cout<<sol[i]<<" ";
    }
    for (ll i=idx; i<N; i++){
        cout<<sol[idx]<<" ";
    }

    

    return 0;
}

