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
    int n,x; cin>>n>>x;
    vector<int> p(n); cin>>p;
    sort(p.begin(),p.end());
    int i=0,j=n-1,ans=0;
    while(i<=j){
        if(p[j]+p[i]>x) ans++,j--;
        else ans++,i++,j--;
    }
    cout<<ans<<endl;
}
