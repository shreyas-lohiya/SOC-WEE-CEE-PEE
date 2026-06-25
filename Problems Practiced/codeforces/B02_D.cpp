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
    int t=1; //cin>>t;
    while(t--){
        int n,sx,sy; cin>>n>>sx>>sy;
        int nor=0,sou=0,eas=0,wes=0;
        for(int i=0; i<n; i++){
            int x,y; cin>>x>>y;
            if (x>sx) eas++;
            else if (x<sx) wes++;
            if (y>sy) nor++;
            else if (y<sy) sou++;
        }
        int maxx=nor; 
        maxx=max(maxx,sou);
        maxx=max(maxx,eas);
        maxx=max(maxx,wes);
        cout<<maxx<<endl;
        if (maxx==nor) cout<<sx<<" "<<sy+1<<endl;
        else if (maxx==sou) cout<<sx<<" "<<sy-1<<endl;
        else if (maxx==eas) cout<<sx+1<<" "<<sy<<endl;
        else if (maxx==wes) cout<<sx-1<<" "<<sy<<endl;

    }
}
