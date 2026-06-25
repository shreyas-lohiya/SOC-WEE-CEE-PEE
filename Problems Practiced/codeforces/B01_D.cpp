#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int ii=1; ii<=t; ii++){
        int n; cin>>n;  vector<double> x,y;
        for(int i=0; i<2*n; i++){
            int a,b; cin>>a>>b;
            if(a==0) {y.push_back(abs(b));}
            else {x.push_back(abs(a));}
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        double ans=0;
        for(int i=0; i<n; i++){
            //cout<<"                 "<<x[i]<<" "<<y[i]<<endl;
            ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
        }
        printf("%.15f\n",ans);
    }
}
