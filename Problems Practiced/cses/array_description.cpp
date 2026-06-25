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
    int big=1e9+7;
 
    int n,m,ans=1; cin>>n>>m;
    vi x(n); cin>>x; 
    for(int j=1; j<n; j++){
        if(x[j-1]!=0 && x[j]!=0 && abs(x[j]-x[j-1])>1) {cout<<0<<endl; return 0;} 
    }
    
    
    vi c(m);
    int i=0;
    while(i<n && x[i]==0) i++;
    if(i!=0 && i!=n) {
        for(auto &e:c) e=0;
        c[x[i]-1]++;
        int temp=i;
        while(temp--){
            vi d(m);
            for(int i=0; i<m; i++) {
                d[i]=(d[i]+c[i])%big;
                if(i+1<m) d[i]=(d[i]+c[i+1])%big;
                if(i-1>=0) d[i]=(d[i]+c[i-1])%big;
            }
            c=d;
        }
        int an=0;
        for(int i=0; i<m; i++) {
            an=(an+c[i])%big;
        }
        ans*=an; ans%=big;
    }
    else if (i==n) {
        ans=0;
        for(int ii=0; ii<m; ii++){
            for(auto &e:c) e=0;
            c[ii]++;
            int temp=n-1;
            while(temp--){
                vi d(m);
                for(int i=0; i<m; i++) {
                    d[i]=(d[i]+c[i])%big;
                    if(i+1<m) d[i]=(d[i]+c[i+1])%big;
                    if(i-1>=0) d[i]=(d[i]+c[i-1])%big;
                }
                c=d;
            }
            for(int i=0; i<m; i++) {
                ans=(ans+c[i])%big;
            }
        }
    }
    while(i<n){
        while(i<n && x[i]!=0) i++;
        int a=i; if(i==n) break;
        while(i<n && x[i]==0) i++;
        int b=i;    
        if(b==n){
            for(auto &e:c) e=0;
            c[x[a-1]-1]++;
            int temp=b-a;
            while(temp--){
                vi d(m);
                for(int i=0; i<m; i++) {
                    d[i]=(d[i]+c[i])%big;
                    if(i+1<m) d[i]=(d[i]+c[i+1])%big;
                    if(i-1>=0) d[i]=(d[i]+c[i-1])%big;
                }
                c=d;
            }
            int an=0;
            for(int i=0; i<m; i++) {
                an=(an+c[i])%big;
            }
            ans=(ans*an)%big;
        }
        else{
            for(auto &e:c) e=0;
            c[x[a-1]-1]++;
            int temp=b-a+1;
            while(temp--){
                vi d(m);
                for(int i=0; i<m; i++) {
                    d[i]=(d[i]+c[i])%big;
                    if(i+1<m) d[i]=(d[i]+c[i+1])%big;
                    if(i-1>=0) d[i]=(d[i]+c[i-1])%big;
                }
                c=d;
            }
            int an=c[x[b]-1];
            ans=(ans*an)%big;
        }
    }
    ans%=big;
    cout<<ans<<endl;
 
}
