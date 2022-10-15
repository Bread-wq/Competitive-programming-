#include <cstdio>
#include <iostream>
using namespace std;

int A[101][101],ref[101][101];
int n,m;

void update(int x, int y){
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            if ((x+i)>=0 && (x+i)<n && (y+j)>=0 && (y+j)<m){
                ref[x+i][y+j]++;
            }
        }
    }

    ref[x][y]=-100;
    return;
} 

int main(){
    cin>>n;
    cin>>m;
    bool ans=true;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ref[i][j]=0;
            A[i][j]=0;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char c;
            cin>>c;
            if (c=='*'){
                update(i,j); //update the 8 squres around i,j in ref
                A[i][j]=-100;
            }
            else if (c=='.'){
                A[i][j]=0;
            }
            else {
                A[i][j]= c-'0';
            }

        }

    }
    /* debug output
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<ref[i][j];
        }
        cout<<"\n";
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<A[i][j];
        }
        cout<<"\n";
    }
    */

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (A[i][j]!=ref[i][j] && A[i][j]>=0)
                ans=false;
        }
    }
    if (ans==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}