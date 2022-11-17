#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

// obs: odd col first row num= col^2
//      even row first col num= row^2
// 

ll get_val(ll r,ll c){
    ll init=0;
    if (r>c){
        if (r%2==0){
            init=r*r;
            return init+1-c;
        }
        else {
            init=(r-1)*(r-1)+1;
            return init-1+c;
        }
    }
    else{
        if (c%2==1){
            init=c*c;
            return init-r+1;
        }
        else{
            init=(c-1)*(c-1)+1;
            return init-1+r;
        }
    }
}

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        ll r,c;
        cin>>r>>c;
        cout<<get_val(r,c)<<"\n";
    }

    return 0;
}