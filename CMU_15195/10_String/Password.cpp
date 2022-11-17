#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main(){
    string s;
    cin>>s;
    int n=s.length();
    
    vector<int> prefix=prefix_function(s);
    // for (auto e:prefix){
    //     cout<<e<<" ";
    // }
    // cout<<"\n";
    int last=prefix[n-1];
    if (last==0 )  {
        cout<<"Just a legend";
        return 0;
    }

    for (int i=0; i<n-1; i++){
        if (prefix[i]==last){
            cout<< s.substr(0,last);
            return 0;
        }
    }
    if (prefix[last-1]==0) {
        cout<<"Just a legend";
        return 0;
    }

    for (int i=0; i<prefix[last-1]; i++){
        cout<<s[i];
    }
    

    return 0;
}