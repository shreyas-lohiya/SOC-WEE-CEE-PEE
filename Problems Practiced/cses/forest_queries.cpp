#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
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
signed main(){
    int n,q; cin>>n>>q; char temp;
    vector<vector<int>> v(n,vector<int>(n));
    for(auto &l:v) for(auto &e:l) cin>>temp, e=((temp=='*')?1:0);
    vector<vector<int>> sum(n+1,vector<int>(n+1));
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]+v[i][j]-sum[i][j];
 
    while(q--){
        int y1,x1,y2,x2; cin>>y1>>x1>>y2>>x2; 
        int L=min(y1,y2)-1, R=max(y1,y2), LL=min(x1,x2)-1, RR=max(x1,x2);
        cout<<sum[R][RR]-sum[R][LL]-sum[L][RR]+sum[L][LL]<<endl;
    }
}
