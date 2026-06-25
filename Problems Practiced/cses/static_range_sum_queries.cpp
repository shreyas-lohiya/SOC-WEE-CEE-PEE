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
signed main(){
    int n,q,a,b; cin>>n>>q;
    vi x(n); cin>>x;
    vi prefsum(n+1); prefsum[0]=0;
    for(int i=0; i<n; i++) prefsum[i+1]=prefsum[i]+x[i];
    while(q--) cin>>a>>b, cout<<prefsum[b]-prefsum[a-1]<<endl;
}
