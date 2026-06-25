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
        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        if((a+c-1)/c+(b+d-1)/d >k ) cout<<-1<<endl;
        else cout<<(a+c-1)/c<<" "<<(b+d-1)/d<<endl;
    }
}
