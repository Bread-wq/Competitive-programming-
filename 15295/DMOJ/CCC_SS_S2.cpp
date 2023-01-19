#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,G;
    int ans=0;
    unordered_map<string, int> grp;
    vector<pair<string,string>> tgt,hate;
    cin>>X;
    for (int i=0; i<X; i++){
        string a,b;
        cin>>a>>b;
        tgt.push_back({a,b});
    }
    cin>>Y;
    for (int i=0; i<Y; i++){
        string a,b;
        cin>>a>>b;
        hate.push_back({a,b});
    }
    cin>>G;
    for (int i=1; i<=G; i++){
        string a,b,c;
        cin>>a>>b>>c;
        grp[a]=i; grp[b]=i; grp[c]=i;
    }

    for (auto p:tgt){
        if (grp[p.first]!=grp[p.second]) ans++;
    }
    for (auto p:hate){
        if (grp[p.first]==grp[p.second]) ans++;
    }
    
    cout<<ans;
    return 0;
}

