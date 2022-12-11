#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // odd number type of chocolate
    int N;
    
    ll ans=0;
    cin>>N;
    int min_c=INT_MAX;
    int count=0;
    for (int i=0; i<N; i++){
        int choc;
        cin>>choc;
        if (choc%2==0){
            choc--;
        }

        min_c=min(min_c,choc);
        ans+=choc;
    }
    if (ans%2==0){
        ans-=min_c;
    }
    cout<<ans;

}