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
        if (n%2==0) cout<<n/2<<" "<<n/2<<endl;
        else{
            int ans=n/2;
            int temp=ans; int ind=0;
            while(temp%10==9){
                temp/=10; ind++;
            }
            int diff=0;
            for(int i=0; i<ind; i++) diff*=10, diff+=5;
            ans-=diff;
            vi x(2); x[0]=ans+1; x[1]=ans; int p=1;
            int num=10;
            for(int i=0; i<ind; i++){
                x[p]+=num;
                num*=10;
                p=1-p;
            }
            cout<<x<<endl;
        }
    }
}
