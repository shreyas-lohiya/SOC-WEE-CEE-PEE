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
        for(int i=1; i<=2*k-n-1; i++) cout<<i<<" ";
        for(int i=2*k-n; i<=k; i++) cout<<3*k-n-i<<" ";
        cout<<endl;
    }
}
