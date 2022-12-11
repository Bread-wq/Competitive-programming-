#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 3 4 6 8 10 18 21 18*21
// 1 1 2 2 1  3  2  
//       1    1  

// 2 4 6 8 12 24
// 1 2 2  

int clique_size[1000001];
int A[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, ans=0;
    cin>>N;
    for (int i=0; i<N; i++){
        cin>>A[N-i-1];
    }

    for (int i=0; i<N; i++){
        //cerr<<i<<' '<<N<<"\n";   
        clique_size[A[i]]=1;
        for (int j=2; j*A[i]<=1000000; j++){
            clique_size[A[i]]=max(clique_size[A[i]],clique_size[j*A[i]]+1);
        }
        ans=max(ans,clique_size[A[i]]);
        //cerr<<i<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}