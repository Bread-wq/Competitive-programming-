#include <cstdio>
#include <iostream>
using namespace std;

int n, A[1000000];
int main(){
    cin>>n;
    bool ans=true;
    for (int i=0; i<n; i++){
        cin>>A[i];
    }
    for (int i=1; i<n-1; i++){
        if (A[i]<A[i-1] && A[i]<A[i+1])
            ans=false;
    }
    if (ans==true){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}
