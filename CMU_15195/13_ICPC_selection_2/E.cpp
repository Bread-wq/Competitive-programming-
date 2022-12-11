#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll area(int x1, int y1, int x2, int y2, int x3, int y3){
    ll area=(ll)(x2-x1)*(y3-y2)-(ll)(x3-x2)*(y2-y1);
    if (area==29) cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<"\n";
    return abs(area);
}
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
        y[0]=0; y[1]=0;

        cin>>p2;
        for (int j=0; j<p2; j++){
            int m;
            cin>>m;
            if (j==0) x[2]=m;
            else if (j==p2-1) x[3]=m;
        }
        y[2]=Y; y[3]=Y;

        cin>>p3;
        for (int j=0; j<p3; j++){
            int m;
            cin>>m;
            if (j==0) y[4]=m;
            else if (j==p2-1) y[5]=m;
        }
        x[4]=0; x[5]=0;

        cin>>p4;
        for (int j=0; j<p4; j++){
            int m;
            cin>>m;
            if (j==0) y[6]=m;
            else if (j==p4-1) y[7]=m;
        }
        x[6]=X; x[7]=X;
        for (int a=0; a<8; a++){
            cout<<"x: "<<x[a]<<"  y: "<<y[a]<<"\n";
        }
        for (int a=0; a<6; a++){
            for (int b=a+1; b<7; b++){
                for (int c=b+1; c<8; c++){
                    ll A=area(x[a],y[a],x[b],y[b],x[c],y[c]);
                    ans=max(ans,A);
                }
            }
        }
        cout<<ans<<"\n";
        cout<<area(0,1,0,6,5,5);
    }

}