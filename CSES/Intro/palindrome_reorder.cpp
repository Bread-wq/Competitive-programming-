#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,half;
    cin>>s;
    int odd_cnt=0, prev_pos=0;
    char center;
    int bit=0;
    sort(s.begin(),s.end());
    for (int i=0; i<s.length(); i++){
        if (i!=0 && s[i]!=s[i-1]){
            int len=i-prev_pos;
            prev_pos=i;
            if (len%2==1) {
                odd_cnt++;
                center=s[i-1];
                if (odd_cnt>1){
                    cout<<"NO SOLUTION";
                    return 0;
                }
            }
            else {
                if (bit){
                    half+=s[i];
                }
                bit=1-bit;
            } 
        }
        else{
            if (bit) half+=s[i];
            bit=1-bit;
        }
        
    }
    int len=s.length()-prev_pos;
            if (len%2==1) {
                odd_cnt++;
                center=s[s.length()-1];
                if (odd_cnt>1){
                    cout<<"NO SOLUTION";
                    return 0;
                }
            }
    if (odd_cnt==1){
        cout<<half<<center;
        reverse(half.begin(),half.end());
        cout<<half;
    }
    else{
        cout<<half;
        reverse(half.begin(),half.end());
        cout<<half;
    }
    return 0;
}