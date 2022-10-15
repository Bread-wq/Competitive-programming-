#include <bits/stdc++.h>
using namespace std;

int ans=0;
//int diagonal1[2001]; // diff
//int diagonal2[2001]; // sum
map<int,int> A,B;


int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if (A.find(a-b)==A.end())
            A[a-b]=1;
        else A[a-b]+=1;

        if (B.find(a+b)==B.end())
            B[a+b]=1;
        else B[a+b]+=1;
    }

    map<int, int>::iterator it;
    for (it=A.begin(); it!=A.end(); it++){
        int val=it->second;
        //cout<<it->first<<val<<"\n";
        ans+=(val)*(val-1)/2;
    }
    for (it=B.begin(); it!=B.end(); it++){
        int val=it->second;
        //cout<<it->first<<val<<"\n";
        ans+=(val)*(val-1)/2;
    }

    cout<<ans;
}