#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, ans=0, count=0;
    cin>>n;
    long long board[4001], cnt[2001];
    fill_n(cnt,2001,0);
    fill_n(board,4001,0);
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    for (int i=2; i<4001; i++){
        for (int j=1; j<=i/2; j++){
            int x=0;
            if (i-j==j){
                x= cnt[j]/2;
            }
            else if (i-j<2001 && i-j>j){
                x=min( cnt[j],cnt[i-j]);
            }
           
            board[i]+=x;
            
        }
        
        
        ans=max(ans,board[i]);
    }
    
    for (int i=2; i<4001; i++){
        if (board[i]==ans) count++;
    }
    cout<<ans<<" "<<count;
    
    
}

