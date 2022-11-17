#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<pair<int, int>> vp;
// n cities, m one-way roads
// 2n roads remain
int N,n,m;

vvi G, G_r;
vector<bool> visited;
vp useful, all, erase;

void dfs(int u){
    if (visited[u]){
        return;
    }
    else{
        visited[u]=true;
        for (auto &v: G[u]){
            if (!visited[v]){
                dfs(v);
                useful.insert(make_pair(u,v));
            } 
        }
    }
}

void dfs_r(int u){
    if (visited[u]){
        return;
    }
    else{
        visited[u]=true;
        for (auto &v: G_r[u]){
            if (!visited[v]){
                dfs_r(v);
                useful.insert(make_pair(v,u));
            } 
        }
    }
}

// set_difference(first, first + 5, second, second + 5, v2.begin());

int main(){
    cin>>N;
    for (int i=0; i<N; i++){
        cin>>n>>m;
        // use n edges to connect node 1 to every other nodes
        // reverse the direction of all edges 
        // use the same algorithm and find n other edges such that
        // all edges can reach n
        visited=vector<bool>(n, false);
        G=vvi(n, vi(0));
        G_r=vvi(n, vi(0)); // reversed graph
        all.clear(); useful.clear(); erase.clear();

        for (int j=0; j<m; j++){
            int out,in;
            cin>>out>>in;
            out--; in--;
            G[out].push_back(in);
            G_r[in].push_back(out);
            all.insert(make_pair(out,in));
        }
        dfs(0); 
        visited=vector<bool>(n, false);
        dfs_r(0);
        
        m-=2*n;
        
        for (auto &x: all){
            if (useful.find(x)==useful.end()){
                cout<<x.first+1<<' '<<x.second+1<<"\n";
                m--;
            }
            
            if (m==0) break;
        }
    }

    return 0;
}