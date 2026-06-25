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
#define sortr(x) sort(rall(x))
template<class T1, class T2>
istream& operator>>(istream& in, pair<T1,T2>& p){
    in >> p.first >> p.second;
    return in;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p){
    return out << "\n" << p.first << " " << p.second;
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
        int n; cin>>n; vi a(n); cin>>a;
        vi b(n); b[0]=a[0]; for(int i=1; i<n; i++) b[i]=b[i-1]+a[i];
        int i=0,ans=0; map<int,int> f;
        while(i<n && a[i]!=0) {if(b[i]==0) ans++; i++;}
        while(i<n){
            f[b[i]]++; i++;
            while(i<n && a[i]!=0) (f[b[i]]++,i++);
            int temp=0;
            for(const auto& pair: f) temp=max(temp,pair.second);
            ans+=temp;
            f.clear();
        }
        cout<<ans<<"\n";
    }
}
