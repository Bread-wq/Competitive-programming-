#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

//k: position
//m: pillow
//n: people

//1 2 3 4 5 6 7 8
//1 1 1 2 3 2 1 1
//m-2 m-1 m m-1

//1 2 3 4 5 6 7 8
//2 3 4 5 6 7 6 5
long long calc(long long k, long long x, long long n){
    long long l_sum, r_sum;
    if (x<=k){
        l_sum=x*(x+1)/2+(k-x);
    }
    else{
        l_sum=k*(2*x-k+1)/2;
    }
    if (x<=(n-k)){
        r_sum=(x-1)*(x)/2+(n-k-x+1);
    }
    else{
        r_sum=(n-k)*(x-1+x-(n-k))/2;
    }
    //cout<<l_sum<<' '<<r_sum<<"\n";
    return l_sum+r_sum;
}

int bi_search(int l, int r, int k, int n, int m){
    int mid= l+(r-l)/2;
    while (l<=r){
        //cout<<"search:"<<l<<' '<<r<<' '<<mid<<"\n";
        if (calc(k, mid, n)>m){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        mid=l+(r-l)/2;
    }
    return l-1;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    // binary search for the max m
    // left=0 right=(m-n)
    cout<<bi_search(1, m-n+1, k, n, m);
    return 0;
}

