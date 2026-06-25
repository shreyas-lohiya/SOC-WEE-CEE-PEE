#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,i; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),c(n+1);
        for(int &e:a) cin>>e, e<=n && c[e]++;
        int x=1,l=0,r=n-1;
        while(x<=n && c[x]==1 && (a[l]==x || a[r]==x)) 
            a[l]==x ? l++: r--, x++;
        for(i=1; i<=n && c[i]==1; i++);
        cout<<(i>n);
        for(i=2; i<=n; i++) 
            cout<< (i<n-x+1 || (i==n-x+1 && c[x]==0) ? 0 : 1);
        cout<<endl;
    }
}
