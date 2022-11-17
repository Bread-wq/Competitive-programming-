#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
// dfs each connected component and see if sum of each is zero

vvi G;
vi money;
vector<bool> visited;
int m,n;
int cur_sum=0;

void dfs(int u){
    if (visited[u]){
        return;
    }
    else{
        cur_sum+=money[u];
        visited[u]=true;
        for (auto &v: G[u]){
            if (!visited[v]) dfs(v);
        }
    }
}

int main(){
    cin>>n>>m;
    G = vvi(n, vi(0));

    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        money.push_back(x);
    }
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    visited=vector<bool>(n,false);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            cur_sum=0;
            dfs(i);
            if (cur_sum!=0){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    cout<<"POSSIBLE";
    return 0;
}