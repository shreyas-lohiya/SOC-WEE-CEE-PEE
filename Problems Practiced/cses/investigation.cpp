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
    int n,m,a,b,w; cin>>n>>m; vector<vpi> g(n+1);
    while(m--){
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    int mod=1e9+7;
    vi distance(n+1,1e18),count(n+1,0),maxnode(n+1,0),minnode(n+1,1e18); vector<bool> processed(n+1); priority_queue<pair<int,pair<int,int>>> q;
    count[0]=1; 
    minnode[0]=-1;
    maxnode[0]=-1;
    distance[1] = 0;
    q.push({0,{1,0}});
    while (!q.empty()) {
        int a = q.top().second.first; 
        if (processed[a]) {q.pop(); continue;}
        processed[a]=1;
        while(!q.empty() && q.top().second.first==a && q.top().first==-distance[a]){
            count[a]+=count[q.top().second.second]; count[a]%=mod;
            minnode[a]=min(minnode[a],minnode[q.top().second.second]+1);
            maxnode[a]=max(maxnode[a],maxnode[q.top().second.second]+1);
            q.pop();
        }
        for (auto u : g[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w <= distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],{b,a}});
            }
        }
    }
    cout<<distance[n]<<" "<<count[n]<<" "<<minnode[n]<<" "<<maxnode[n];
 
}
