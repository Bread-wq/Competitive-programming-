#include <bits/stdc++.h>
using namespace std;
long double pi=3.141592653589793238462643383279502884+1e-9; /* pi */

int main(){
    int n,R,r;
    cin>>n>>R>>r;
    if (n==1){
        if (r<=R) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    else if (2*r>R){
        cout<<"NO";
        return 0;
    }
    long double x=asin((long double)r/(long double)(R-r));
    //cout<<"cos(theta)="<<(long double)r/(long double)(R-r);
    //cout<<"theta: "<<x<<"\n";
    //long double max_n=pi/(x);
    //cout<<"max number of plates: "<<max_n<<"\n";
    if (pi<(long double)n*x){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}