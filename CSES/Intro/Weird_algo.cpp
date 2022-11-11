#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;


int main(){
    ll n;
    cin>>n;
    while (n!=1){
        cout<<n<<' ';
        if (n%2==0){
            n/=2;
        }
        else n=n*3+1;
    }    
    cout<<1;
    return 0;

}