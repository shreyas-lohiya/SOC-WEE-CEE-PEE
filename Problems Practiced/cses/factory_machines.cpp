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
    int n,t; cin>>n>>t;
    vi k(n); cin>>k;
    int a=1,b=t**min_element(k.begin(), k.end());
    while(b>a){
        int mid=(a+b)/2;
        int sum=0;
        for(auto &e:k) sum+=mid/e;
        if(sum<t) a=mid+1;
        if(sum>=t) b=mid;
    }
    cout<<b<<endl;
}
