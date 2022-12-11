
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> is_root;
int dfs(int v) {
    //visited[v] = true;
    int ans=1;
    for (int u : adj[v]) {
        //if (!visited[u])
            ans=max(ans,1+dfs(u));
    }
    return ans;
}

int main(){
    // odd number type of chocolate
    
    int ans=0;
    cin>>n;
    if (n>0){
        ans=1;
    }
    adj=vector<vector<int>>(n+1,vector<int>(0,0));
    is_root=vector<bool>(n+1,false);
    
    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        if (x==-1){
            is_root[i]=true;
        }
        else adj[x].push_back(i);
    }
    //cerr<<"here";
    for (int i=1; i<=n; i++){
        if (is_root[i]){
            int dist=dfs(i);
            ans=max(ans,dist);
        }
    }
    cout<<ans;

}
