#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // 2007 2 27
    for (int i=0; i<n; i++){
        int year,mon,day;
        cin>>year>>mon>>day;
        if (year<1989){
            cout<<"Yes"<<endl;
        }
        else if (year==1989){
            if (mon<2){
                cout<<"Yes"<<endl;
            }
            else if (mon==2){
                if (day<=27){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
