#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;


int main(){
    bool arr[200001];
    memset(arr, 0, sizeof(arr));
    int n;
    cin>>n;
    for (int i=0; i<n-1; i++){
        int x;
        cin>>x;
        arr[x]=true;
    }
    for (int i=1; i<=n; i++){
        if (arr[i]==false){
            cout<<i;
            break;
        }
    }
    return 0;
}