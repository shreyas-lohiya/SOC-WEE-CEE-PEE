#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int ii=1; ii<=t; ii++){
        int n; cin>>n; vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
        vector<int> nex(n); for(int i=0; i<n; i++) nex[i]=i+1;
        vector<int> prev(n); for(int i=0; i<n; i++) prev[i]=i-1;
        vector<pair<int,int>> ans;
        int start=0;
        for(int j=0; j<n-1; j++){
            int i=start;
            int mini=start; int r=j; int counter=0;
            while(i!=n){ 
                if(v[i]<v[mini]) {mini=i; r=j+counter;}
                i=nex[i]; counter++;
            }

            //cout<<start<<i<<" "<<mini<<" "<<r<<" "<<j<<" "<<counter<<endl;

            if(r==j) {start=nex[start]; continue;}
            ans.push_back({j+1,r+1});
            nex[prev[mini]]=nex[mini];
            if(nex[mini]!=n) prev[nex[mini]]=prev[mini];
        }
        
        cout<<ans.size()<<endl;
        for(int iii=0; iii<ans.size(); iii++){
            cout<<ans[iii].first<<" "<<ans[iii].second<<" "<<ans[iii].second-ans[iii].first<<endl;
        }
       
    }
}
