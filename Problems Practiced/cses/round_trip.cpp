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
#define sortp2(x) sort(all(x),[](const auto& a, const auto& b){if(a.second==b.second) return a.first<b.first; return a.second<b.second;})
#define sortp2r(x) sort(all(x),[](const auto& a, const auto& b){if(a.second==b.second) return a.first>b.first; return a.second>b.second;})
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
int solve(int node, int parent, const vector<vi>& adj, vi& a, vi& sum){
    sum[node]=a[node];
    for(auto &e: adj[node]){
        if(e!=parent) {
            solve(e,node,adj,a,sum);
            sum[node]+=sum[e];
        }
    }
    return sum[node];
}
void solvecost(int node, int parent, const vector<vi>& adj, vi& a, vi& sum, vi& cost){
    if(node!=1) cost[node]=cost[parent]+sum[1]-2*sum[node];
    for(auto &e: adj[node]){
        if(e!=parent) {solvecost(e,node,adj,a,sum,cost);}
    }
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
int prevfind(int x, const vi& prevlink) {
    while (x != prevlink[x]) x = prevlink[x];
    return x;
}
bool prevsame(int a, int b, const vi& prevlink) {
    return prevfind(a,prevlink) == prevfind(b,prevlink);
}
void prevunite(int a, int b, vi& prevlink, vi& prevsize) {
    a = prevfind(a,prevlink);
    b = prevfind(b,prevlink);
    if (prevsize[a] < prevsize[b]) swap(a,b);
    prevsize[a] += prevsize[b];
    prevlink[b] = a;
}
void dfs(int node,vi& p, const vector<vi>& adj, vi& num){
    num[node]++;
    for(auto &c: adj[node]){
        if(c!=p[node]){
            p[c]=node;
            dfs(c,p,adj,num);
            num[node]+=num[c];
        }
    }
}
bool check(int n){
    set<int> s;
    while(n!=0){
        s.insert(n%10); n/=10;
    }
    return s.size()<3;
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
    int n,m,a,b; cin>>n>>m;
    vector<vi> g(n+1);
    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi visited(n+1); vi ans; bool cycle=0; bool unfinished=1;
    auto dfs = [&](auto&& self, int node, int parent) -> void {
        visited[node]=1;
        for(auto& child: g[node]){
            if(ans.size()!=0) {if(ans.back()!=ans[0]) ans.push_back(node); return;}
            if(child!=parent){
                if(visited[child]) {ans.push_back(child); ans.push_back(node); return;}
                else self(self,child,node);
            }
        }
        if(ans.size()!=0) {if(ans.back()!=ans[0]) ans.push_back(node); return;}
    };
    for(int i=1; i<=n; i++){
        if(ans.size()!=0) break;
        else if(!visited[i]) dfs(dfs,i,0);
    }
    if(ans.size()==0) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<ans.size()<<"\n"<<ans<<"\n";
}
