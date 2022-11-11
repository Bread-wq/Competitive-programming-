#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

int main(){
    string s;
    cin>>s;
    int ans=1;
    int cur=1;
    char prev=s[0];
    for (int i=1; i<s.length(); i++){
        if (prev==s[i]){
            cur+=1;
        }
        else {
            prev=s[i];
            ans=max(ans,cur);
            cur=1;
        }

    }
    ans=max(ans,cur);
    cout<<ans;
    return 0;
}