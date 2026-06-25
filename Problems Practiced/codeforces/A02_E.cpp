#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto &x:v) in>>x;
    return in;
}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for(auto &x:v) out<<x<<" ";
    return out;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--){
        int n,T,a,b; cin>>n>>T>>a>>b; 
        vector<pair<int,int>> tt(n);  for( auto &e:tt) cin>>e.second; for( auto &e:tt) cin>>e.first;
        sort(tt.begin(),tt.end());
        vi don(n+1),easy(n+1),hard(n+1);
        for(int i=1; i<=n; i++){
            don[i]=don[i-1]+(tt[i-1].second?b:a);
            easy[i]=easy[i-1]+(tt[i-1].second?0:1);
            hard[i]=hard[i-1]+(tt[i-1].second?1:0);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(don[i]<tt[i].first) {
                int currans = i;
                int remaining = tt[i].first-1-don[i];
                currans+=min(remaining/a,easy[n]-easy[i]);
                remaining-=a*min(remaining/a,easy[n]-easy[i]);
                currans+=min(remaining/b,hard[n]-hard[i]);
                remaining-=b*min(remaining/b,hard[n]-hard[i]);
                ans=max(ans,currans);
            }
        }
        if(don[n]<=T) {
            ans=max(ans,n);
        }
        cout<<ans<<endl;
    }
}
