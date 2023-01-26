#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,vector<int>>>  boxes;
    for (int i=0; i<n; i++){
        int l,w,h;
        cin>>l>>w>>h;
        // create an int tuple to store the dimensions
        vector<int> dim(3);
        dim[0]=l; dim[1]=w; dim[2]=h;
        int vol =l*w*h;
        sort(dim.begin(),dim.end());
        boxes.push_back({vol,dim});
    }
    int m;
    cin>>m;
    
    
    sort(boxes.begin(),boxes.end());


    for (int i=0; i<m; i++){
        int l,w,h;
        cin>>l>>w>>h;
        vector<int> dim(3);
        dim[0]=l; dim[1]=w; dim[2]=h;
        sort(dim.begin(),dim.end());
        bool fit=false;
        for (auto it:boxes){
            if (it.second[0]>=dim[0] && it.second[1]>=dim[1] && it.second[2]>=dim[2]){
                cout<<it.first<<endl;
                fit=true;
                break;
            }
        }
        if (!fit){
            cout<<"Item does not fit."<<endl;
            continue;
        }
    }

}

// 30: 5*6, 5*2+4*5
