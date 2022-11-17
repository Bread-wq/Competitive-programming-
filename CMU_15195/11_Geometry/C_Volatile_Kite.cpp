#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    vector<pair<long double, long double>> points;
    cin>>n;
    long double min_dist=double(INT_MAX);
    for (int i=0; i<n; i++){
        long double x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    for (int i=0; i<points.size(); i++){
        pair<long double,long double> left,mid,right;
        left=points[i];
        mid=points[(i+1)%points.size()];
        right=points[(i+2)%points.size()];
        long double AC,AB,BC,BD, s, Area;
        AB=sqrt((left.first-mid.first)*(left.first-mid.first)+(left.second-mid.second)*(left.second-mid.second));
        BC=sqrt((right.first-mid.first)*(right.first-mid.first)+(right.second-mid.second)*(right.second-mid.second));
        AC=sqrt((left.first-right.first)*(left.first-right.first)+(left.second-right.second)*(left.second-right.second));
        // Heron's formula... finally actually using it outside of math olympiads
        s=(AB+BC+AC)/2;
        Area=sqrt(s*(s-AB)*(s-BC)*(s-AC));
        BD=Area/AC;
        //cout<<"AB "<<AB<<" BC "<<BC<<" AC "<<AC<<" BD "<<BD<<"\n";
        min_dist=min(min_dist,BD);
    }
    cout<<fixed<<setprecision(9)<<min_dist;
    return 0;

}