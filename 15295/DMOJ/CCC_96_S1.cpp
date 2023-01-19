#include <bits/stdc++.h>
using namespace std;

int proper_divisor(int x){
    int sum=0;
    for (int i=1; i<=x/2; i++){
        if (x%i==0) sum+=i;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        int sum=proper_divisor(a);
        if (sum==a){
            cout<<a<<" is a perfect number.\n";
        }
        else if (sum<a){
            cout<<a<<" is a deficient number.\n";
        }
        else{
            cout<<a<<" is an abundant number.\n";
        }
    }
    return 0;
}
