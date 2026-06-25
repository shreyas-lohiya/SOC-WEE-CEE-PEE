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
        int n; cin>>n; vi a(n); cin>>a;
        int sum=0; for(auto &e:a) sum+=e;
        bool done=0;
        int p=0;
        for(int i=0; i<n-1 && !done; i++){
            p+=a[i];
            if(p>=sum) {cout<<"NO"<<endl; done=1;}
        }
        int s=0;
        for(int i=n-1; i>0 && !done; i--){
            s+=a[i];
            if(s>=sum) {cout<<"NO"<<endl; done=1;}
        }
        if(!done) cout<<"YES"<<endl;
    }
}
