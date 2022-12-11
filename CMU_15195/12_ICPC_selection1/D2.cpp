#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 3 4 6 8 10 18 21 18*21
// 1 1 2 2 1  3  2  

// 2 4 6 8 12 24
// 1 2 2  

int clique_size[1000001], max_till[1000001];
int A[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, ans=0;
    cin>>N;
    
    for (int i=0; i<N; i++){
        //cerr<<i<<' '<<N<<"\n";
        cin>>A[i];
        clique_size[A[i]]=1;
        for (int j=i-1; j>=0; j--){
            if (A[i]%A[j]==0){
                clique_size[A[i]]=max(clique_size[A[i]],clique_size[A[j]]+1);
                if (clique_size[A[i]]>ans) break;
                if (max_till[A[j]]==clique_size[A[j]]) break;
            }            
        }
        ans=max(ans,clique_size[A[i]]);
        max_till[A[i]]=ans;
        //cerr<<i<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}