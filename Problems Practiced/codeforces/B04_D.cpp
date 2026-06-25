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
        int i=0; bool ans=1; vpi p;
        while(i<n){
            int temp=i;
            while(i<n && a[i]==0) i++;
            if(i!=temp) p.push_back({temp+1,i});
            if(i==n) break;
            temp=i; i++;
            while(i<n && a[i]==0) i++;
            if(i==n) {ans=0; break;}
            if((i-temp)%2==1 && a[i]==a[temp]) p.push_back({temp+1,i+1});
            else if((i-temp)%2==0 && a[i]!=a[temp]) p.push_back({temp+1,i+1});
            else p.push_back({temp+1,temp+1}),p.push_back({temp+2,i+1});
            i++;
        }
        if(ans) cout<<p.size()<<p<<"\n";
        else cout<<-1<<"\n";
    }
}
