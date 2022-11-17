#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int INF=INT_MAX;
// n people, k key, p office location
// sort a,b
// DP[n][k]
// DP[0][]: 0
// DP[][0]: INF for i>0
// DP[i][j]=min(DP[i][j-1] if ith person does not take jth key
//  min(max(DP[i-1][j-1], abs(Key[j]-A[i])+abs(Key[j]-p))) ) if ith person takes jth key   

int main(){
    int n,k,p;
    cin>>n>>k>>p;
    int A[n+1], Key[k+1];
    int DP[n+1][k+1];
    
    for (int i=1; i<=n; i++){
        DP[i][0]=INF;
        cin>>A[i];
    }
    for (int j=1; j<=k; j++){
        DP[0][j]=0;
        cin>>Key[j];
    }
    DP[0][0]=0;

    sort(A+1,A+n+1);
    sort(Key+1,Key+k+1);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            DP[i][j]=min(DP[i][j-1], max(DP[i-1][j-1], 
                abs(Key[j]-A[i])+abs(Key[j]-p)));
            //cout<<Key[j]<<' '<<A[i]<<"\n";
            //cout<<DP[i][j-1]<<' '<<DP[i-1][j-1]<<' '<<abs(Key[j]-A[i])+abs(Key[j]-p)<<"\n";
            //cout<<DP[i][j]<<' ';
        }
        //cout<<"\n";
    }

    cout<<DP[n][k];
}