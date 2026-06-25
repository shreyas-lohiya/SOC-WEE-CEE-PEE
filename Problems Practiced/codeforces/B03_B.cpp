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
    int t=1; //cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vi p(n),f; cin>>p; sortv(p);
        multiset<string> ms; string s;
        for(int i=0; i<m; i++){
            cin>>s;
            ms.insert(s);
        }
        auto it = ms.begin();
        while (it != ms.end()) {
            auto range = ms.equal_range(*it);
            auto count = std::distance(range.first, range.second);
            f.push_back(count);
            it = range.second;
        }
        rsort(f); int ans1=0,ans2=0;
        for(int i=0; i<f.size(); i++) ans1+=f[i]*p[i];
        rsort(p); 
        for(int i=0; i<f.size(); i++) ans2+=f[i]*p[i];
        cout<<ans1<<" "<<ans2<<endl;
    }
}
