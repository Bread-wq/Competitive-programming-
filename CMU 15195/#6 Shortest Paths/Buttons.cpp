#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, m;
queue<int> Q;

// idx: 0 1 2 3 4 5 6 7 8
// dist:      1 0       1
// 4-1=3, 3*2=6
// Q: 4 3 2 6
// 10-1*9=1
vi dist;
// 3 6 2  

int main(){
    cin>>n>>m;

    int upper;
    int t=n;

    if (n>m) upper=n;
    else while (t<m){
        t*=2;
    }
    upper=t+1;
    //=max(abs(m-n)+m, n); // upper bound
    dist=vi(upper+1, INT_MAX);
    Q.push(n);
    dist[n]=0;
    int cur=Q.front();
    while (cur!=m && !Q.empty()){
        Q.pop();
        int x,y;
        x = cur*2;
        y = cur-1;
        if ((x<upper) && (dist[x]==INT_MAX)){
            Q.push(x);
            dist[x]=min(dist[x],dist[cur]+1);
        }
        if ((y>0) && (dist[y]==INT_MAX)){
            Q.push(y);
            dist[y]=min(dist[y],dist[cur]+1);
        }

        cur=Q.front();
        //cout<< cur<<' ';
    }
    cout<<dist[m];
    return 0;

}
