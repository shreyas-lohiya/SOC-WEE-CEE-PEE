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
        int n,m,k; cin>>n>>m>>k;
        if(k>3) cout<<0<<endl;
        else if (k==1) cout<<1<<endl;
        else if (k==3) cout<<max(0LL,m-m/n-(n-1))<<endl;
        else if (k==2) cout<<m/n+min(m,(n-1))<<endl;

    }
}
