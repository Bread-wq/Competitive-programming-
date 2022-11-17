#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
// 1, 4 2
// 1 4 2

// 1, 4 2, 5
// 1, 4 2 5
// 1 4 2 5
// 1 4 2, 5
// 1 4, 2 5 *
// 1, 4, 2 5  *

// 1, 4, 2 5 3
// 1, 4 2, 5 3
// 1, 4 2 5 3
// 1 4, 2 5 3
// 1 4 2, 5 3
// 1 4 2 5 3



// N villages
// beacon = max(increasing subseq)

// B[i]=B[i-1]*2+ middle+1 if A[i]>max(A[0:i-1]), middle=0
//  or = B[i-1], middle+=1
int m=1000000007;
int main(){
    int N;
    cin>>N;
    int A[N+1];
    long long B[N+1];
    int ans=0, high=0;
    long long middle=0;
    B[0]=0; 
    for (int i=0; i<N; i++){
        cin>>A[i];
        if (A[i]<high){
            middle+=1;
            B[i+1]=B[i];
        }
        else{
            high=A[i];
            B[i+1]=B[i]*(2+middle)%m;
            middle=0;
            if (i==0) B[1]=1;
        }
        //cout<<B[i];
    }
    cout<<B[N];

}