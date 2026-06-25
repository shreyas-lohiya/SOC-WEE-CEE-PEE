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
        int n; cin>>n; vi a(n); cin>>a;
        int currsum=0,count=0; multiset<int> s;
        for(int i=0; i<n; i++){
            if(a[i]>=0) currsum+=a[i],count++;
            else if (currsum+a[i]>=0) currsum+=a[i],count++,s.insert(a[i]);
            else if (a[i]>*s.begin()) currsum+=a[i]-*s.begin(),s.erase(s.begin()),s.insert(a[i]);
        }
        cout<<count<<endl;
    }
}
