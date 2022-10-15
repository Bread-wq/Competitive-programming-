#include <cstdio>
#include <iostream>
using namespace std;

int A[100005], n;
void print_A(){
    for (int i=0; i<n; i++)
        cout<<A[i]<<' ';
    cout<<"\n";
}
bool check_pos(int t){
    int B[100005];
    for (int i=0; i<n; i++){
        B[i]=A[i];
    }
    for (int i=0; i<n; i++){
        // keep track of the left most *
        if (B[i]==1){
            for (int j=max(0,i-t); j<min(i+t+1,n);j++){
                if (B[j]==-1)
                    B[j]=0;
            }
        }
    }

    for (int i=0; i<n; i++){
        //cout<<A[i]<<' ';
        if (B[i]<0) return false;
    }
    return true;
}

int bi_search(){
    int l=0;
    int r=n;
    int m=(l+r)/2;
    while (l<=r){
        //cout<<"search:"<<l<<' '<<r<<' '<<m<<"\n";
        if (check_pos(m)){
            r=m-1;
        }
        else{
            l=m+1;
        }
        m=(l+r)/2;
    }
    return l;
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        char c;
        cin>>c;
        if (c=='*'){
            A[i]=-1;
        }
        else if (c=='P'){
            A[i]=1;
        }
    }
    print_A();
    cout<<bi_search();
    return 0;
}