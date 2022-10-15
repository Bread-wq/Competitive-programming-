#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long w,wo,wow;
// track number of w, wo, wow at the current position
// use single_v to check if the last letter is a single v
// wowwoww
// if next is w:
//     w+=1
//     wow+=wo
// if next is o:
//     wo+=w


int main(){
    string s;
    cin>>s;
    char prev='.';

    for (int i=0; i<s.size(); i++){
        if (s[i]=='v'){
            if (prev=='v'){
                w++;
                wow+=wo;
            }
        }
        else if (w!=0){
            wo+=w;
        }

        prev=s[i];
    }
    cout<<wow;

}
