// QN: https://codeforces.com/group/KIrM1Owd8u/contest/407924/problem/A1
// Reference: https://noiref.codecla.ws/graph/#maxflow

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
struct AugPath {
    int A, B;   //size of left, right groups
    vii G; //size A
    vb visited;   //size A
    vi P;          //size B
    
    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1) {}
    
    void AddEdge(int a, int b) {    //a from left, b from right
        G[a].push_back(b);
    }
    bool Aug(int x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        /* Greedy heuristic */
        for (auto it:G[x]) {
            if (P[it] == -1) {
                P[it] = x;
                return 1;
            }
        }
        for (auto it:G[x]) {
            if (Aug(P[it])) {
                P[it] = x;
                return 1;
            }
        }
        return 0;
    }
    int MCBM() {
        int matchings = 0;
        for (int i = 0; i < A; ++i) {
            visited.resize(A, 0);
            matchings += Aug(i);
            visited.clear();
        }
        return matchings;
    }
    vector<pair<int, int> > GetMatchings() {
        vector<pair<int, int> > matchings;
        for (int i = 0; i < B; ++i) {
            if (P[i] != -1) matchings.emplace_back(P[i], i);
        }
        return matchings;
    }
};

int get_idx(int i, int c, int j){
    return i*c+j;
}

bool check_is_left(int i,int c,int j){
    int parity=(i+j)%2;
    if (parity==0) return true;
    else return false;
}

int main(){
    int r,c;
    cin>>r>>c;
    struct AugPath X=AugPath(r*c, r*c);
    bool Map[30][30];

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            //bool is_left=check_is_left(i,c,j);
            char c;
            cin>>c;
            if (c=='.') Map[i][j]=true;
            else Map[i][j]=false;
        }
    }
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1,  0, 0, 1, -1, 1, -1};
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (!check_is_left(i,c,j)) continue;
            if (Map[i][j]==false) continue;
            int idx=get_idx(i,c,j);
            //cout<<"left"<<idx<<"\n";
            for (int k=0; k<4; k++){
                int nx=i+dx[k], ny=j+dy[k];
                if (nx<0 || ny<0) continue;
                if (nx>=r || ny>=c) continue;
                if (Map[nx][ny]==false) continue;
                int idx_r=get_idx(nx,c,ny);
                //cout<<nx<<' '<<ny<<"\n";
                //cout<<"right"<<idx_r<<"\n";
                X.AddEdge(idx, idx_r);
            }
        }
    }
    cout<<X.MCBM();


}