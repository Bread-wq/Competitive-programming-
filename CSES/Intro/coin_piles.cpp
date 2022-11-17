#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        if (x>y*2 || y>x*2 || (x+y)%3!=0){
            cout<<"NO\n";
            continue;
        }
        else cout<<"YES\n";
    }
    return 0;
}