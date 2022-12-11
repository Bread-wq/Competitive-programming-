#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n=1001;
vector<bool> is_prime(n+1, true);

// 3 4 6 8 10 18 21 18*21
// 1 1 2 2 1  3  2  

// 2 4 6 8 12 24
// 1 2 2  


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i=0; i<=n; i++){
        if (is_prime[i]) primes.push_back(i);
    }
    //Note that an empty set of vertices 
    // a set consisting of a single vertex are also counted as cliques. 
    int N, ans=0;
    int clique_size[1000001], max_till[1000001];
    
    cin>>N;
    int A[1000001];

    for (int i=0; i<N; i++){
        //cerr<<i<<' '<<N<<"\n";
        cin>>A[i];
        clique_size[A[i]]=1;
        for (int d:primes){
            if (d*d>A[i]){
                break;
            }
            if (A[i]%d==0){
                int x=A[i]/d;
                if (clique_size[x]!=0){
                    clique_size[A[i]]=max(clique_size[A[i]],clique_size[x]+1);
                    if (clique_size[A[i]]>max_till[x]) break;
                }
            }
        }
        //for (int j=i-1; j>=0; j--){
            // if (A[i]%A[j]==0){
            //     clique_size[A[i]]=max(clique_size[A[i]],clique_size[A[j]]+1);
            //     if (clique_size[A[i]]>ans) break;
            // }
            //cout<<"in j\n";
            
        //}
        ans=max(ans,clique_size[A[i]]);
        max_till[A[i]]=ans;
        //cerr<<i<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}