#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n,c;
vi stair, lift, A, B, dist;
//priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

// stair = [0, 7, 13, 31, 24, 40]
// lift  = [0, 8, 17, 18, 28, 35] 

int main(){
    cin>>n>>c;
    A=vi(n, INT_MAX);
    B=vi(n, INT_MAX);
    for (int i=0; i<n-1; i++){
        cin>>A[i];
    }
    for (int i=0; i<n-1; i++){
        cin>>B[i];
    }

    stair=vi(n, INT_MAX);
    lift=vi(n, INT_MAX);
    dist=vi(n,0);
    stair[0]=0;
    lift[0]=c;

    //Q.push(make_pair(0,0));
    cout<<dist[0]<<' ';
    for (int i=0; i<n-1; i++){
        stair[i+1]=min(stair[i]+A[i], lift[i]+A[i]);
        lift[i+1]=min(stair[i]+B[i]+c, lift[i]+B[i]);
        dist[i+1]=min(stair[i+1],lift[i+1]);
        cout<<dist[i+1]<<' ';
    }

    return 0; 
}