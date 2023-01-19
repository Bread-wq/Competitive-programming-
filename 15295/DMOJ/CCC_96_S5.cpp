#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int test=0; test<n; test++){
        int len;
        cin>>len;
        int max_dist=0;
        vector<int> X,Y;
        for (int i=0; i<len; i++){
            int a;
            cin>>a;
            X.push_back(a);
        }
        for (int i=0; i<len; i++){
            int a;
            cin>>a;
            Y.push_back(a);
        }
        int ptr1=0, ptr2=0;
        while (ptr1<len && ptr2<len){
            while (ptr2<len && Y[ptr2]>=X[ptr1] ){
                ptr2++;
            }
            max_dist=max(ptr2-ptr1-1,max_dist);
            ptr1++;
        }


        cout<<"The maximum distance is "<<max_dist<<"\n";

    }
    return 0;
}
