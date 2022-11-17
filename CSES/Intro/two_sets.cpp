#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

/*
1 2 3 4 5 6 7
(x+1)*x >= sum
(x-1)*x <= sum
*/
// a smarter solution is to pair the 1st and 4th, 2nd and 3rd of every 4 numbers
int main(){
    ll n;
    cin>>n;
    ll sum=n*(n+1)/2;
    if (sum%2){
        cout<<"NO";
        return 0;
    }
    else {
        cout<<"YES\n";
        ll half=sum/2;
        ll total=0, ctr=0;
        vector<int> set_1;
        while (total<half){
            total+=(n-ctr);
            set_1.push_back(n-ctr);
            ctr++;
        }
        if (total==half) {
            cout<<ctr<<"\n";
            for (auto x : set_1){
                cout<<x<<" ";
            }
            cout<<"\n"<<n-ctr<<"\n";
            for (int i=1; i<=n-ctr; i++){
                cout<<i<<" ";
            }
        }

        // total > half
        // need to - ctr
        else{
            set_1.pop_back();
            total-=(n+1-ctr);
            int x=half-total;
            set_1.push_back(x);
            cout<<ctr<<"\n";
            for (auto i: set_1){
                cout<<i<<" ";
            }
            cout<<"\n"<<n-ctr<<"\n";
            for (int i=1; i<=n+1-ctr; i++){
                if (i!=x) cout<<i<<" ";
            }

        }
        return 0;
    }
}