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
        int n,m; cin>>n>>m;
        string s; cin>>s;
        vi ans(26),p(m);
        cin>>p;
        sort(p.begin(),p.end());
        vector<int> c(n); int a=0; int b=0;
        for(; a<n; a++){
            while(b<m && p[b]<=a) b++;
            c[a]=m-b;
        }
        
        for(int i=0; i<n; i++){
            
            ans[s[i]-'a']+=(c[i]+1);
        }
        cout<<ans; cout<<endl;
    }
}
