#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
// DFS right then down

vii visited,grid;
int N,M,K;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool dfs(int x, int y) {
    if (visited[x][y]) return false;
    visited[x][y] = 1;
    //cout<<"visiting"<<x<<' '<<y<<"\n";
    if (grid[x][y]) {
         //cout<<x<<' '<<y<<"\n";
         return true;
    }
    for (int i = 0; i < 4; ++i) { //Change  '4' to '8' for 8 directions
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;
        if (nx >= N || ny >= M) continue; //Edit if 1 index-ed
        if (visited[nx][ny]) continue; 
        if (dfs(nx, ny)) return true;
    }
    return false;
}

/* Usage */
int num_pools = 0;

int main(){
    
    cin>>N>>M>>K;
    visited=vii(N, vi(M,0));
    grid=vii(N, vi(M,0));
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            char c;
            cin>>c;
            if (c=='1') grid[i][j]=1;
        }
    }

    int cnt=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 0) continue;
            if (visited[i][j]) continue;
            //cout<<"start: "<<i<<' '<<j<<"\n";
            grid[i][j]=0;
            if (dfs(i, j)) cnt++;
            else break;
        }
    }
    if (cnt>=K){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
    
}