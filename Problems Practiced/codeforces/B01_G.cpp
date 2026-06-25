#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; t=1;
    for(int ii=1; ii<=t; ii++){
        int n; cin>>n; vector<bool> isplus(2*n); vector<int> b(2*n); bool ans=1; vector<int> possans;
        for(int i=0; i<2*n; i++) {
            char c; cin>>c; isplus[i]=(c=='+');
            if (!isplus[i]) cin>>b[i];
        }
        set<int> revshowcase;
        for(int i=2*n-1; i>=0; i--){
            if (isplus[i]){
                if (revshowcase.empty()) {ans=0; break;}
                else {
                    int first=*revshowcase.begin();
                    possans.push_back(first);
                    revshowcase.erase(first);
                }
            }
            else{
                if (!revshowcase.empty() && b[i]>*revshowcase.begin()) {ans=0; break;}
                else revshowcase.insert(b[i]);
            }
        }
        if (ans==0) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=n-1; i>=0; i--){
                cout<<possans[i]<<" ";
            } cout<<endl;
        }
    }
}
