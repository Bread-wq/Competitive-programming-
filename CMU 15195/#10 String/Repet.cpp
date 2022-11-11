#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 2; 
const int m = 1e9 + 9;

int rabin_karp(string const& s, string const& t, vector<ll> p_pow, vector<ll> h) {
    int S = s.size(), T = t.size();
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - '0' + 1) * p_pow[i]) % m; 

    int occurences=0;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences++;
    }
    return occurences;
}

int main(){
    string s;
    cin>>s;
    int n=s.length();

    vector<long long> p_pow(n); 
    p_pow[0] = 1; 
    
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0); 
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - '0' + 1) * p_pow[i]) % m; 

    //int ans=1;
    for (int i=1; i<n; i++){
        if (n%i!=0) continue;
        int m=n/i;
        string sub=s.substr(0,i);
        int occurences=rabin_karp(sub,s, p_pow, h);
        if (occurences==m){
            cout<<m;
            return 0;
        }
        //cout<<i<<" "<<occurences<<' '<<m<<"\n";
    }
    cout<<1;
    return 0;
}