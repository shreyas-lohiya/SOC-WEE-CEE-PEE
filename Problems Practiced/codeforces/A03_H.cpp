#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pii = pair<int,int>;
using vpi = vector<pii>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define sortv(x) sort(all(x))
#define rsort(x) sort(rall(x))
template<class T1, class T2>
istream& operator>>(istream& in, pair<T1,T2>& p){
    in >> p.first >> p.second;
    return in;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p){
    return out << p.first << " " << p.second;
}
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
        int n,m; cin>>n>>m;
        vi a(n); cin>>a; map<int,int> mm; vi lc(n,-1);
        for(int i=0; i<m; i++){
            int p,v; cin>>p>>v; p--;
            if(mm.contains(a[p])) mm[a[p]]+=i-lc[p];
            else mm[a[p]]=i-lc[p];
            lc[p]=i;
            a[p]=v;
        }
        for(int p=0; p<n; p++){
            if(mm.contains(a[p])) mm[a[p]]+=m-lc[p];
            else mm[a[p]]=m-lc[p];
        }
        
        int ans=0;
        for (const auto& [key,x] : mm) {
            ans+=x*(x-1)/2+x*(m+1-x);
        }
        cout<<ans<<endl;
    }
}
