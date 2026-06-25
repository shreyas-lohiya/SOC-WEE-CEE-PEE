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
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a=1; int ans=0;
        while(a<k && a<n){
            ans++; a*=2;
        }
        ans+=(max(n-a,0LL)+k-1)/k;
        cout<<ans<<endl;
    }
}
