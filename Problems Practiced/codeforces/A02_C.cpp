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
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n; 
        vector<pair<int,int>> ab(n); for(auto &e:ab) cin>>e.first; for(auto &e:ab) cin>>e.second;
        sort(ab.rbegin(),ab.rend());
        vi ans;
        int sum=0,i=0,maxx=ab[i].first; ans.push_back(ab[i].first);
        for(; i<n; i++){
            if(ab[i].first!=maxx) {
                maxx=ab[i].first;
                ans.push_back(max(maxx,sum));
            }
            sum+=ab[i].second;
        }
        maxx=0;
        ans.push_back(max(maxx,sum));
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<endl;
        
        
    }
}
