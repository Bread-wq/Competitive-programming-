#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int> swift,sema;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        if (i==0)
            swift.push_back(x);
        else
            swift.push_back(x+swift[i-1]);
    }
    int prefix=0;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        prefix+=x;
        if (prefix==swift[i]){
            ans=i+1;
        }
        
    }

    cout<<ans<<endl;
}

// 30: 5*6, 5*2+4*5
