#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n;
double A[100005];
bool B[100005]; //record if A[i] is int
int main(){
    cin>>n;
    long long count=0; // number of round up
    long long sum=0, diff;
    for (int i=0; i<n; i++){
        cin>>A[i];
        if (fabs(floor(A[i])-ceil(A[i]))<=1e-9){
            B[i]=true;
        }
        else B[i]=false;
        sum+=floor(A[i]);
    }
    
    diff=-sum;
    for (int i=0; i<n; i++){
        if (!B[i] && count<diff){ // if A[i] is not an int
            cout<<(int)(ceil(A[i]))<<"\n";
            count++;
        }
        else cout<<(int)(floor(A[i]))<<"\n";
    }

    return 0;
}