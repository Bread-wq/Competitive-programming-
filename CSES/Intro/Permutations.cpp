#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

int main(){
    int n;
    cin>>n;
    if (n==1)  cout<<1;
    else if (n<4){
        cout<<"NO SOLUTION";
    }
    else if (n==4){
        cout<<"3 1 4 2";
    }
    else{
        for (int i=1; i<=n/2; i++){
            cout<<2*i-1<<" ";
        }
        if (n%2==1){
            cout<<n<<" ";
        }
        for (int i=1; i<=n/2; i++){
            cout<<2*i<<" ";
        }
    }
    return 0;
}