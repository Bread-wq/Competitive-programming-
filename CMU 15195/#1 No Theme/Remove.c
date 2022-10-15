#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int n, A[100005], val[100005];
int main(){
    cin>>n;
    set<int> mySet; 
    //prev(mySet.end(),2) gives the 2nd last element
    for (int i=0; i<n; i++){
        cin>>A[i];
        val[i]=0;
    }
    int m=-1; // max record so far
    //mySet.insert(A[0]);
    //val[A[0]]=-1;
    for (int i=0; i<n; i++){
        mySet.insert(A[i]);
        if (A[i]==*prev(mySet.end())){
            val[A[i]]--;
        }
        else if (A[i]==*prev(mySet.end(),2)){
            val[*prev(mySet.end())]++;
            //cout<<A[i];
        }
        
    }
    //cout<<"\n";
    int ans=1;
    for (int i=1; i<=n; i++){
        //cout<<val[i]<<" ";
        if (m<val[i]){
            m=val[i];
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}

//2 3 4 1 8 9 5 6 7
//y y y 3 y y 2 2 2

// check if A[i] is a record
// check how many more records we will have if we remove A[i]
