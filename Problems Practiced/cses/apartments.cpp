#include <bits/stdc++.h>
using namespace std;
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
int main(){
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n),b(m); cin>>a>>b;
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    int i=0,j=0,ans=0;
    while(j<m){
        if(i>=n) break;
        if(abs(a[i]-b[j])<=k) {ans++; i++; j++;}
        else if (b[j]>a[i]) i++;
        else j++;
    }
    cout<<ans<<endl;
}
