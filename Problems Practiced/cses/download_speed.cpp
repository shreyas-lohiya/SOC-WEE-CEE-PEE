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
    int result = 1; int mod=1e9+7;
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
//segtreeeee
const int IDENTITY = 0;
int segadd(int a, int b) { return gcd(a,b); }
int segmult(int val, int len) { return val; }
int N; vi segtree, lazy_A, lazy_B; bool lazy=0;
void makesegtree(const int& n, const vi& a, bool laz){
    N = bit_ceil((unsigned)n);
    segtree.assign(2*N,IDENTITY);
    lazy=laz;
    if(lazy) lazy_A.assign(2*N,1);
    if(lazy) lazy_B.assign(2*N,0);
    for(int i=0; i<n; i++) segtree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) segtree[i]=segadd(segtree[2*i],segtree[2*i+1]);
}
void push(int k, int x, int y){
    if(lazy_A[k]==1 && lazy_B[k]==0) return;
    segtree[k]=lazy_A[k]*segtree[k]+segmult(lazy_B[k],y-x+1);
    if(x!=y){
        lazy_B[2*k]=lazy_A[k]*lazy_B[2*k]+lazy_B[k]; lazy_A[2*k]=lazy_A[k]*lazy_A[2 * k];
        lazy_B[2*k+1]=lazy_A[k]*lazy_B[2*k+1]+lazy_B[k]; lazy_A[2*k+1]=lazy_A[k]*lazy_A[2*k+1];
    }
    lazy_A[k]=1; lazy_B[k]=0;
}
void update_op_lazy(int l, int r, int A, int B, int k = 1, int x = 0, int y = N-1){
    push(k, x, y); 
    if(r<x||l>y) return;
    if(l<=x&&y<=r) {
        lazy_A[k]=A; lazy_B[k]=B;
        push(k, x, y); 
        return;
    }
    int d=(x+y)/2;
    update_op_lazy(l,r,A,B,2*k,x,d); 
    update_op_lazy(l,r,A,B,2*k+1,d+1,y);
    segtree[k]=segadd(segtree[2*k],segtree[2*k+1]);
}
void update_add(int l, int r, int v) { update_op_lazy(l, r, 1, v); }
void update_assign(int l, int r, int v) { update_op_lazy(l, r, 0, v); }
void update_add(int l, int v) { 
    int k=l+N;
    segtree[k]+=v;                  
    for(k/=2; k>=1; k/=2){
        segtree[k]=segadd(segtree[2*k],segtree[2*k+1]);
    }
}
void update_assign(int l, int v) { 
    int k=l+N;
    segtree[k]=v;                  
    for(k/=2; k>=1; k/=2){
        segtree[k]=segadd(segtree[2*k],segtree[2*k+1]);
    }
}
int query(int l, int r, int k = 1, int x = 0, int y = N-1){
    if(lazy) { push(k, x, y);
    if(r<x||l>y) return IDENTITY;
    if(l<=x&&y<=r) return segtree[k];
    int d=(x+y)/2;
    return segadd(query(l,r,2*k,x,d),query(l,r,2*k+1,d+1,y)); }
    l += N;
    r += N;
    int ans = IDENTITY;
    while(l <= r){
        if(l & 1) ans = segadd(ans, segtree[l++]);
        if(!(r & 1)) ans = segadd(ans, segtree[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}
//segtree finish
//hld
vector<int> parent, depth, heavy, head, pos;
int cur_pos;
int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}
void hld_init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;
    parent[1] = 1;
    depth[1] = 0;
    dfs(1, adj);
    decompose(1, 1, adj);
}
//hld finish
//max flow
const int inf = 1e18;
int n;
vector<vector<int>> capacity, flow, adj;
vector<int> height, excess;
void push(int u, int v)
{
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}
void relabel(int u)
{
    int d = inf;
    for (int i = 0; i < n; i++) {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}
vector<int> find_max_height_vertices(int s, int t) {
    vector<int> max_height;
    for (int i = 0; i < n; i++) {
        if (i != s && i != t && excess[i] > 0) {
            if (!max_height.empty() && height[i] > height[max_height[0]])
                max_height.clear();
            if (max_height.empty() || height[i] == height[max_height[0]])
                max_height.push_back(i);
        }
    }
    return max_height;
}
int max_flow(int s, int t)
{
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<int>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (int i = 0; i < n; i++) {
        if (i != s)
            push(s, i);
    }
 
    vector<int> current;
    while (!(current = find_max_height_vertices(s, t)).empty()) {
        for (int i : current) {
            bool pushed = false;
            for (auto& j: adj[i]) {
                if(!excess[i]) break;
                if (capacity[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed) {
                relabel(i);
                break;
            }
        }
    }
    return excess[t];
}
//max flow finish
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; int m,a,b,c; cin>>m;
    capacity.assign(n, vi(n,0));
    adj.assign(n, vi(0));
    while(m--){
        cin>>a>>b>>c;
        a--; b--;
        capacity[a][b]+=c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<max_flow(0,n-1);
}
