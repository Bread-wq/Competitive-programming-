#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int X,Y;
        cin>>X>>Y;
        ll ans=0;
        int x[8];
        int y[8];
        int p1,p2,p3,p4;
        cin>>p1;
        for (int j=0; j<p1; j++){
            int m;
            cin>>m;
            if (j==0) x[0]=m;
            else if (j==p1-1) x[1]=m;
        }
        ans=max(ans,(ll)(x[1]-x[0])*Y);

        cin>>p2;
        for (int j=0; j<p2; j++){
            int m;
            cin>>m;
            if (j==0) x[2]=m;
            else if (j==p2-1) x[3]=m;
        }
        ans=max(ans,(ll)(x[3]-x[2])*Y);

        cin>>p3;
        for (int j=0; j<p3; j++){
            int m;
            cin>>m;
            if (j==0) y[4]=m;
            else if (j==p3-1) y[5]=m;
        }
        ans=max(ans,(ll)(y[5]-y[4])*X);

        cin>>p4;
        for (int j=0; j<p4; j++){
            int m;
            cin>>m;
            if (j==0) y[6]=m;
            else if (j==p4-1) y[7]=m;
        }
        ans=max(ans,(ll)(y[7]-y[6])*X);
      
        cout<<ans<<"\n";
        //cout<<area(0,1,0,6,5,5);
    }

}