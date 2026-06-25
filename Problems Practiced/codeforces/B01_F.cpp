#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int ii=1; ii<=t; ii++){
        int n; cin>>n; vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
        if (n==1) {cout<<"0"<<endl; continue;}
        int maxx=v[0];
        set<int> diff; for(int i=0; i<n-1; i++) {diff.insert(v[i+1]-v[i]); maxx=max(maxx,v[i+1]);}
        if (diff.size()>2) cout<<"-1"<<endl;
        else if (diff.size()==1 && *diff.begin()>=0) cout<<"0"<<endl;
        else if (diff.size()==1 && *diff.begin()<0) {int negc=-1*(*diff.begin());
            if(maxx>=negc){
                cout<<0<<endl;
            }
            else{
                cout<<-1<<endl;
            }}
        else if (diff.size()==2){
            int first=*diff.begin();
            int second=*next(diff.begin(), 1);
            if (first <0 && second>0 && (second-first)>maxx) cout<<(second-first)<<" "<<second<<endl;
            else cout<<-1<<endl;
        }
        
    }
}
