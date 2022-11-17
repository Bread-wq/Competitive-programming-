#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

stack<int> nodes;
int n;

int main(){
    cin>>n;
    for (int i=0; i<2*n; i++){
        string s;
        int v;
        cin>>s>>v;
        if (s=="in"){
            nodes.push(v);
        }
        else {
            nodes.pop();
            if (!nodes.empty())
                cout<<nodes.top()<<' '<<v<<"\n";
        }

    }
    return 0;

}