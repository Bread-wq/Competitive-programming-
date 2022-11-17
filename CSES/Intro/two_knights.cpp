#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

/*
xx
xx 4C2

xxx
xxx
xxx 9C2 - 4*2

*/
ll choose2(ll a){
    return a*(a-1)/2;
}

ll attack(ll a){
    return (a-2)*(a-1)*4;
}

int main(){
    int n;
    cin>>n;
    for (ll i=1; i<=n; i++){
        ll output=choose2(i*i)-attack(i);
        cout<<output<<"\n";
    }
    return 0;

}