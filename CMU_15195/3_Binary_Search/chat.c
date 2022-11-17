#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long first_half_sum(long long x){
    //cout<<"sum:"<<x*(x+1)/2;
    return x*(x+1)/2;
}

int bi_search(int k, long long x){
    int l=0;
    int r=k;
    int m=(l+r)/2;
    while (l<=r){
        //cout<<"search:"<<l<<' '<<r<<' '<<m<<"\n";
        if (first_half_sum(m)>=x){
            r=m-1;
        }
        else{
            l=m+1;
        }
        m=(l+r)/2;
    }
    return l;
}

int bi_search2(int k, long long x){
    int l=0;
    int r=k;
    int m=(l+r)/2;
    while (l<=r){
        //cout<<"search:"<<l<<' '<<r<<' '<<m<<"\n";
        if (first_half_sum(m)>x){
            r=m-1;
        }
        else if (first_half_sum(m)==x){
            return m+1;
        }
        else{
            l=m+1;
        }
        m=(l+r)/2;
    }
    return l;

}

int main(){
    int t;
    cin>>t;
    int k;
    long long x;
    long long s;
    for (int i=0; i<t; i++){
        cin>>k>>x;
        long long half=first_half_sum((long long)k);
        if (x<=half){
            // binary search the first half
            //cout<<"first half\n";
            cout<<bi_search(k, x)<<"\n";
        }
        else if (x>=(half*2-k)){
            cout<<2*k-1<<"\n";
        }
        else{
            // binary search the second half
            //cout<<"second half\n";
            x=half*2-k-x;
            cout<<2*k-bi_search2(k, x)<<"\n";
        }

    }

    return 0;

}


