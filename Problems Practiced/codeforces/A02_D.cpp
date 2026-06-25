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
        int n; cin>>n; 
        vi x(n),t(n); cin>>x>>t;
        int sum=x[0]+t[0], diff=t[0]-x[0];
        for(int i=1; i<n; i++) sum=max(sum,x[i]+t[i]), diff=max(diff,t[i]-x[i]);
        int ans=sum-diff;
        if (ans%2==0) cout<<ans/2<<endl;
        else cout<<ans/2<<".5"<<endl;
    }
}
