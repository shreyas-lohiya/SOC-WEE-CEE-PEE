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
        int k; cin>>k; set<int> v; map<int,pii> m;
        for(int ii=0; ii<k; ii++){
            int sum=0; int n; cin>>n; vi a(n); for(auto &e:a) cin>>e,sum+=e;
            for(int i=0; i<n; i++){
                if(v.contains(sum-a[i])){
                    if(m[sum-a[i]].first!=ii+1){
                        cout<<"YES"<<endl;
                        cout<<m[sum-a[i]].first<<" "<<m[sum-a[i]].second<<endl;
                        cout<<ii+1<<" "<<i+1<<endl;
                        return 0;
                    }
                }
                else{
                    v.insert(sum-a[i]);
                    m[sum-a[i]]={ii+1,i+1};
                }
            }
        }
        cout<<"NO"<<endl;
    }
}
