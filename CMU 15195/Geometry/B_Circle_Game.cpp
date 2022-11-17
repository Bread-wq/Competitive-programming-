#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A="Ashish\n", U="Utkarsh\n";


int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        ll d,k;
        cin>>d>>k;
        ll t=(ll)trunc((double)d/sqrt(2.0));
        //cout<<"t: "<<t<<"\n";
        t=t/k*k;
        
        //cout<<"t: "<<t<<"\n";
        // check if you can still go up
        ll sum=t*t+(t+k)*(t+k);
        
        ll bound=d*d;
        //cout<<"sum  "<<sum<<"  bound  "<<bound;
        if (sum<=bound){
            cout<<A;
            //cout<<"number of moves: "<<t/k*2+1<<"\n";
        }
        else {
            cout<<U;
            //cout<<"number of moves: "<<t/k*2<<"\n";
        }

    }
    return 0;
}