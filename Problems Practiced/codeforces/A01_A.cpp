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
        int a,b,c; cin>>a>>b>>c;
        int r=abs(b-a);
        if (b>2*r || a>2*r || c>2*r) {cout<<-1<<endl;}
        else {
            if (c<=r) cout<<c+r<<endl;
            else cout<<c-r<<endl;
        }
        
    }
}
