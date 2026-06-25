#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int ii=1; ii<=t; ii++){
        int n; cin>>n; vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
        int a=0; for(; a<n; a++) if(v[a]<a) break;
        int b=n-1; for(; b>=0; b--) if(v[b]<n-1-b) break;
        //cout<<"                            "<<n<<" "<<a<<" "<<b<<" "<<v[a-1]<<" "<<v[b+1]<<endl;
        if(b>=a) cout<<"No"<<endl;
        else if(n%2==0 && a==(n/2) && b==(n/2-1) && v[a-1]==n/2-1 && v[b+1]==n/2-1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
