#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m=1000000007;

// Computes a^b mod m
ll expmod (ll a, ll b) {
  if (b == 0) return 1;
  ll x = expmod (a, b>>1);
  ll xx = (x * x) % m;
  if ((b & 1) == 0) return xx; else return (a*xx) % m;
}
// Computes the modular inverse of x, modulo m
// Assumes that m is a prime number
ll inverse(int x) {
  return expmod(x, m-2);
}

// 2: 1
// 2 2: (3)!/2=3
// 2 2 1: (3)!/2!

// ans[i]=(sum+k-1)!/(sum! (k-1)!)*ans[i-1]
int main(){
    int n;
    long long ans=1, Ans=1;
    cin>>n;
    int sum=0;
    for (int i=0; i<n; i++){
        int k;
        ans=1;
        cin>>k;
        
        if (i>0 && k>1){
            for (int j=sum+1; j<sum+k; j++){
                ans=ans*j%m;
            }
            for (int j=2; j<=k-1; j++){
                ans=ans*inverse(j)%m;
                //ans=ans/j;
            }
            Ans=ans*Ans%m;
        }
        sum+=k;
        //cout<<' '<<ans<<"\n";
    }
    cout<<Ans;
}