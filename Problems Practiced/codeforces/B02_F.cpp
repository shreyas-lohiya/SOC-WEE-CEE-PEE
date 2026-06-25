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
    int n,t,k,queryout,ans; cin>>n>>t>>k;
    int a=1, b=n;
    while(b>a){
        int mid=(a+b)/2;
        cout<<"? 1 "<<mid<<endl; cin>>queryout; ans=mid-queryout;
        if(ans<k) a=mid+1;
        else b=mid;
    }
    cout<<"! "<<b<<endl;
}
