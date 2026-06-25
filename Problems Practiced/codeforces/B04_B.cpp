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
    int t=1; //cin>>t;
    while(t--){
        int n,m; cin>>n>>m; vector<vector<int>> a(n,vector<int>(m)); cin>>a;
        int ans=0;
        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=0; j<m; j++){
                if(a[i][j]==1) ans+=temp,temp=0;
                else temp++;
            }
        }
        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=m-1; j>=0; j--){
                if(a[i][j]==1) ans+=temp,temp=0;
                else temp++;
            }
        }
        for(int j=0; j<m; j++){
            int temp=0;
            for(int i=0; i<n; i++){
                if(a[i][j]==1) ans+=temp,temp=0;
                else temp++;
            }
        }
        for(int j=0; j<m; j++){
            int temp=0;
            for(int i=n-1; i>=0; i--){
                if(a[i][j]==1) ans+=temp,temp=0;
                else temp++;
            }
        }
        cout<<ans<<"\n";
    }
}
