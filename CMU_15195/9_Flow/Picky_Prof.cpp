// QN: https://codeforces.com/group/KIrM1Owd8u/contest/407924/problem/A2
// Reference: https://noiref.codecla.ws/graph/#maxflow

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
struct Edge {
    int to;
    ll cap, flow;
    Edge(int tar, ll capacity): to(tar), cap(capacity), flow(0) {}
    ll amt() { return cap-flow; }
};
struct PushRelabel {
    int N;
    vector<Edge> E;
    vector<vector<int> >G;
    vector<int> height, cnt;
    vector<bool> inq;
    vector<ll> excess;
    queue<int> q;
    
    PushRelabel(int _N): N(_N), height(_N), cnt(2*_N), inq(_N), excess(_N), G(_N) {}
    
    void AddEdge(int a, int b, ll c) {  //directed edge a -> b with capacity c
        //cout<<a<<' '<<b<<' '<<c<<"\n";
        if (a == b) return;
        G[a].push_back(E.size());
        E.push_back({b, c});
        G[b].push_back(E.size());
        E.push_back({a, 0});
    }
    
    void Enqueue(int x) {
        if (inq[x] || excess[x] == 0) return;
        inq[x] = 1;
        q.push(x);
    }
    
    void Push(int x, int ed) {
        int it = E[ed].to;
        if (height[x] <= height[it]) return;
        ll flow = min(excess[x], E[ed].amt());
        if (flow == 0) return;
        E[ed].flow += flow;
        E[ed^1].flow -= flow;
        excess[x] -= flow;
        excess[it] += flow;
        Enqueue(it);
    }
    
    void Relabel(int x) {
        if (excess[x] == 0) return;
        --cnt[height[x]];
        height[x] = 2*N;
        for (auto it:G[x]) {
            if (E[it].amt() == 0) continue;
            height[x] = min(height[x], height[E[it].to]+1);
        }
        ++cnt[height[x]];
        Enqueue(x);
    }
    
    void GapHeuristic(int g) {
        for (int i = 0; i < N; ++i) {
            if (height[i] >= g) {
                --cnt[height[i]];
                height[i] = max(height[i], N+1);
                ++cnt[height[i]];
                Enqueue(i);
            }
        }
    }
    
    void Discharge(int x) {
        for (auto it:G[x]) {
            Push(x, it);
            if (excess[x] == 0) return;
        }
        if (cnt[height[x]] == 1) GapHeuristic(height[x]);
        else Relabel(x);
    }
    
    ll MaxFlow(int S, int T) {
        height[S] = N;
        cnt[0] = N-1, cnt[N] = 1;
        inq[S] = inq[T] = 1;
        
        for (auto it:G[S]) {
            excess[S] += E[it].cap;
            Push(S, it);
        }
        
        while (!q.empty()) {
            int x = q.front();
            q.pop(), inq[x] = 0;
            Discharge(x);
        }
        
        return excess[T];
    }
    
    vector<int> MinCut(int S, int T) {
        MaxFlow(S, T);
        int split = N;
        vector<int> ans;
        for (int i = 1; i <= N; ++i) {
            if (cnt[i] == 0) {
                split = i;
                break;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (height[i] > split) ans.push_back(i);
        }
        return ans;
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    struct PushRelabel F=PushRelabel(n+m+2);
    // int p[n], b[m];
    int S=n+m, T=n+m+1; // source and sink
    int total=0;
    for (int i=0; i<n; i++){ // # of drinks prof wanna drink
        int p;
        cin>>p;
        total+=p;
        F.AddEdge(i,T,p); 
    }
    for (int i=0; i<m; i++){ // # of drinks available 
        int b;
        cin>>b;
        F.AddEdge(S,i+n,b);
    }
    for (int i=0; i<n; i++){ // prof
        int n_willing;
        cin>>n_willing;
        for (int j=0; j<n_willing; j++){ 
            int drink;
            cin>>drink;
            F.AddEdge(drink+n-1, i, INT_MAX);
        }
    }
    int sum=F.MaxFlow(S,T);
    if (total==sum){
        cout<<"PARTY";
    }
    else cout<<"NO";
}