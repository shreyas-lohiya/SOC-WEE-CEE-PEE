#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int,int>;
using vpi = vector<pii>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define sortv(x) sort(all(x))
#define sortr(x) sort(rall(x))
#define sortp2(x) sort(all(x),[](const auto& a, const auto& b){if(a.second==b.second) return a.first<b.first; return a.second<b.second;})
#define sortp2r(x) sort(all(x),[](const auto& a, const auto& b){if(a.second==b.second) return a.first>b.first; return a.second>b.second;})
template<class T1, class T2>
istream& operator>>(istream& in, pair<T1,T2>& p){
    in >> p.first >> p.second;
    return in;
}
template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p){
    return out << " " << p.first << " " << p.second;
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
int ipow(int base, unsigned int exp) {
    int result = 1; int mod=998244353;
    while (exp > 0){
        if (exp & 1) {
            result*=base;
            result%=mod;
        }
        base*=base;
        base%=mod;
        exp/=2;
    }
    return result;
}
int find(int x, const vi& link) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b, const vi& link) {
    return find(a,link) == find(b,link);
}
void unite(int a, int b, vi& link, vi& size) {
    a = find(a,link);
    b = find(b,link);
    if (size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}
//segtreeeee
int IDENTITY=0;                     //changethis!!!!!!!
int segfunc(int a, int b){
    return a+b;                     //changethis!!!!!!!
}
int N; vi segtree;
void makesegtree(const int& n, const vi& a){
    N=bit_ceil((unsigned)n);
    segtree.assign(2*N, IDENTITY);
    for(int i=0;i<n;i++) 
        segtree[N+i]=a[i];
    for(int i=N-1;i>=1;i--)
        segtree[i]=segfunc(segtree[2*i],segtree[2*i+1]);
}
int query(int l, int r){
    l+=N; r+=N;
    int s=IDENTITY;
    while(l<=r){
        if(l%2==1) s=segfunc(s,segtree[l++]);
        if(r%2==0) s=segfunc(s,segtree[r--]);
        l/=2; r/=2;
    }
    return s;
}
void update(int k, int x){
    k+=N;
    segtree[k]=x;
    for(k/=2; k>=1; k/=2){
        segtree[k]=segfunc(segtree[2*k],segtree[2*k+1]);
    }
}
//segtree finish
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b; char temp1,temp2; cin>>m>>n; vector<vi> g(2*n+1),gt(2*n+1);
    while(m--){
        cin>>temp1>>a; 
        cin>>temp2>>b; 
        g[temp1=='-'?a:(a+n)].push_back(temp2=='-'?(b+n):b);
        gt[temp2=='-'?(b+n):b].push_back(temp1=='-'?a:(a+n));
        g[temp2=='-'?b:(b+n)].push_back(temp1=='-'?(a+n):a);
        gt[temp1=='-'?(a+n):a].push_back(temp2=='-'?b:(b+n));
    }
    vi ord; vb v(2*n+1); vi comp(2*n+1); int currcomp=0;
    auto dfs1 = [&](auto&& self, int node) -> void {
        v[node]=1;
        for(auto& child: g[node]){
            if(!v[child]) self(self,child);
        }
        ord.push_back(node);
    };
    auto dfs2 = [&](auto&& self, int node) -> void {
        comp[node]=currcomp;
        for(auto& child: gt[node]){
            if(!comp[child]) self(self,child);
        }
    };
    for(int i=1; i<=2*n; i++){
        if(!v[i]) dfs1(dfs1,i);
    }
    for(int i=2*n-1; i>=0; i--){
        if(!comp[ord[i]]){
            currcomp++;
            dfs2(dfs2,ord[i]);
        }
    }
    bool imp=0;
    for(int i=1; i<=n && !imp; i++) if(comp[i]==comp[i+n]) imp=1;
    if(imp) cout<<"IMPOSSIBLE";
    else{
        for(int i=1; i<=n; i++) cout<<((comp[i]>comp[i+n])?'+':'-')<<" ";
    }
}
