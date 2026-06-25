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
        int n,k; cin>>n>>k; vi a(n); cin>>a; sortv(a);
        int l=0,r=n-1,ans=a[r]-a[l];
        if(a[l]<a[r]){
            while(a[l]==a[0]) l++; l--;
            while(a[r]==a[n-1]) r--; r++;
        }
        while(l<r && a[l]<a[r]){
            if(l+1<=n-r){
                ans-=min(k/(l+1),a[l+1]-a[l]);
                k-=(l+1)*min(k/(l+1),a[l+1]-a[l]);
                if(k<(l+1)) break;
                if(a[l+1]==a[r]) break;
                int temp=a[l+1]; 
                l++;
                while(a[l]==temp) l++; l--;
            }
            else{
                ans-=min(k/(n-r),a[r]-a[r-1]);
                k-=(n-r)*min(k/(n-r),a[r]-a[r-1]);
                if(k<(n-r)) break;
                if(a[l]==a[r-1]) break;
                int temp=a[r-1]; 
                r--;
                while(a[r]==temp) r--; r++;
            }
        }
        cout<<ans<<"\n";
    }
}
